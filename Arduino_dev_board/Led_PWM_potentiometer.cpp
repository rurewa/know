// Arduino_dev_board v 1.0
// V 1.0
// PWM potentiometer led
const int led = 9;
const int pot = 1;
int val = 0;

void setup() 
{
    pinMode(led, OUTPUT);
}

void loop() 
{
   val = analogRead(pot) / 2;
   analogWrite(led, val);
}
