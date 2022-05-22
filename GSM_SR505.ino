[code]
#include <SoftwareSerial.h>

#define SIGNAL_PIN 2
#define pzr 5
//Create software serial object to communicate with SIM800L
SoftwareSerial mySerial(4, 3); //SIM800L Tx & Rx is connected to Arduino #4 & #3

void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  pinMode(SIGNAL_PIN, INPUT);
  pinMode(pzr, OUTPUT);
  //Begin serial communication with Arduino and SIM800L
  mySerial.begin(9600);
  Serial.println("Initializing..."); 
  delay(1000);
}

void loop()
{
anmtion();
}

void anmtion(){
  int x = 2000 ;
  int t = digitalRead(SIGNAL_PIN) ;
  if(t == HIGH) {
      for(int i=0 ; i<10 ; i++ ){
        x/= 1.5 ;
        digitalWrite(pzr, HIGH);
        delay(x);
        digitalWrite(pzr, LOW);
        delay(x);
      }
      digitalWrite(pzr,HIGH);
      delay(1000);
      digitalWrite(pzr, LOW);
      delay(1000);
      x=2000;
      call(); 
    }
  }


void sendSMS(char *sms){
  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CMGS=\"+9647516274515\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  mySerial.print(sms); //text content
  updateSerial();
  mySerial.write(26);
}

void call(){
  mySerial.println("AT"); //Once the handshake test is successful, i t will back to OK
  updateSerial();
  
  mySerial.println("ATD+ +9647516274515;"); //  change ZZ with country code and xxxxxxxxxxx with phone number to dial
  updateSerial();
  delay(20000); // wait for 20 seconds...
  mySerial.println("ATH"); 
  updateSerial();
}

void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}

void delay_timer(int j , int n , int range){
  for(int ii=0;ii<range ;ii+= n){
    delay(j);
  }
}
