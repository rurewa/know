// Blink alternate 1
// V 1.0
void setup() 
{
  pinMode(13, OUTPUT);
}

void loop() 
{
  digitalWrite(13, !digitalRead(13));
  delay(100);
}
