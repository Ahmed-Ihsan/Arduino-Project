#include <Servo.h>

//Servo Tanımları
Servo myServoEW;
Servo myServoNS;

//Değişken Tanımları
int farkNS;
int farkEW;

//Servo Motor Derece Değişkenleri
int degNS;
int degEW;

//LDRlerin ışık değerleri
int ldrN;
int ldrW;
int ldrS;
int ldrE;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  //Servo motorları bağla
  myServoNS.attach(5);
  myServoEW.attach(4);
  delay(500);
  
//Başlangıç pozisyonu al  
  degNS=90;
  degEW=90;
  myServoNS.write(degNS);
  myServoEW.write(degEW);
  
}

void loop() {
  //LDR leri oku
  ldrN=analogRead(A0);
  ldrW=analogRead(A1);
  ldrS=analogRead(A2);
  ldrE=analogRead(A3);
  
  //Bildirim yap
  Serial.print("ldrN:");
  Serial.print(ldrN);
  Serial.print("    ldrW:");
  Serial.print(ldrW);
  Serial.print("    ldrS:");
  Serial.print(ldrS);
  Serial.print("    ldrE:");
  Serial.print(ldrE);
  //Bulunan açı değerlerini yazdır
  Serial.print("    degEW");
  Serial.print(degEW);
  Serial.print("    degNS");
  Serial.println(degNS);
  
  delay(100);
  
  /* Ldrlerin ışık değerlerini karşılaştırarak 
  yeniden pozisyon almak için karşılaştırma yap*/
  
  if (ldrN>ldrS)  //ldrN değeri ldrS değerinden büyükse
  {
   farkNS=ldrN-ldrS;
   if (farkNS>5)
   {
      degNS++;
      myServoNS.write(degNS);
      
    }
   }
  if (ldrS>ldrN)  //ldrN değeri ldrS değerinden büyükse
  {
   farkNS=ldrS-ldrN;
   if (farkNS>5)
   {
      degNS--;
      myServoNS.write(degNS);
      
    }
   }
   
  /* Ldrlerin ışık değerlerini karşılaştırarak 
  yeniden pozisyon almak için karşılaştırma yap*/
  
  if (ldrW>ldrE)  //ldrW değeri ldrE değerinden büyükse
  {
   farkEW=ldrW-ldrE;
   if (farkEW>5)
   {
      degEW++;
      myServoEW.write(degEW);
      
    }
   }
  if (ldrE>ldrW)  //ldrE değeri ldrW değerinden büyükse
  {
   farkEW=ldrE-ldrW;
   if (farkEW>5)
   {
      degEW--;
      myServoEW.write(degEW);
      
    }
   }
}
