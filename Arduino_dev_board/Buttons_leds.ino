// Arduino_dev_board v 1.0

const int inPin = A7;
int val;

void setup() 
{
    Serial.begin(9600);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(inPin, INPUT);
}

void loop() 
{
   val = analogRead(inPin)> 700 ? 0 : 1;
   analogWrite(8, val);
   Serial.println(val, DEC);
   delay(150);
}
