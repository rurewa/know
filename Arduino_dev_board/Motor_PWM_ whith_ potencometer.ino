// Arduino_dev_board v 1.0
// Motor PWM whith potencometer
// V 1.0

void setup() 
{
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

void loop() 
{
  int val = analogRead(1);
  val = map(val, 0, 1024, 0, 256);
  analogWrite(3, val);
}
