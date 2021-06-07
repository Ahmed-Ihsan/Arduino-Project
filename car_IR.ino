int sensorPin_0 = A0;
int sensorPin_1 = A1;
int sensorPin_2 = A2;
int sensorPin_3= A3;
int sensorPin_4 = A4;
const int motor1 = 11;   
const int motor_1 = 10;
const int motor2 = 9;
const int motor_2 = 6;

int ledPin = 13;      // select the pin for the LED

const int speed_=150;
const int speed_2=150;

int sensorValue_3 ;
int sensorValue_1;

void setup() {
  Serial.begin(9600);
  // declare the ledPin as an OUTPUT:
  pinMode(motor1, OUTPUT);
  pinMode(motor_1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor_2, OUTPUT);
}

void loop() {
  /* read the value from the sensor:
 int sensorValue_0 = analogRead(sensorPin_0);
 int sensorValue_1 = analogRead(sensorPin_1);
 int sensorValue_2 = analogRead(sensorPin_2);
 int sensorValue_3 = analogRead(sensorPin_3);
 int sensorValue_4 = analogRead(sensorPin_4);
 
  Serial.print("A0 :");
  Serial.println(sensorValue_0);
  Serial.print("A1 :");
  Serial.println(sensorValue_1);
  Serial.print("A2 :");
  Serial.println(sensorValue_2);
  Serial.print("A3 :");
  Serial.println(sensorValue_3);
  Serial.print("A4 :");
  Serial.println(sensorValue_4);
  delay(1000); */
   

sensorValue_1 = analogRead(sensorPin_1);
sensorValue_3 = analogRead(sensorPin_3);

if(sensorValue_1 > 500 && sensorValue_3 < 500)
{
  Serial.println("turning right");
  right();
  }
  
if(sensorValue_1 < 500 && sensorValue_3 > 500)
{
  Serial.println("turning left");
  left();
  }

if(sensorValue_1 > 500 && sensorValue_3 > 500)
{
  Serial.println("going forward");
  forword();
  }

if(sensorValue_1 < 500 && sensorValue_3 < 500)
{ 
  Serial.println("going forward");
  stop_();
  }
}

void forword(){
  analogWrite(motor1,LOW);
  analogWrite(motor_1,speed_);
  analogWrite(motor2,speed_);
  analogWrite(motor_2,LOW);
}
void left(){
  analogWrite(motor1,LOW);
  analogWrite(motor_1,speed_);
  analogWrite(motor2,LOW);
  analogWrite(motor_2,speed_);  
}

void right(){
  analogWrite(motor1,speed_);
  analogWrite(motor_1,LOW);
  analogWrite(motor2,speed_);
  analogWrite(motor_2,LOW);  
}

void stop_(){
  analogWrite(motor1,LOW);
  analogWrite(motor_1,LOW);
  analogWrite(motor2,LOW);
  analogWrite(motor_2,LOW);  
}
