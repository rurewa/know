// Мигаем светодиодом при помощи функции времени и оператора while
// V 1.0
 
void setup()
{
  pinMode(9 , OUTPUT); 
}

void loop()
{
  static unsigned long CurrentTime;
  unsigned long HighTime;
  unsigned long LowTime;
  CurrentTime = millis();
  HighTime = CurrentTime + 500;
  LowTime = CurrentTime + 5000;
  while (CurrentTime < HighTime)
  {
    digitalWrite(9, HIGH);
    CurrentTime= millis();
  }
  while (CurrentTime < LowTime)
  {
    digitalWrite(9, LOW);
    CurrentTime = millis();
  }
}
