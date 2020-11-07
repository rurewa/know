/************************************************* ************************************************** ******
* OPEN-SMART Rich Shield Lesson 12: Test infrared remote keys 
*
* Learn how to get keys code of the buttons on the IR remote and display on the digital tube and serial monitor of Arduino IDE.
*
* The following functions are available:
* IR.enableIRIn(); // Start the receiver
* IR.decode();//if no result, it return 0, otherwise it return 1; .
* IR.resume(); // so that it can receive the next value
* IR.isReleased();//if the button is not released yet, it return 0; otherwise it return 1;
*********************************************************************************************************/

#include <Wire.h>

#include "RichShieldIRremote.h"
#include "RichShieldTM1637.h"

#define CLK 10//CLK of the TM1637 IC connect to D10 of OPEN-SMART UNO R3
#define DIO 11//DIO of the TM1637 IC connect to D11 of OPEN-SMART UNO R3
TM1637 disp(CLK,DIO);

#define RECV_PIN 2//the SIG pin of Infrared Receiver is connected with D2 of OPEN-SMART UNO R3
IRrecv IR(RECV_PIN);

void setup()
{
  Serial.begin(9600);
  disp.init();//The initialization of the display
  IR.enableIRIn(); // Start the receiver
}

void loop()
{
  if (IR.decode()) {//If a valid key code is detected

    if(IR.isReleased())//If it is not the repeat code for long press, then read out to display
	{
      Serial.print("user code is ");
      Serial.println(IR.usercode,HEX);
      Serial.print("key code is ");
      Serial.println(IR.keycode,HEX);
	  disp.display(2, IR.keycode>>4);//display the high digit of the hexadecimal number on the second tube
	  disp.display(3, IR.keycode&0x0f);//display the low digit of the hexadecimal number on the third tube
    }
    IR.resume(); //resume to receive again
  }
}


/*********************************************************************************************************
The end of file
*********************************************************************************************************/

