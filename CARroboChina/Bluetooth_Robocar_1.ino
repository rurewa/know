// Bluetooth Robocar for Chine 1
// V 1.0
int MotorRight1=5;
int MotorRight2=6; 
int MotorLeft1=10; 
int MotorLeft2=11;

void setup()
{
Serial.begin(9600);
pinMode(MotorRight1, OUTPUT); 
pinMode(MotorRight2, OUTPUT); 
pinMode(MotorLeft1, OUTPUT); 
pinMode(MotorLeft2, OUTPUT); 
}


void go()// go forward
{
digitalWrite(MotorRight1,LOW); 
digitalWrite(MotorRight2,HIGH); 
digitalWrite(MotorLeft1,LOW); 
digitalWrite(MotorLeft2,HIGH);
}


void left() // turn right
{
digitalWrite(MotorRight1,HIGH); 
digitalWrite(MotorRight2,LOW); 
digitalWrite(MotorLeft1,LOW); 
digitalWrite(MotorLeft2,HIGH);
}
void right() // turn left 
{
digitalWrite(MotorRight1,LOW); 
digitalWrite(MotorRight2,HIGH); 
digitalWrite(MotorLeft1,HIGH); 
digitalWrite(MotorLeft2,LOW);
}
void stop() // stop 
{
digitalWrite(MotorRight1,LOW); 
digitalWrite(MotorRight2,LOW);
digitalWrite(MotorLeft1,LOW);
digitalWrite(MotorLeft2,LOW);
}
void back() // go backwards
{
digitalWrite(MotorRight1,HIGH); 
digitalWrite(MotorRight2,LOW); 
digitalWrite(MotorLeft1,HIGH); 
digitalWrite(MotorLeft2,LOW);;
}


void loop()
{
char val = Serial.read(); 
Serial.write(val);
if (-1 != val) {
if ('U' == val)
go();
else if ('L' ==val) left();
else if ('R' == val) right();
else if ('D' == val) back();
else if ('S' == val) stop(); 
delay(500);
}
else
{
//stop(); delay(500);
}
}
