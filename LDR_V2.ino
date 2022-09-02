#include <Servo.h>
Servo myservo_1;
Servo myservo_2;

int farkNS;
int farkEW;

int degNS;
int degEW;

int ldrN; //شمال  
int ldrW;   //غرب
int ldrS;  //جنوب 
int ldrE;   //شرق

int ldr1;
int ldr2;
int ldr3;
int ldr4;

void setup() {
  myservo_1.attach(9);  //pin 9
  myservo_2.attach(10); //pin 10
  Serial.begin(9600);

   delay(500);
   
    degNS=90;
    degEW=90;
    myservo_1.write(degNS); // 90 <-> 160
    myservo_2.write(degEW); // 90 <-> 160
}

void loop() {
  ldr1=analogRead(A0);
  ldr2=analogRead(A1);
  ldr3=analogRead(A2);
  ldr4=analogRead(A3);
  
  ldrN = ldr1 + ldr2;
  ldrW = ldr1 + ldr3;
  ldrE = ldr2 + ldr4;
  ldrS = ldr3 + ldr4;
  
  Serial.print("ldrN:");
  Serial.print(ldrN);
  Serial.print("    ldrW:");
  Serial.print(ldrW);
  Serial.print("    ldrS:");
  Serial.print(ldrS);
  Serial.print("    ldrE:");
  Serial.print(ldrE);
  
  Serial.print("    degEW = ");
  Serial.print(degEW);
  Serial.print("    degNS = ");
  Serial.println(degNS);
  delay(100);
 
top(ldrS ,ldrN);
down(ldrN,ldrS);
right(ldrE,ldrW);  
left(ldrW,ldrE);  

}

void top(int ldr_1,int ldr_2){
if (ldr_1>ldr_2)  
  {
     farkNS=ldr_1-ldr_2;
     if (farkNS>5)
     {
        if(degNS > 93){
          degNS--;
          myservo_1.write(degNS);
        }
      }
   }
}

void down(int ldr_1,int ldr_2){
if (ldr_1>ldr_2)  
  {
     farkNS=ldr_1-ldr_2;
     if (farkNS>5)
     {
        if(degNS < 160){
          degNS++;
          myservo_1.write(degNS);
        }
      }
   }
}

void right(int ldr_1,int ldr_2){
if (ldr_1>ldr_2)  
  {
     farkNS=ldr_1-ldr_2;
     if (farkNS>5)
     {
        if(degNS > 10){
          degEW--;
          myservo_2.write(degEW);
        }
      }
   }
}

void left(int ldr1,int ldr2){
if (ldr_1>ldr_2)  
  {
     farkNS=ldr_1-ldr_2;
     if (farkNS>5)
     {
        if(degNS > 10){
          degEW++;
          myservo_2.write(degEW);
        }
      }
   }
}
