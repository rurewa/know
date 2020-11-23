/************************************************* ************************************************** ******
* OPEN-SMART Rich Shield Lesson 8: Knob angle display
* You can learn get the angle of the knob(rotary angle sensor) and display.
* The following functions are available:
* knob.getAngle();//read the angle of the knob, the range of angle is 0~280 degrees
* disp.init(); // initialization
* disp.display(int Decimal);   // display range: -999 ~ 9999
* Управление потенцометром с выводом результата на экран. V 1.0
************************************************** **************************************************/
#include <Arduino.h>
#include <Wire.h>
#include "RichShieldTM1637.h"
#include "RichShieldKnob.h"
const int KNOB_PIN = A0; //SIG pin of Rotary Angle Sensor module connect to A0 of IO Shield, that is pin A0 of OPEN-SMART UNO R3
Knob knob(KNOB_PIN);

const int CLK = 10; //CLK of the TM1637 IC connect to D10 of OPEN-SMART UNO R3
const int DIO = 11; //DIO of the TM1637 IC connect to D11 of OPEN-SMART UNO R3
TM1637 disp(CLK, DIO);

void setup() {
  disp.init();//The initialization of the display
}

void loop() {
  int angle;
  angle = knob.getAngle();
  disp.display(angle);
  delay(500);
}
/*********************************************************************************************************
The end of file
*********************************************************************************************************/
