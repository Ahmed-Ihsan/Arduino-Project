const int motor1 = 11;
const int motor_1 = 10;
const int motor2 = 7;
const int motor_2 = 6;

char Incoming_value ; 
void setup() {
  Serial.begin(9600);
  pinMode(motor1, OUTPUT);
  pinMode(motor_1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor_2, OUTPUT);
}

void loop() {
  
  if (Serial.available() > 0) {
    Incoming_value = Serial.read();
  }
    bletooth(Incoming_value);
    Serial.println(Incoming_value);
}

void bletooth(char read_) {
  if (read_ == 'F') {
    forword();
  } else if (read_ == 'B') {
    backword();
  } else if (read_ == 'R') {
    right();
  } else if (read_ == 'L') {
    left();
  }else {
    Break();
  }
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
