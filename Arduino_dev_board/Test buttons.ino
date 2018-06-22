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
    pinMode(inPin8, INPUT);
    pinMode(inPin9, INPUT);
}

void loop() 
{
   val1 = analogRead(inPin8);
   val2 = analogRead(inPin9);
   Serial.print("AnalogOne: ");
   Serial.print(val1);
   Serial.print("  AnalogTwo: ");
   Serial.print(val2);
   val1 = analogRead(inPin8) > 700 ? LOW : HIGH;
   val2 = analogRead(inPin9) > 700 ? LOW : HIGH;
   Serial.print("  Button ONE: ");
   Serial.print(val1);
   Serial.print(" || ");
   Serial.print("  Button TWO: ");
   Serial.println(val2);
   delay(150);
}
