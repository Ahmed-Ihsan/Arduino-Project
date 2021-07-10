int LED1 = 12;
int buzzer = 10;
int smokeA0 = A5;
int sensorThreshold = 400;
int relay = 3;
int ledPin = 13;                
int pirPin = 2;                
int pirStat = 0; 

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  pinMode(ledPin, OUTPUT);     
    pinMode(pirPin, INPUT); 
  Serial.begin(9600);
}

void loop() {
  MQ_2();
  PIR_SEN ();
}


void PIR_SEN (){
  
   pirStat = digitalRead(pirPin); 
 if (pirStat == HIGH) {            // if motion detected
   digitalWrite(ledPin, HIGH);  // turn LED ON
   Serial.println("SomeOne Front The Door");
 } 
 else {
   digitalWrite(ledPin, LOW); // turn LED OFF if we have no motion
 }
 
}

void MQ_2(){

  int analogSensor = analogRead(smokeA0);

  // Checks if it has reached the threshold value
  if (analogSensor > sensorThreshold)
  {
    digitalWrite(LED1, HIGH);
     Serial.println("There Is Danger In The Kitchen");
    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(LED1, LOW);
    Serial.println("safety");
    noTone(buzzer);
  }
  delay(100);
  
}
