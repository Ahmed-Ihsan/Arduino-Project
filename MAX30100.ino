//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "MAX30100_PulseOximeter.h"

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
#define REPORTING_PERIOD_MS     1000
PulseOximeter pox;
uint32_t tsLastReport = 0;

void onBeatDetected()
{
     lcd.print("Beat!");
}

 
void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Initializing pulse oximeter..");
  if (!pox.begin()) {
        lcd.print("FAILED");
        for(;;);
    } else {
        lcd.print("SUCCESS");
    }
     pox.setIRLedCurrent(MAX30100_LED_CURR_33_8MA);
     pox.setOnBeatDetectedCallback(onBeatDetected);
}


void loop()
{
  pox.update();
   if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("HR: ");
        lcd.print(pox.getHeartRate());
        lcd.print(" bpm");
        lcd.setCursor(0,1);
        lcd.print("SpO2: ");
        lcd.print(pox.getSpO2());
        lcd.print("%");
        
        tsLastReport = millis();
    }
}
