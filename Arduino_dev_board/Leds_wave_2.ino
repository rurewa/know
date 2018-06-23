void setup() 
{
  /*pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);*/
  for (int thisPin = 8; thisPin <= 12; thisPin++)
    {
      pinMode(thisPin, OUTPUT);
    }
}

void loop() 
{
  for (int pin = 8; pin <= 12; pin++)
  {
    digitalWrite(pin, HIGH);
    delay(100);
    digitalWrite(pin, LOW);
    delay(100);
  }  
}
