#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN D4
#define DHTTYPE    DHT11

DHT dht(DHTPIN, DHTTYPE);

int lcdColumns = 16;
int lcdRows = 2;
int smokeA0 = A0;
int sensorThres = 600;
int buzzer = D3;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void setup(){
  lcd.init();                     
  lcd.backlight();
  pinMode(smokeA0, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop(){
  int analogSensor = analogRead(smokeA0);
  float newT = dht.readTemperature();
  float newH = dht.readHumidity();

  lcd.setCursor(0, 0);
  lcd.print("MQ : ");
  lcd.print(analogSensor);
  lcd.setCursor(0, 1);
  lcd.print("T: ");
  lcd.print(newT);
  lcd.print(" -- ");
  lcd.print("H: ");
  lcd.print(newH);

  delay(1000);
  lcd.clear(); 
  if (analogSensor > sensorThres)
 {
   tone(buzzer, 1000, 200);
 }
 else
 {
   noTone(buzzer);
 }
}
