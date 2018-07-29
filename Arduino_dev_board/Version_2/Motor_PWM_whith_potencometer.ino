// Arduino_dev_board v 2.0
// Motor PWM whith potencometer
// V 1.0

void setup()
{
  Serial.begin(9600);
  pinMode(3, OUTPUT); // Motor
}

void loop()
{
  int val = analogRead(7);
  Serial.print("Analog: ");
  Serial.print(val);
  val = map(val, 0, 1023, 0, 254);
  analogWrite(3, val);
  Serial.print(" | PWM: ");
  Serial.println(val);
}
