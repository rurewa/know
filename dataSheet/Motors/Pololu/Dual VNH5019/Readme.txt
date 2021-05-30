https://www.pololu.com/product/2502

https://github.com/pololu/dual-vnh5019-motor-shield

_INA1 = 2;
  _INB1 = 4;
  _PWM1 = 9;
  _EN1DIAG1 = 6;
  _CS1 = A0;
  _INA2 = 7;
  _INB2 = 8;
  _PWM2 = 10;
  _EN2DIAG2 = 12;
  _CS2 = A1;

Свободны пины:

D - 3, 5, 11, 13
A - A3, A4, A5

md.init(); // Инициализация
/*md.setM1Speed(200);
  md.setM2Speed(200);
  stopIfFault();
  delay(1000);
  md.setM1Speed(-200);
  md.setM2Speed(-200);
  delay(1000);*/