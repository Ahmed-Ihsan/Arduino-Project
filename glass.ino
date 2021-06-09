
const int trigPin_1 = 11; // pin 11
const int echoPin_1 = 10; // pin 10
const int trigPin_2 = 9; // pin 9
const int echoPin_2 = 6; // pin 6
const int trigPin_3 = 5; // pin 5
const int echoPin_3 = 3; // pin 3

const int sond_1 = 8;
const int sond_2 = 7;


long distance_1,duration_1;
long distance_2,duration_2;
long distance_3,duration_3;

void setup() { 
  Serial.begin(9600);
  pinMode(trigPin_1, OUTPUT);
  pinMode(echoPin_1, INPUT);
  pinMode(trigPin_2, OUTPUT);
  pinMode(echoPin_2, INPUT);
  pinMode(trigPin_3, OUTPUT);
  pinMode(echoPin_3, INPUT); 

  pinMode(sond_1, OUTPUT);
  pinMode(sond_2, OUTPUT);
}

void loop() {
  sensor_sound_1();
  
  Serial.println("sensor_sound_1");
  Serial.println(distance_1);
  
  if (distance_1 < 30) { 
    digitalWrite(sond_1,HIGH);
    digitalWrite(sond_2,HIGH);       
  }else if(distance_1 > 30 && distance_2 > 30 && distance_3 > 30){
    digitalWrite(sond_1,LOW);
    digitalWrite(sond_2,LOW); 
    }
  sensor_sound_2();
  Serial.println("sensor_sound_2");
  Serial.println(distance_2);
  if (distance_2 < 30 ) { 
    digitalWrite(sond_1,LOW);
    digitalWrite(sond_2,HIGH);       
  }else if(distance_1 > 30 && distance_2 > 30 && distance_3 > 30){
    digitalWrite(sond_1,LOW);
    digitalWrite(sond_2,LOW); 
    }
  sensor_sound_3();
  Serial.println("sensor_sound_3");
  Serial.println(distance_3);
  if (distance_3 < 30) { 
    digitalWrite(sond_1,HIGH);
    digitalWrite(sond_2,LOW);       
  }else if(distance_1 > 30 && distance_2 > 30 && distance_3 > 30) {
    digitalWrite(sond_1,LOW);
    digitalWrite(sond_2,LOW); 
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

void sensor_sound_2() {
  digitalWrite(trigPin_2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_2, LOW);
  duration_2 = pulseIn(echoPin_2, HIGH);
  distance_2 = duration_2 / 58.2;
}

void sensor_sound_3() {
  digitalWrite(trigPin_3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_3, LOW);
  duration_3 = pulseIn(echoPin_3, HIGH);
  distance_3 = duration_3 / 58.2;

}
