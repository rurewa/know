#include <Arduino.h>
// Controlling RGB LEDs using arrays for Arduino dev board 2.0
// V1.0

int ledPins[] = {9, 10, 11}; // Определяем переменные при помощи массива
int pinCount = 3; // Длина массива
int timer = 500; // Задержка

void setup()
{
  // Конструкция приращения for
  for (int thisPin = 0; thisPin < pinCount; thisPin++)
    {
        // Используем оператор for для определения
        // пинов как ВЫХОД при помощи массива
        pinMode(ledPins[thisPin], OUTPUT);
    }
}

void loop()
{
  for (int thisPin = 0; thisPin < pinCount; thisPin++)
        {
            digitalWrite(ledPins[thisPin], HIGH);
            delay(timer);
            digitalWrite(ledPins[thisPin], LOW);
        }
}
