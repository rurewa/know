// Arduino_dev_board v 1.0
// V 1.0
// Test potentiometer
const int pot = 1;
int val;

void setup() 
{
    Serial.begin(9600);
    pinMode(pot, INPUT);
}

void loop() 
{
   val = analogRead(pot);
   Serial.println(val);
   delay(150);
}
