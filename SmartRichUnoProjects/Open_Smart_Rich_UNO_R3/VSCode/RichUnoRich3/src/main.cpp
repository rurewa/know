/*************************************************************************************************** ******
* OPEN-SMART Rich Shield Lesson 4: Display number
* You can learn how to display numbers, which can be displayed in bits, or you can display integers directly
*
* The following functions are available:
*
* disp.init(); // initialization
* disp.display(int8_t DispData []); // display the numbers in the array
* // For example, the array is {1,2,3,4}, then show 1234
* disp.display(uint8_t BitAddr, int8_t DispData); // bit by bit to display numbers, characters, BitAddr range is 0 ~ 3,
* // Parameter DispData range is 0 ~ 17 represents 0 ~ 9, A, b, c, d, E, F, -, space
* disp.display(int Decimal);   // display range: -999 ~ 9999
* disp.clearDisplay(); // clear the display
* disp.set(uint8_t brightness); // set the brightness, 0 ~ 7, the greater the value, the higher the brightness,
*                                       //the next display takes effect
* disp.point(0); // Turn off the display colon and the next display takes effect
* disp.point(1); // Turn on the display colon and the next display takes effect
* display(double Decimal);// display a floating-point value
* Запрограммированы 4-е сенсорных кнопки без библиотеки для вывода на экран
* Сенсорные кнопки с дисплеем. V 1.0
*****************************************************************************************************/
#include <Arduino.h>
#include "RichShieldTM1637.h"

const int CLK = 10; //CLK of the TM1637 IC connect to D10 of OPEN-SMART UNO R3
const int DIO = 11; //DIO of the TM1637 IC connect to D11 of OPEN-SMART UNO R3
TM1637 disp(CLK, DIO);

const int TOUCH_1 = 3;
const int TOUCH_2 = 4;
const int TOUCH_3 = 5;
const int TOUCH_4 = 6;

void setup() {
  disp.init(); //The initialization of the display
}

void loop() {
  bool touchState_1 = digitalRead(TOUCH_1);
  bool touchState_2 = digitalRead(TOUCH_2);
  bool touchState_3 = digitalRead(TOUCH_3);
  bool touchState_4 = digitalRead(TOUCH_4);

  int8_t ListDisp_1[4] = {1, 1, 1, 1};
  int8_t ListDisp_2[4] = {2, 2, 2, 2};
  int8_t ListDisp_3[4] = {3, 3, 3, 3};
  int8_t ListDisp_4[4] = {4, 4, 4, 4};
  int8_t ListDisp_5[4] = {0, 0, 0, 0};
  if (touchState_1 == true) { disp.display(ListDisp_1); }
  else if (touchState_2  == true) { disp.display(ListDisp_2); }
  else if (touchState_3  == true) { disp.display(ListDisp_3); }
  else if (touchState_4  == true) { disp.display(ListDisp_4); }
  else { disp.display(ListDisp_5); }
}
/*********************************************************************************************************
The end of file
*********************************************************************************************************/