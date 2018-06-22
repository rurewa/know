// Arduino_dev_board v 1.0
// V 1.0
// Test buttons

const int inPin8 = A7;
const int inPin9 = A6;
int val1;
int val2;

void setup() 
{
    Serial.begin(9600);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(inPin8, INPUT);
    pinMode(inPin9, INPUT);
}

void loop() 
{
   val1 = analogRead(inPin8)> 700 ? 0 : 1;
   val2 = analogRead(inPin9)> 700 ? 0 : 1;
   analogWrite(8, val1);
   analogWrite(9, val2);
   Serial.print("Button ONE: ");
   Serial.print(val1, DEC);
   Serial.print(" || ");
   Serial.print("Button TWO: ");
   Serial.println(val2, DEC);
   delay(150);
}
