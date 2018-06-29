// Arduino_dev_board v 1.0
// Motor PWM
// V 1.0

void setup() 
{
  Serial.begin(9600);
  pinMode(3, OUTPUT); // Motor
}

void loop() 
{
  
  for (int i=10; i<=256; i++)
  {
    analogWrite(3, i);
    delay(10);
  }
  for (int i=255; i>=10; i--)
  {
    analogWrite(3, i);
    delay(10);
  }
  delay(2000);
}
