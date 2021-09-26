int PWM_1 = 3;
int INA_1 = 2;
int INB_1 = 4;
int EN_1 = A0;

int PWM_2 = 6;
int INA_2 = 7;
int INB_2 = 8;
int EN_2 = A1;

int get_ = 0 ;

void setup() {
  Serial.begin(9600);
  pinMode(PWM_1,OUTPUT);
  pinMode(INA_1,OUTPUT);
  pinMode(INB_1,OUTPUT);
  pinMode(EN_1,OUTPUT);

  pinMode(PWM_2,OUTPUT);
  pinMode(INA_2,OUTPUT);
  pinMode(INB_2,OUTPUT);
  pinMode(EN_2,OUTPUT);
  
}
 void motor(int PWM ,int INA,int INB,int EN,int R,int speed_){
  if (R == 1){
    digitalWrite(INA,HIGH);
    digitalWrite(INB,LOW);
    }else if (R == -1){
      digitalWrite(INA,LOW);
      digitalWrite(INB,HIGH);
    }else{
      digitalWrite(INA,LOW);
      digitalWrite(INB,LOW);
    }

    int pot;
    int out1;
    
    digitalWrite(EN,HIGH);
    out1=map(speed_,0,1023,0,255);
    analogWrite(PWM,out1); 
}

void loop() {
  if (Serial.available() > 0){ 
    get_ = Serial.read();
    Serial.println(get_);
    if(get_ == 119){
      motor(PWM_1,INA_1,INB_1,EN_1,1,1023);
      motor(PWM_2,INA_2,INB_2,EN_2,1,1023);
    }else if(get_ == 115){
      motor(PWM_1,INA_1,INB_1,EN_1,-1,1023);
      motor(PWM_2,INA_2,INB_2,EN_2,-1,1023);
    }else if(get_ == 100){
      motor(PWM_1,INA_1,INB_1,EN_1,1,1023);
      motor(PWM_2,INA_2,INB_2,EN_2,-1,1023);
    }else if(get_ == 97){
      motor(PWM_1,INA_1,INB_1,EN_1,-1,1023);
      motor(PWM_2,INA_2,INB_2,EN_2,1,1023);
    }else{
      motor(PWM_1,INA_1,INB_1,EN_1,0,1023);
      motor(PWM_2,INA_2,INB_2,EN_2,0,1023);
    }
  }

}
