// Arduino_dev_board v 1.0
// V 1.0
// PWM led
const int led = 9;

void setup() 
{
    pinMode(led, OUTPUT);
}

void loop() 
{
   for (int i=10; i<256; i++)
   {
       analogWrite(led, i);
       delay(10);
   }
   for (int i=255; i>=10; i--)
   {
       analogWrite(led, i);
       delay(10);
   }
}
