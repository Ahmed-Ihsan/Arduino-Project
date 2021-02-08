const int val_const = 350;
const int pin_motor = 12;
const int pin_s1=11;
const int pin_s2=10;
const int pin_s3=9;
const int pin_s4=8;
int val=0;
int arr[4];
int valve[4]={11,10,9,8};


void setup() {
    Serial.begin(9600); 
    pinMode(pin_motor , OUTPUT);
    pinMode(pin_s1,OUTPUT);
    pinMode(pin_s2,OUTPUT);
    pinMode(pin_s3,OUTPUT);
    pinMode(pin_s4,OUTPUT);
}
void loop() {
    off(pin_motor);
    all_Check();
    Valve();
    All_off();
}

void all_Check(){
    arr[0]=Check(0);
    arr[1]=Check(1);
    arr[2]=Check(2);
    arr[3]=Check(3);
}

int Check(int A){
    int Switch=0;
    val = analogRead(A);
    if( val <= val_const ){
        Switch=1;
        }
    print(val , A);
    delay(100);
    return Switch;
}

void print(int senser , int pin){
    Serial.print("senser ");
    Serial.print(senser);
    Serial.print(": pin ");
    Serial.println(pin); 
}

void Valve(){
    int motor=0;
    for (int i=0 ; i < 4 ;i++){
        if (arr[i]){
            on(valve[i]);
            motor=1;
        }
    }
    if (motor){
        on(pin_motor);
        delay(5000);
        off(pin_motor);
    }
}

void All_off(){
    for(int i=0 ; i < 4 ; i++){
        off(valve[i]);
    }
}

void off(int i){
    digitalWrite(i, HIGH);
    delay(10);
}
void on(int j){
    digitalWrite(j, LOW);
    delay(10);
}
