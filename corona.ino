#include <Servo.h>
Servo servo;
const int trigPin_1 = 11;
const int echoPin_1 = 10;
const int relay = 12;

void setup() {
  pinMode(trigPin_1, OUTPUT);
  pinMode(echoPin_1, INPUT);
  pinMode(relay,OUTPUT);
} long duration_1, distance_1;

void loop() {
  sensor_sound_1();
  digitalWrite(relay,HIGH);
  if (distance_1 < 50){
    digitalWrite(relay,LOW);
    for(int i=0; i<10 ;i++){
      delay(1000);
    }
    digitalWrite(relay,HIGH);
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
