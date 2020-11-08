// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Тест для светодиодной матрицы 8х8 MAX7219
// Вариант 1
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
LedControl lc=LedControl(5,6,7,1);
 
/* Делаем небольшую задержку между обновлениями дисплея. */
unsigned long delaytime=100;
 
void setup() {
  /*
   По умолчанию при запуске у MAX72XX включается энергосберегающий
   режим, поэтому мы должны его «разбудить».
   */
  lc.shutdown(0,false);
  /* Задаем среднюю яркость. */
  lc.setIntensity(0,8);
  /* Очищаем дисплей. */
  lc.clearDisplay(0);
}
 
/*
 Эта функция будет показывать на матрице символы  для
 Слова «Arduino» – один за другим (чтобы видеть  полные
 символы, размер матрицы должен быть как минимум 5 на 7).
*/
void writeArduinoOnMatrix() {
  /* Данные для символов. */
  byte a[5]={B01111110,B10001000,B10001000,B10001000,B01111110};
  byte r[5]={B00111110,B00010000,B00100000,B00100000,B00010000};
  byte d[5]={B00011100,B00100010,B00100010,B00010010,B11111110};
  byte u[5]={B00111100,B00000010,B00000010,B00000100,B00111110};
  byte i[5]={B00000000,B00100010,B10111110,B00000010,B00000000};
  byte n[5]={B00111110,B00010000,B00100000,B00100000,B00011110};
  byte o[5]={B00011100,B00100010,B00100010,B00100010,B00011100};
 
  /* Теперь показываем их один за одним с определенной задержкой. */
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
 Эта функция включает несколько светодиодов, находящихся в одном ряду.
 Заданный паттерн будет повторяться в каждом ряду.
 Кроме того, паттерн будет моргать в соответствии с номером ряда.
 То есть ряд номер 4 (индекс 3) будет моргать 4 раза и т.д.
*/
void rows() {
  for(int row=0;row<8;row++) {
    delay(delaytime);
    lc.setRow(0,row,B10100000);
    delay(delaytime);
    lc.setRow(0,row,(byte)0);
    for(int i=0;i<row;i++) {
      delay(delaytime);
      lc.setRow(0,row,B10100000);
      delay(delaytime);
      lc.setRow(0,row,(byte)0);
    }
  }
}
 
/*
 Включает несколько светодиодов, находящихся в одном столбце.
 Заданный паттерн будет повторяться в каждом столбце.
 Кроме того, паттерн будет моргать в соответствии с номером столбца.
 То есть столбец номер 4 (индекс 3) будет моргать 4 раза и т.д.
 */
void columns() {
  for(int col=0;col<8;col++) {
    delay(delaytime);
    lc.setColumn(0,col,B10100000);
    delay(delaytime);
    lc.setColumn(0,col,(byte)0);
    for(int i=0;i<col;i++) {
      delay(delaytime);
      lc.setColumn(0,col,B10100000);
      delay(delaytime);
      lc.setColumn(0,col,(byte)0);
    }
  }
}
 
/*
 Эта функция поочередно включает все светодиоды в матрице.
 Кроме того, светодиод будет моргать в соответствии с номером ряда.
 То есть ряд номер 4 (индекс 3) будет моргать 4 раза и т.д.
 */
void single() {
  for(int row=0;row<8;row++) {
    for(int col=0;col<8;col++) {
      delay(delaytime);
      lc.setLed(0,row,col,true);
      delay(delaytime);
      for(int i=0;i<col;i++) {
        lc.setLed(0,row,col,false);
        delay(delaytime);
        lc.setLed(0,row,col,true);
        delay(delaytime);
      }
    }
  }
}
 
void loop() {
  writeArduinoOnMatrix();
  rows();
  columns();
  single();
}
