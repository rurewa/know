// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Тест для светодиодной матрицы 8х8 DISPLAY MH (MAX7219)
// RANDOM
// lc.setLed(0, 1, 2, true); // 0 - номер экрана, 1 - столбец (0-7), 2 - ряд (0-7), true - экран включён
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>
#include "LedControl.h"
/*
 Теперь настраиваем объект LedControl.
 Эти номера контактов, возможно, не будут работать в вашем проекте.
 Если необходимо, поменяйте их.
 5-ый контакт подключен к DIN.
 6-ый контакт подключен к CLK.
 7-ый контакт подключен к CS.
 У нас есть только один MAX72XX.
 */
LedControl lc=LedControl(5, 6, 7, 1);

void setup()
{
  lc.shutdown(0, false);// Выключить энергосбережение, включить матрицу
  lc.setIntensity(0, 0);// Устанавлить яркость (0 ~ 15 возможных значений)
  lc.clearDisplay(0);// Очистить матрицу
}

void loop() {
  static int RAND = 0;
  RAND = random(0, 9);

  for (int row = 0; row <= 8; row++) { // Нарастание по рядам
    lc.setLed(0, row, RAND, true); // Включение рядов светодиодов в случайном порядке
  }
  delay(50);
  for (int row = 0; row <= 8; row++) {
    lc.setLed(0, row, RAND, false); // Выключение рядов светодиодов в случайном порядке
  }
  delay(50);
}