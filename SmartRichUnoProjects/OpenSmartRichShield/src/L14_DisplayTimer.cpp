/************************************************* ************************************************** ******
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
                                       //the next display takes effect
* disp.point(0); // Turn off the display colon and the next display takes effect
* disp.point(1); // Turn on the display colon and the next display takes effect
* display(double Decimal);// display a floating-point value
* Программа выполняет отсчёт от 0 до 9999 и обратно. При достижении заданных значений включаются
* или выключаются светодиоды.
* Таймер с цифровым дисплеем. V 1.0
************************************************** **************************************************/
#include <Arduino.h>
#include <Wire.h>
#include "RichShieldTM1637.h"

const int CLK = 10; //CLK of the TM1637 IC connect to D10 of OPEN-SMART UNO R3
const int DIO = 11; //DIO of the TM1637 IC connect to D11 of OPEN-SMART UNO R3
TM1637 disp(CLK, DIO);

void setup() {
  Serial.begin(9600);
  disp.init(); //The initialization of the display
  disp.set(1);
  for (int i = 4; i <= 7; ++i) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  static int up = 0;
  static int down = 5;
  static unsigned long oneTime = millis();
  while(millis() >= oneTime) {
    disp.display(up);
    up += down;
    // Когда up < 9999 происходит приращение на 5. Когда up >= 9999
    // происходит выполнение up += -down (уменьшение на 5)
    if(up <= 0 || up >= 9999) {
      down = -down; // Тут просто down -5 до тех пор, пока up <= 0
    }
    oneTime = millis() + 50;
    Serial.println(up);
    if (up == 2500) { digitalWrite(7, !digitalRead(7)); }
    if (up == 5000) { digitalWrite(6, !digitalRead(6)); }
    if (up == 7500) { digitalWrite(5, !digitalRead(5)); }
    if (up == 9990) { digitalWrite(4, !digitalRead(4)); }
  }
}
/*********************************************************************************************************
The end of file
*********************************************************************************************************/
