/************************************************* ************************************************** ******
* OPEN-SMART Rich Shield Lesson 10: Measure voltage and Display
* You can learn use the 4-digit tube to display the input voltage value you measure.
* The following functions are available:
* voltage.read();//read the voltage and return a floating-point value
* disp.init(); // initialization
* display(double Decimal);// display a floating-point value
* Example v 1.0
************************************************** **************************************************/
#include <Arduino.h>
#include <Wire.h>
#include "RichShieldVoltageSensor.h"
#include "RichShieldTM1637.h"

const int CLK = 10;//CLK of the TM1637 IC connect to D10 of OPEN-SMART UNO R3
const int DIO = 11;//DIO of the TM1637 IC connect to D11 of OPEN-SMART UNO R3
TM1637 disp(CLK,DIO);

const int VOL_SENOR = A3;//The SIG pin connects A3 pin of OPEN-SMART UNO R3
VoltageSensor voltage(VOL_SENOR);

void setup() {
  disp.init();//
}

void loop() {  
   float vol;
   vol = voltage.read();
   disp.display(vol);
   delay(1000);
}

