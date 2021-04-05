// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// Простой алгоритм счётчика нажатий 2-х кнопок
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
#include <Arduino.h>
#include "Button_Simple.h"

Button_Simple button13(13); // Пин кнопки
Button_Simple button17(17); // Пин кнопки

// Определяем группу ячеек в массиве
const int CELL[5] = {8, 9, 10, 11, 12};

int COUNT = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i <= 4; ++i) {
    pinMode(CELL[i], OUTPUT);
  }
}

void loop() {
  static int click13 = 0; // Состояние режима 1/0
  static int click17 = 0; // Состояние режима 1/0
  button13.scan(); // Инициализация библиотеки
  button17.scan(); // Инициализация библиотеки
  while (button17.clicked()) { // Если нажали
    if (++click17 >= 2) { click17 = 0; ++COUNT;} // Счётчик с ограничителем (0/1)
    if (click17 == 1) { ++COUNT; }
  }
  while (button13.clicked()) {
    if (++click13 >= 2) { click13 = 0; --COUNT;} // Счётчик с ограничителем (0/1)
    if (click13 == 1) { --COUNT; }
  }
  Serial.println(COUNT); // Для диагностики
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
