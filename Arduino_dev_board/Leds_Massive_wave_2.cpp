// Massive leds wave for Arduino_dev_board v 1.0 & 2.0
// V1.0

int led[5] = {8, 9, 10, 11, 12}; // Определяем переменные при помощи массива
int timer = 100;

void setup()
{
    // Конструкция приращения
    for (int thisPin = 0; thisPin < 5; thisPin++)
    {
        // Настраиваем пины как ВЫХОД
        pinMode(led[thisPin], OUTPUT);
    }
}

void loop()
{
  // Клнструкция приращения
  for (int thisPin = 0; thisPin < 5; thisPin++)
  {
    digitalWrite(led[thisPin], HIGH);
    delay(timer);
    digitalWrite(led[thisPin], LOW);
  }
  for (int thisPin = 4; thisPin > 0; thisPin--)
  {
    digitalWrite(led[thisPin], HIGH);
    delay(timer);
    digitalWrite(led[thisPin], LOW);
  }
}
