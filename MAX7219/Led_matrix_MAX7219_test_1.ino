#include "LedControl.h"
// Led matrix MAX7219
// V 1.0
LedControl lc=LedControl(12,11,10,1);
// pin 12 DIN
// pin 11 CLK
// pin 10 CS
// 1 as we are only using 1 MAX7219

void setup()
{
  // 0 для первого чипа
  lc.shutdown(0,false);// Выключить энергосбережение, включить отображение
  lc.setIntensity(0,8);// Устанавливает яркость (0 ~ 15 возможных значений)
  lc.clearDisplay(0);// Очистить экран
}
void loop()
{
  for (int row=0; row<8; row++)
  {
    for (int col=0; col<8; col++)
    {
      lc.setLed(0,col,row,true); // Включает светодиоды в колонке, строке
      delay(25);
    }
  }

  for (int row=0; row<8; row++)
  {
    for (int col=0; col<8; col++)
    {
      lc.setLed(0,col,row,false); // Выключает светодиоды в колонке, строке
      delay(25);
    }
  }
}
