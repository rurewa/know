#include <Arduino.h>
#include "LedControl.h"
// Test led matrix 7219 for Arduino dev board 2.0
// V 1.0
/*
 pin 5 is connected to the DataIn
 pin 6 is connected to the CLK
 pin 7 is connected to LOAD
 */

LedControl lc=LedControl(5,6,7,1);

/* немного ждём перед обновлением матрицы */
unsigned long delaytime=100;

void setup()
{
  /*
   MAX72XX находится в режиме энергосбережения при запуске,
   мы её пробудить
   */
  lc.shutdown(0, false);
  /* Устанавливаем яркость в среднее значение */
  lc.setIntensity(0,8);
  /* и очищаем экран */
  lc.clearDisplay(0);
}

/*
Этот метод отобразит символы
 */
void writeArduinoOnMatrix()
{
  /* Данные для символов */
  byte a[5]={B01111110,B10001000,B10001000,B10001000,B01111110};
  byte r[5]={B00111110,B00010000,B00100000,B00100000,B00010000};
  byte d[5]={B00011100,B00100010,B00100010,B00010010,B11111110};
  byte u[5]={B00111100,B00000010,B00000010,B00000100,B00111110};
  byte i[5]={B00000000,B00100010,B10111110,B00000010,B00000000};
  byte n[5]={B00111110,B00010000,B00100000,B00100000,B00011110};
  byte o[5]={B00011100,B00100010,B00100010,B00100010,B00011100};

  /* Отображаем один за другим с небольшой задержкой*/
  lc.setRow(0,0,a[0]);
  lc.setRow(0,1,a[1]);
  lc.setRow(0,2,a[2]);
  lc.setRow(0,3,a[3]);
  lc.setRow(0,4,a[4]);
  delay(delaytime);
  lc.setRow(0,0,r[0]);
  lc.setRow(0,1,r[1]);
  lc.setRow(0,2,r[2]);
  lc.setRow(0,3,r[3]);
  lc.setRow(0,4,r[4]);
  delay(delaytime);
  lc.setRow(0,0,d[0]);
  lc.setRow(0,1,d[1]);
  lc.setRow(0,2,d[2]);
  lc.setRow(0,3,d[3]);
  lc.setRow(0,4,d[4]);
  delay(delaytime);
  lc.setRow(0,0,u[0]);
  lc.setRow(0,1,u[1]);
  lc.setRow(0,2,u[2]);
  lc.setRow(0,3,u[3]);
  lc.setRow(0,4,u[4]);
  delay(delaytime);
  lc.setRow(0,0,i[0]);
  lc.setRow(0,1,i[1]);
  lc.setRow(0,2,i[2]);
  lc.setRow(0,3,i[3]);
  lc.setRow(0,4,i[4]);
  delay(delaytime);
  lc.setRow(0,0,n[0]);
  lc.setRow(0,1,n[1]);
  lc.setRow(0,2,n[2]);
  lc.setRow(0,3,n[3]);
  lc.setRow(0,4,n[4]);
  delay(delaytime);
  lc.setRow(0,0,o[0]);
  lc.setRow(0,1,o[1]);
  lc.setRow(0,2,o[2]);
  lc.setRow(0,3,o[3]);
  lc.setRow(0,4,o[4]);
  delay(delaytime);
  lc.setRow(0,0,0);
  lc.setRow(0,1,0);
  lc.setRow(0,2,0);
  lc.setRow(0,3,0);
  lc.setRow(0,4,0);
  delay(delaytime);
}

/*
Эта функция подсвечивает несколько строк в строке.
Шаблон будет повторяться в каждой строке.
Шаблон будет мигать вместе с номером строки.
Строка номер 4 (индекс == 3) будет мигать 4 раза и т. д.
*/
void rows()
{
  for(int row=0;row<8;row++)
  {
    delay(delaytime);
    lc.setRow(0,row,B10100000);
    delay(delaytime);
    lc.setRow(0,row,(byte)0);
    for(int i=0;i<row;i++)
    {
      delay(delaytime);
      lc.setRow(0,row,B10100000);
      delay(delaytime);
      lc.setRow(0,row,(byte)0);
    }
  }
}

/*
Эта функция подсвечивает некоторые светодиоды в столбце.
Шаблон будет повторяться в каждом столбце.
Шаблон будет мигать вместе с номером столбца.
Столбец номер 4 (индекс == 3) будет мигать 4 раза и т. д.
*/
void columns()
{
  for(int col=0;col<8;col++)
  {
    delay(delaytime);
    lc.setColumn(0,col,B10100000);
    delay(delaytime);
    lc.setColumn(0,col,(byte)0);
    for(int i=0;i<col;i++)
    {
      delay(delaytime);
      lc.setColumn(0,col,B10100000);
      delay(delaytime);
      lc.setColumn(0,col,(byte)0);
    }
  }
}

/*
Эта функция вулючает каждый светодиод на матрице.
Светодиод будет мигать вместе с номером строки.
Строка номер 4 (индекс == 3) будет мигать 4 раза и т. д.
*/
void single() {
  for(int row=0;row<8;row++)
  {
    for(int col=0;col<8;col++)
    {
      delay(delaytime);
      lc.setLed(0,row,col,true);
      delay(delaytime);
      for(int i=0;i<col;i++)
      {
        lc.setLed(0,row,col,false);
        delay(delaytime);
        lc.setLed(0,row,col,true);
        delay(delaytime);
      }
    }
  }
}

void loop()
{
  writeArduinoOnMatrix();
  rows();
  columns();
  single();
}
