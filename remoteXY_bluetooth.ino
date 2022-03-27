/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.8 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.11.1 or later version;
     - for iOS 1.9.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL_RX 2
#define REMOTEXY_SERIAL_TX 3
#define REMOTEXY_SERIAL_SPEED 9600


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 94 bytes
  { 255,11,0,0,0,87,0,16,24,1,7,36,0,0,63,9,16,16,36,11,
  129,0,5,17,53,5,137,69,110,116,101,114,32,110,117,109,98,101,114,32,
  111,114,32,110,97,109,101,0,129,0,12,31,18,6,1,49,46,32,65,104,
  109,101,100,0,129,0,12,40,18,6,1,50,46,32,65,108,105,0,129,0,
  12,49,18,6,1,51,46,32,73,104,115,97,110,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  char input_1[11];  // string UTF8 end zero  

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////



void setup() 
{
  RemoteXY_Init (); 
  
  Serial.begin(9600);
}

void loop() 
{ 
  RemoteXY_Handler ();


  if ( (strcmp (RemoteXY.input_1, "ahmed")==0) || (strcmp (RemoteXY.input_1, "1")==0) ) {
      Serial.println(RemoteXY.input_1);
      RemoteXY.input_1[1] = '-';
    }


    if ( (strcmp (RemoteXY.input_1, "ali")==0) || (strcmp (RemoteXY.input_1, "2")==0) ) {
      Serial.println(RemoteXY.input_1);
      RemoteXY.input_1[1] = '-';
    }


    if ( (strcmp (RemoteXY.input_1, "ihsan")==0) || (strcmp (RemoteXY.input_1, "3")==0) ) {
      Serial.println(RemoteXY.input_1);
      RemoteXY.input_1[1] = '-';
    }


}
