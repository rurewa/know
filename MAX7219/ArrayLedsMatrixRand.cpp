// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Тест для светодиодной матрицы 8х8 DISPLAY MH (MAX7219)
// Код в случайном порядке включает на матрицы светодиды
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

int indexLeds[8] = { 0,1,2,3,4,5,6,7 }; // Массив из номеров светодиодов матрицы
int rowIndex = 0; // Светодиоды строки матрицы
int colIndex = 0; // Светодиоды столбца матрицы

void setup()
{
  lc.shutdown(0, false);// Выключить энергосбережение, включить матрицу
  lc.setIntensity(0, 1);// Устанавлить яркость (0 ~ 15 возможных значений)
  lc.clearDisplay(0);// Очистить матрицу
}

void loop()
{
  rowIndex = random(0, 8);
  colIndex = random(0, 8);
  lc.setLed(0, indexLeds[rowIndex], indexLeds[colIndex], true);
  delay(100);
  lc.setLed(0, indexLeds[rowIndex], indexLeds[colIndex], false);
  delay(100);
  //lc.setLed(0, 1, 2, true); // 0 - номер экрана, 1 - столбец (0-7), 2 - ряд (0-7), true - экран включён
}
