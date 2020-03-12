// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Светодиодная волна при помощи алгоритмов
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>
// Указываем размер массива
const int ARRAY_SIZE = 5;
// Объявляем массив элементов
const int ARRAY_PINS_LEDS[ARRAY_SIZE] = {8, 9, 10, 11, 12};

void setup() {
  // Настройка пинов в режиме ВЫХОД
  for (int i = 0; i < ARRAY_SIZE; ++i) {
    pinMode(ARRAY_PINS_LEDS[i], OUTPUT);
  }
}

void loop() {
  // Состояние текущего светодиода
  static int currentLed = 0;
  // Шаг
  static int directWave = 1;
  // Выключение всех светодиодов (циклично)
  for (int x = 0; x < ARRAY_SIZE; ++x) {
    digitalWrite(ARRAY_PINS_LEDS[x], LOW);
  }
  // Включаем текущий светодиод
  digitalWrite(ARRAY_PINS_LEDS[currentLed], HIGH);
  // Начало движения светодиодной волны
  currentLed += directWave; // currentLed = currentLed + directWave
  // Когда currentLed становится 4
  if (currentLed == ARRAY_SIZE -1) {
    // Начинается обратный отчёт
    directWave = -directWave; // currentLed += -directWave
  }
  // Когда отчёт достигает 0
  if (currentLed == 0) {
    // Возвращаем исходное значение
    directWave = 1;
  }
  delay(300); // Задержка для мигания
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //