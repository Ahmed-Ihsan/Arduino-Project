#include <BH1750.h>
#include <Wire.h>

BH1750 lightMeter;
int val;
int tempPin = 1;

void setup() {
  Serial.begin(9600);

  Wire.begin();
  lightMeter.begin();

  Serial.println(F("BH1750 Test begin"));
}

void loop() {
  gy_30();
  lm_35();
}

void lm_35(){
  val = analogRead(tempPin);
  float mv = ( val/1024.0)*5000;
  float cel = mv/10;
  float farh = (cel*9)/5 + 32;
  Serial.print("TEMPRATURE = ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println();
  delay(1000);
}

void gy_30(){
  float lux = lightMeter.readLightLevel();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  delay(1000);
}
