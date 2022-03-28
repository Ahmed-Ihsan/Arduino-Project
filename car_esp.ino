/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

// Motor A
const int motor1 = 36;
const int motor_1 = 39;
const int motor2 = 34;
const int motor_2 = 35;
const int speed_pin1 = 32;
const int speed_pin2 = 33;

// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 100;

void setup() {
  // sets the pins as outputs:
  pinMode(motor1, OUTPUT);
  pinMode(motor_1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor_2, OUTPUT);
  
  // configure LED PWM functionalitites
  ledcSetup(pwmChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(speed_pin1, pwmChannel);
  ledcAttachPin(speed_pin2, pwmChannel);
 
  ledcWrite(pwmChannel, dutyCycle);
  
  Serial.begin(115200);

  // testing
  Serial.print("Testing DC Motor...");
}

void loop() {
  
forword();
}

void left() {
  digitalWrite(motor2, HIGH);
  digitalWrite(motor_2, LOW);
  digitalWrite(motor1, HIGH);
  digitalWrite(motor_1, LOW);
}

void right() {
  digitalWrite(motor2, LOW);
  digitalWrite(motor_2, HIGH);
  digitalWrite(motor1, LOW);
  digitalWrite(motor_1, HIGH);
}

void backword() {
  digitalWrite(motor1, HIGH);
  digitalWrite(motor_1, LOW);
  digitalWrite(motor2, LOW);
  digitalWrite(motor_2, HIGH);
}

void forword() {
  digitalWrite(motor1, LOW);
  digitalWrite(motor_1, HIGH);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor_2, LOW);
}

void Break() {
  digitalWrite(motor2, HIGH);
  digitalWrite(motor_2, HIGH);
  digitalWrite(motor1, HIGH);
  digitalWrite(motor_1, HIGH);
}