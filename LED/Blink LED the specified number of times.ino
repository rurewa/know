void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  static int var = 0;
  while (var < 5)
  {
    var++;
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
  }
}
