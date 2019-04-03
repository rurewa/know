void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  static int var = 0; // static сохраняет своё значение между вызовами функции
  while (var < 5) // Задаём нужное количество
  {
    var++; // инкремент - увеличивает значение var на 1
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
  }
}
