    /*
  VNH2SP30-full-bridge-Driver
  made on 01 Nov 2020
  by Amir Mohammad Shojaee @ Electropeak
  https://electropeak.com/learn/

*/

#define PWM 5
#define INA 7
#define INB 8

#define EN A0

int pot;
int out1;

void setup() {
  Serial.begin(9600);
  pinMode(PWM,OUTPUT);
  pinMode(INA,OUTPUT);
  pinMode(INB,OUTPUT);
  pinMode(EN,OUTPUT);
}
 
void loop() {
  
  digitalWrite(INA,HIGH); //Motor A Rotate Clockwise
  digitalWrite(INB,LOW);
  digitalWrite(EN,HIGH);
  
  pot=analogRead(A5);
  out1=map(pot,0,1023,0,255);
  analogWrite(PWM,out1); //Speed control of Motor 
}
