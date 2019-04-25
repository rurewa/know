// Функция для генерации 3-х точек
void threeDots()
{
  // Конструкция для приращения и завершения цикла
  for (int i=0; i<3; i++) // 
  {
    digitalWrite(13, HIGH);
    delay(200);
    digitalWrite(13, LOW);
    delay(200);
  }
  delay(300); //
}

//
void threeDashes()
{
  // Конструкция для приращения и завершения цикла
  for (int i=0; i<3; i++) //
  {
    digitalWrite(13, HIGH);
    delay(400);
    digitalWrite(13, LOW);
    delay(200);
  }
  delay(300); //
}

void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  // Циклично повторяем функции генерации сигнала с задержкой
  threeDots();
  threeDashes();
  threeDots();
  delay(1500);
}
