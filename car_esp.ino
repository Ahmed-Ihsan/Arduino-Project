int motor1Pin1 = 27; 
int motor1Pin2 = 26; 

int motor1Pin_1 = 32; 
int motor1Pin_2 = 33; 

int enable1Pin1 = 14;
int enable1Pin2 = 25; 

// Setting PWM properties
const int freq = 30000;
const int pwmChannel0 = 0;
const int pwmChannel1 = 1;

const int resolution = 8;
int dutyCycle = 200;

void setup() {
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin1, OUTPUT);

  pinMode(motor1Pin_1, OUTPUT);
  pinMode(motor1Pin_2, OUTPUT);
  pinMode(enable1Pin2, OUTPUT);
 
  ledcSetup(pwmChannel0, freq, resolution);
  ledcSetup(pwmChannel1, freq, resolution);
  
  ledcAttachPin(enable1Pin1, pwmChannel0);
  ledcAttachPin(enable1Pin2, pwmChannel1);

  ledcWrite(pwmChannel0, dutyCycle);
  ledcWrite(pwmChannel1, dutyCycle);
  Serial.begin(115200);
  Serial.print("Testing DC Motor...");
}

void loop() {
  left();
}

void forword() {
  digitalWrite(motor1Pin_1, HIGH);
  digitalWrite(motor1Pin_2, LOW); 
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  
}

void backword() { 
  digitalWrite(motor1Pin_1, LOW);
  digitalWrite(motor1Pin_2, HIGH); 
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
}

void right() {
  digitalWrite(motor1Pin_1, HIGH);
  digitalWrite(motor1Pin_2, LOW); 
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
}

void left() {
  Serial.println("Moving Forward");
  digitalWrite(motor1Pin_1, LOW);
  digitalWrite(motor1Pin_2, HIGH); 
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH); 
}

void Break() {
  digitalWrite(motor1Pin_1, LOW);
  digitalWrite(motor1Pin_2, LOW); 
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW); 
}
