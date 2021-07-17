#include <Servo.h>

const int motor1 = 9;
const int motor_1 = 6;
const int motor2 = 5;
const int motor_2 = 3;

int speed_ = 100;
int duration ;
int distance ;
int B = 0;
int A = 0;
char Incoming_value ;
#define echoPin A2
#define trigPin A1

Servo servo_motor;

void setup() {
  Serial.begin(9600);
  // declare the ledPin as an OUTPUT:
  pinMode(motor1, OUTPUT);
  pinMode(motor_1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor_2, OUTPUT);
  servo_motor.attach(10);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  
  if (Serial.available() > 0) {
    Incoming_value = Serial.read();
    Serial.println(Incoming_value);
  }
  
  if (Incoming_value == 'B' || B ) {
    B = 1;
    A = 0;
    speed_ = 255 ;
    bletooth(Incoming_value);
  }

  if (Incoming_value == 'A' || A ) {
    speed_ = 100 ;
    auto_drive();
    B = 0;
    A = 1;
  }

  
}
void auto_drive() {

}

void bletooth(char read_) {
  if (read_ == 'F') {
    forword();
  } else if (read_ == 'X') {
    backword();
  } else if (read_ == 'R') {
    right();
    forword();
  } else if (read_ == 'L') {
    left();
    forword();
  } else {
    stop_LR();
    stop_FB();
  }

}

int chack_L() {
  servo_motor.write(150);
  delay(200);
  chack();
  return distance ;
}

int chack_F() {
  servo_motor.write(98);
  delay(200);
  chack();
  return distance ;
}

int chack_R() {
  servo_motor.write(42);
  delay(200);
  chack();
  return distance ;
}

void chack() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
}

void forword() {
  analogWrite(motor2, speed_);
  analogWrite(motor_2, LOW);
}

void backword() {
  analogWrite(motor2, LOW);
  analogWrite(motor_2, speed_);
}

void right() {
  digitalWrite(motor1, HIGH);
  digitalWrite(motor_1, LOW);
}

void left() {
  digitalWrite(motor1, LOW);
  digitalWrite(motor_1, HIGH);
}

void stop_FB() {
  analogWrite(motor2, LOW);
  analogWrite(motor_2, LOW);
}

void stop_LR() {
  digitalWrite(motor1, LOW);
  digitalWrite(motor_1, LOW);
}
