// Arduino_dev_board v 1.0
// Motor PWM whith potencometer
// V 1.0

void setup() 
{
  pinMode(3, OUTPUT); // Motor
}

void loop() 
{
  int val = analogRead(1);
  val = map(val, 0, 1024, 0, 256);
  analogWrite(3, val);
}
