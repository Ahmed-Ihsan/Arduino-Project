#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
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
int fi = D5;

char auth[] = "Usg7C01eJO60JVSsggl5yEJ_CDbq3Xz3";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "TP-Link_6C72";
char pass[] = "56759860";
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void setup()
{
  Serial.begin(115200);
  pinMode(D3,OUTPUT);
  lcd.init();                     
  lcd.backlight();
  pinMode(smokeA0, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(fi, INPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
 
  int analogSensor = analogRead(smokeA0);
  int fier = digitalRead(fi);
  float newT = dht.readTemperature();
  float newH = dht.readHumidity();
  lcd.setCursor(0, 0);
  lcd.print("MQ : ");
  lcd.print(analogSensor);
  if(fier){
    lcd.print(" -- fier");
  }
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
