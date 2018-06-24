#include <Arduino.h>
// Arduino_dev_board v 1.0
// Leds massive wave witch potenciometer
// V 1.0
// константы
const int analogPin = 1;   // порт для потенциометра
const int ledCount = 5;    // число светодиодов на светодиодной шкале

int ledPins[] = { 
  8, 9, 10, 11, 12 };   // массив портов, к которым привязаны светодиоды


void setup() 
{
  // проходим через все элементы массива и устанавливаем режим для выхода
  for (int thisLed = 0; thisLed < ledCount; thisLed++) 
  {
    pinMode(ledPins[thisLed], OUTPUT); 
  }
}

void loop() 
{
  // считываем сигнал с потенциометра
  int sensorReading = analogRead(analogPin);
  // трансформируем результат в диапазон от 0 до 10 (по числу светодиодов)
  int ledLevel = map(sensorReading, 0, 1023, 0, ledCount);

  // проходим через массив светодиодов
  for (int thisLed = 0; thisLed < ledCount; thisLed++) 
  {
    // если индекс элемента массива меньше чем ledLevel,
    // включаем порт для данного элемента:
    if (thisLed < ledLevel) {
      digitalWrite(ledPins[thisLed], HIGH);
    } 
    // Выключаем все порты, которые выше чем ledLevel:
    else 
    {
      digitalWrite(ledPins[thisLed], LOW); 
    }
  }
}
