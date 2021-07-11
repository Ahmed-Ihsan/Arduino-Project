int LED1 = 12;
int buzzer = 10;
int smokeA0 = A5;
int sensorThreshold = 100;

int ledPin = 12;                
int pirPin = 2;                
int pirStat = 0; 
int sensor_ = 0;
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  pinMode(ledPin, OUTPUT);     
  pinMode(pirPin, INPUT); 
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()){
  sensor_ = Serial.read();
  }
  MQ_2(sensor_);
  PIR_SEN (sensor_);
}


void PIR_SEN (int sensor_){
  
   pirStat = digitalRead(pirPin);
 if (pirStat == HIGH) {            // if motion detected
   digitalWrite(ledPin, HIGH);  // turn LED ON
   if (sensor_){
     Serial.println("SomeOne Front The Door");
   }
 } 
 else {
   digitalWrite(ledPin, LOW); // turn LED OFF if we have no motion
   if (sensor_){
     Serial.println("no motion");
   }
 }
  delay(100);
 
}

void MQ_2(int sensor_){

  int analogSensor = analogRead(smokeA0);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThreshold)
  {
      digitalWrite(LED1, HIGH);
      if (sensor_){
        Serial.println("There Is Danger In The Kitchen");
      }
      digitalWrite(buzzer, LOW);
  }
  else
  {
    digitalWrite(LED1, LOW);
    if (sensor_){
        Serial.println("safety");
      }
    digitalWrite(buzzer, HIGH);
  }
  delay(100);
  
}
