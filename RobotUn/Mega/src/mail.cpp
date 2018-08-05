#include <Arduino.h>
#include <ControlLeds.h> // Моя библиотека
// Test № 3 led matrix 7219 for Arduino dev board 2.0
// V 1.0
/*
 pin 5 is connected to the DataIn
 pin 6 is connected to the CLK
 pin 7 is connected to LOAD
 1 - количество подключённых устройств
 */
LedControl lc = LedControl(5, 6, 7, 1);

GrowingSquares runsquares; // Растущий квадрат
SineWave runwave; // Синусоидная волна
WindMill runwindmill; // Ветряная мельница
FlashAllLeds runflas; // Зажигаем все светодиоды
LightLedsRandomly runrandomly; // Зажигаем всетодиоды в случайном порядке
SwipeColumns runswipecol; // Скользящая полоса по колонке
SwipeRows runswiperows; // Скользящая полоса по ряду
Countdown countdown; // Обратный отчёт 5-0
WiteOnMatrix runsimbols; // Слово

void setup()
{
  lc.shutdown(0, false); // Вывод из спящего режима
  lc.setIntensity(0, 8); // Минимальная яркость
  lc.clearDisplay(0); // Очистка дисплея
}

void loop()
{
  runsimbols.runSimbols(); // Слово
  countdown.countDown(); // Обратный отчёт 5-0
  runsquares.runState(); // Растущий квадрат
  runwave.runWave(); // Синусоидная волна
  runwindmill.runWindmill(); // Ветряная мельница
  runflas.runFlash(); // Зажигаем все светодиоды
  runrandomly.runRandomly(); // Зажигаем всетодиоды в случайном порядке
  runswipecol.runSwipeCol(); // Скользящая полоса
  runswiperows.runSwipeRows(); // Скользящая полоса по ряду
}
