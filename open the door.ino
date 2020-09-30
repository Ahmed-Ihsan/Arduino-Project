#include <Servo.h>
Servo servo;
const int trigPin_1 = 11; // pin 11
const int echoPin_1 = 10; // pin 10
const int LED = 12; // pin 12
int n = 100 ; //time = n x 100Ms
int n1 = n;
int m = 100 ; // distance 

void setup() {
  pinMode(trigPin_1, OUTPUT);
  pinMode(echoPin_1, INPUT);
  pinMode(LED, OUTPUT);
} long duration_1, distance_1;

void loop() {
  sensor_sound_1(); // sensor on
  digitalWrite(LED, LOW); // LED OFF
  if (distance_1 < m) {
    digitalWrite(LED, HIGH);  // LED ON
    for (int i = 0; i < n1 ; n1--) { 
      // timer >= 10s
      sensor_sound_1();
      delay(100);
      if (distance_1 < m) {
        n1 = n; 
      }
    }
    n1=n; 
    digitalWrite(LED,LOW); 
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
