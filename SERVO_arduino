#include <Servo.h>

Servo myservo;  // create servo object to control a servo

const int trigPin_1 = 11; // pin 11
const int echoPin_1 = 10; // pin 10

long distance_1,duration_1;

void setup() {
  pinMode(trigPin_1, OUTPUT);
  pinMode(echoPin_1, INPUT);
  myservo.attach(9);  
}

void loop() {
  sensor_sound_1();
  delay(100);
 if (distance_1 < 20) { 
    myservo.write(170);              
    delay(100);                       
  }
 else {
     myservo.write(10);
     delay(100); 
    }
        
}

void sensor_sound_1() {
  digitalWrite(trigPin_1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_1, LOW);
  duration_1 = pulseIn(echoPin_1, HIGH);
  distance_1 = duration_1 / 58.2;
}
