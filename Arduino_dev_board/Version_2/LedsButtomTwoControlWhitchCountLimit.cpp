// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// Простой алгоритм счётчика нажатий 2-х кнопок
// V 1.1
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
#include <Arduino.h>
#include "Button_Simple.h"

Button_Simple button13(13); // Пин кнопки
Button_Simple button17(17); // Пин кнопки

// Верхний и нижний лимиты счётчика
const int LIMIT_UP = 4;
const int LIMIT_DOWN = 0;

// Определяем группу ячеек в массиве
const int LEDS[5] = {8, 9, 10, 11, 12};

void setup() {
  Serial.begin(9600);
  // Настраиваем светодиоды на управление
  for (int i = 0; i <= 4; ++i) {
    pinMode(LEDS[i], OUTPUT);
  }
}

void loop() {
  static int click13 = 0; // Состояние режима кнопки 1/0
  static int click17 = 0; // Состояние режима кнопки 1/0
  button13.scan(); // Инициализация библиотеки
  button17.scan(); // Инициализация библиотеки
  static int COUNT = 0; // Счётчик
  // Инкремент счётчика
  while (button17.clicked()) { // Если нажали
    if (++click17 >= 2) { click17 = 0; ++COUNT;} // Счётчик с ограничителем (0/1)
    if (click17 == 1) { ++COUNT; }
  }
  // Декремент счётчика
  while (button13.clicked()) {
    if (++click13 >= 2) { click13 = 0; --COUNT;} // Счётчик с ограничителем (0/1)
    if (click13 == 1) { --COUNT; }
  }
  while (COUNT >= LIMIT_UP) { COUNT = LIMIT_UP; break; } // Ограничение инкремента
  while (COUNT <= LIMIT_DOWN) { COUNT = LIMIT_DOWN; break; } // Ограничение декремента
  Serial.println(COUNT); // Для д
  for (int i = 0; i <= 4; ++i) {
    digitalWrite(LEDS[COUNT], HIGH);
    for (int i = 0; i <= 4; ++i) {
      digitalWrite(LEDS[COUNT - 1], LOW);
    }
    for (int i = 0; i <= 4; ++i) {
    digitalWrite(LEDS[COUNT - 1], HIGH);
    for (int i = 0; i <= 4; ++i) {
      digitalWrite(LEDS[COUNT], LOW);
    }
  }
 }
}  

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
