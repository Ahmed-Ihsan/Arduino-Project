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

void setup() {
  myservo_1.attach(9);  // 90 <-> 160
  myservo_2.attach(10);
  Serial.begin(9600);

   delay(500);
   
    degNS=90;
    degEW=90;
    myservo_1.write(degNS);
    myservo_2.write(degEW);
}

void loop() {
  ldrN=analogRead(A0);
  ldrW=analogRead(A1);
  ldrS=analogRead(A2);
  ldrE=analogRead(A3);
  
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
 
top(ldrS ,ldrW);
top(ldrN ,ldrE);
down(ldrW,ldrS);
down(ldrE,ldrN);

right(ldrW,ldrE);
right(ldrS,ldrN);  
left(ldrE,ldrW);  
left(ldrN,ldrS);

}

void top(int ldr1,int ldr2){
if (ldr1>ldr2)  
  {
     farkNS=ldr1-ldr2;
     if (farkNS>5)
     {
        if(degNS > 93){
          degNS--;
          myservo_1.write(degNS);
        }
      }
   }
}

void down(int ldr1,int ldr2){
if (ldr1>ldr2)  
  {
     farkNS=ldr1-ldr2;
     if (farkNS>5)
     {
        if(degNS < 160){
          degNS++;
          myservo_1.write(degNS);
        }
      }
   }
}

void right(int ldr1,int ldr2){
if (ldr1>ldr2)  
  {
     farkNS=ldr1-ldr2;
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
if (ldr1>ldr2)  
  {
     farkNS=ldr1-ldr2;
     if (farkNS>5)
     {
        if(degNS > 10){
          degEW++;
          myservo_2.write(degEW);
        }
      }
   }
}
