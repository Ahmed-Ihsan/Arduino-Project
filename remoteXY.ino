/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.6 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.7.12 or later version;
     - for iOS 1.4.7 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266_HARDSERIAL_POINT

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200
#define REMOTEXY_WIFI_SSID "haider"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,16,0,0,0,181,0,11,13,1,
  2,0,37,30,22,11,2,26,31,31,
  79,78,0,79,70,70,0,2,0,37,
  43,22,11,2,26,31,31,79,78,0,
  79,70,70,0,2,0,37,56,22,11,
  2,26,31,31,79,78,0,79,70,70,
  0,2,0,37,69,22,11,2,26,31,
  31,79,78,0,79,70,70,0,2,0,
  37,82,22,11,2,26,31,31,79,78,
  0,79,70,70,0,7,36,2,14,58,
  8,2,26,2,11,129,0,4,33,18,
  6,17,84,86,0,129,0,4,46,18,
  6,17,70,97,110,0,129,0,4,59,
  18,6,17,76,105,103,104,116,105,110,
  103,0,129,0,4,72,18,6,17,99,
  111,111,108,105,110,103,0,129,0,4,
  84,18,6,17,82,101,102,114,105,103,
  101,0,129,0,17,5,27,6,17,68,
  111,111,114,32,75,101,121,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 
  uint8_t switch_2; // =1 if switch ON and =0 if OFF 
  uint8_t switch_3; // =1 if switch ON and =0 if OFF 
  uint8_t switch_4; // =1 if switch ON and =0 if OFF 
  uint8_t switch_5; // =1 if switch ON and =0 if OFF 
  char edit_1[11];  // string UTF8 end zero  

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_SWITCH_1 2
#define PIN_SWITCH_2 3
#define PIN_SWITCH_3 4
#define PIN_SWITCH_4 5
#define PIN_SWITCH_5 6


void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_SWITCH_1, OUTPUT);
  pinMode (PIN_SWITCH_2, OUTPUT);
  pinMode (PIN_SWITCH_3, OUTPUT);
  pinMode (PIN_SWITCH_4, OUTPUT);
  pinMode (PIN_SWITCH_5, OUTPUT);
  pinMode (7, OUTPUT);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_2, (RemoteXY.switch_2==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_3, (RemoteXY.switch_3==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_4, (RemoteXY.switch_4==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_5, (RemoteXY.switch_5==0)?LOW:HIGH);
  
  if (strcmp (RemoteXY.edit_1, "kkkk")==0) {
    digitalWrite(7,HIGH);
  }

  if (strcmp (RemoteXY.edit_1, "hhhh")==0) {
    digitalWrite(7,LOW);
  }


}
