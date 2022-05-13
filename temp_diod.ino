#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4); 

const int in = A0;          
const int t0 = 20.3;
const float vf0 = 573.44;
int i;
float dtemp, dtemp_avg, t;

void setup() {
  Serial.begin(9600);
  pinMode(in, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
}

void loop() {
dtemp_avg = 0;
for(i=0;i<1024;i++) {
float vf = analogRead(A0) * (4976.30 / 1023.000);
    dtemp = (vf - vf0) * 0.4545454;
    dtemp_avg = dtemp_avg + dtemp;
  }
t = t0 - dtemp_avg / 1024;
  Serial.print("temperature in Celcius degree)   = " );
  Serial.println(t);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("temp in Celcius");
  lcd.setCursor(0,1);
  lcd.print("degree = " );
  lcd.print(t);
  lcd.print("C%" );
  
  delay (1000);
}
