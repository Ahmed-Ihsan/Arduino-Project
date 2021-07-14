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
  { 255,16,0,0,0,163,0,11,13,1,
  2,0,37,19,22,11,2,26,31,31,
  79,78,0,79,70,70,0,2,0,37,
  34,22,11,2,26,31,31,79,78,0,
  79,70,70,0,2,0,37,49,22,11,
  2,26,31,31,79,78,0,79,70,70,
  0,2,0,37,64,22,11,2,26,31,
  31,79,78,0,79,70,70,0,2,0,
  37,79,22,11,2,26,31,31,79,78,
  0,79,70,70,0,7,36,3,6,58,
  8,2,26,2,11,129,0,1,22,18,
  6,17,76,97,98,101,108,0,129,0,
  1,37,18,6,17,76,97,98,101,108,
  0,129,0,1,53,18,6,17,76,97,
  98,101,108,0,129,0,1,67,18,6,
  17,76,97,98,101,108,0,129,0,1,
  81,18,6,17,76,97,98,101,108,0 };
  
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
