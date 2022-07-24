const int soler_power = D3 ;
const int tower = D2;
const int wind = A0 ;
const int relay = D4;
const int battery1 = D1;
const int battery2 = D0;
int counter_off_wind = 0;

void setup() {
  Serial.begin(9600);
  pinMode(wind, INPUT);
  pinMode(soler_power, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(tower, OUTPUT);
  pinMode(battery1, OUTPUT);
  pinMode(battery2, OUTPUT);
}

void loop() {
  case1();
  delay(5000);
  case2();
  delay(5000);
  case3();
  delay(5000);
}


void case1(){
  digitalWrite(tower,HIGH); 
  digitalWrite(soler_power,LOW); 
  run_wind_tower();
}

void case2(){
  digitalWrite(battery1,LOW);
  digitalWrite(battery2,LOW);
  digitalWrite(tower,HIGH); 
  digitalWrite(soler_power,HIGH); 
  run_wind_tower();
}

void case3(){
  digitalWrite(soler_power,LOW); 
  digitalWrite(battery1,LOW);
  digitalWrite(battery2,LOW);
  digitalWrite(tower,LOW); 
  run_wind_tower();
}

void run_wind_tower(){
  int on_win = check_wind();
  if (on_win == 1) {
    Serial.print("on wind tower :");
    Serial.println(on_win);
    digitalWrite(relay,LOW);//ON
  } else {
    Serial.print("off wind tower :");
    Serial.println(on_win);
    digitalWrite(relay,HIGH);//OFF
  }
}

int wind_power(){
  int IO = analogRead(wind);
  int on_wind = 0 ;
  if(IO >= 16){
    on_wind = 1;
  }
  else{
    on_wind = 0;
  }
  return on_wind;
}

int check_wind(){
  int check_power = wind_power();
  if(check_power == 0){
    if(counter_off_wind == 50){
      return 0;
    }else{
      counter_off_wind += 1;
      return 1;
    }
  }else{
    counter_off_wind = 0;
    return 1;
  }
  
}
