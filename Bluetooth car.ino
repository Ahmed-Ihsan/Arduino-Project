//ARDUINO UNO R3
int brakeTime = 45;
int lastButtonState = 0;
int buttonState = 0;
int command;
int brkonoff = 1;
int Speedsec;
int Turnradius = 0;
int Speed = 204;
void setup()
{
Serial.begin(9600); // SPEED SEND DATA IS 9600
// I CAN USING 12 PIN OUTPUT OR INPUT IN ARDUINO
pinMode(2, OUTPUT);  //1
pinMode(3, OUTPUT);  //2
pinMode(4, OUTPUT);  //3
pinMode(5, OUTPUT);  //4
pinMode(6, OUTPUT);  //5
pinMode(7, OUTPUT);  //6
pinMode(8, OUTPUT);  //7
pinMode(9, OUTPUT);  //8
pinMode(10, OUTPUT); //9
pinMode(11, OUTPUT); //10
pinMode(12, OUTPUT); //11
pinMode(13, OUTPUT); //12
} 

void loop()
{
if (Serial.available() > 0)
{
command = Serial.read();
Stop();
switch (command)
{ // I USING 8 PIN OUTPUT IN ARDUINO
case 'F':
forward();
break;
case 'B':
back();
break;
case 'L':
left();
break;
case 'R':
right();
break;
case 'G':
forwardleft();
break;
case 'I':
forwardright();
break;
case 'H':
backleft();
break;
case 'J':
backright();
break;
case 'W':
digitalWrite(12, HIGH);
break;
case 'w':
digitalWrite(12, LOW);
break;
case 'V':
digitalWrite(13, HIGH);
break;
case 'v':
digitalWrite(13, LOW);
break;
case 'U':
digitalWrite(4, HIGH);
break;
case 'u':
digitalWrite(4, LOW);
break;
case 'X':
digitalWrite(7, HIGH);
break;
case 'x':
digitalWrite(7, LOW);
break;
case '0':
Speed = 100;
break;
case '1':
Speed = 140;
break;
case '2':
Speed = 153;
break;
case '3':
Speed = 165;
break;
case '4':
Speed = 178;
break;
case '5':
Speed = 191;
break;
case '6':
Speed = 204;
break;
case '7':
Speed = 216;
break;
case '8':
Speed = 229;
break;
case '9':
Speed = 242;
break;
case 'q':
Speed = 255;
break;
}
Speedsec = Turnradius;
if (brkonoff == 1)
{
brakeOn();
}
else
{
brakeOff();
}
}
}

void forward()
{
analogWrite(5, Speed);
analogWrite(10, Speed);
}

void Stop()
{
analogWrite(5, 0);
analogWrite(6, 0);
analogWrite(10, 0);
analogWrite(11, 0);
}

void back()
{
analogWrite(6, Speed);
analogWrite(11, Speed);
}

void left()
{
analogWrite(10, Speed);
analogWrite(6, Speed);
}

void right()
{
analogWrite(11, Speed);
analogWrite(5, Speed);
}

void forwardleft()
{
analogWrite(5, Speedsec);
analogWrite(10, Speed);
}

void forwardright()
{
analogWrite(5, Speed);
analogWrite(10, Speedsec);
}

void backright()
{
analogWrite(6, Speed);
analogWrite(11, Speedsec);
}

void backleft()
{
analogWrite(6, Speedsec);
analogWrite(11, Speed);
}

void brakeOn()
{
buttonState = command;
if (buttonState != lastButtonState)
{
if (lastButtonState == 'F')
{
if (buttonState == 'S')
{
back();
delay(brakeTime);
Stop();
}
}
if (lastButtonState == 'B')
{
if (buttonState == 'S')
{
forward();
delay(brakeTime);
Stop();
}
}
if (lastButtonState == 'L')
{
if (buttonState == 'S')
{
right();
delay(brakeTime);
Stop();
}
}
if (lastButtonState == 'R')
{
if (buttonState == 'S')
{
left();
delay(brakeTime);
Stop();
}
}
}
lastButtonState = buttonState;
}
void brakeOff() {}

