/************************************************* ************************************************** ******
* OPEN-SMART Rich Shield Lesson 6: Press key and debounce
* Learn about software debounce method to achieve the number increasing step by step.
*
* The following functions are available:
*
* key.get(); / / return is key number you pressed, if no pressed then return 0
*
* disp.init(); // initialization
* disp.display(int Decimal);   // display range: -999 ~ 9999
************************************************** ************************************************** *****/

#include <Wire.h>

#include "RichShieldKEY.h"
#include "RichShieldTM1637.h"

		
#define CLK 10//CLK of the TM1637 IC connect to D10 of OPEN-SMART UNO R3
#define DIO 11//DIO of the TM1637 IC connect to D11 of OPEN-SMART UNO R3
TM1637 disp(CLK,DIO);
	
#define KEY1_PIN 9//
#define KEY2_PIN 8//
Key key(KEY1_PIN,KEY2_PIN);

int count = 0;

void setup()
{
  disp.init();//The initialization of the display
  disp.display(count);//display counter number
}

void loop()
{
  int keynum;
  keynum = key.get();
  if(keynum == 1) //if you press K1
  {
    delay(10);//delay for 10ms
    if(key.get() == 1)//check it again
    {
      count++;
	  disp.display(count);
    }
	while(key.get() == 1);//Wait for the button to be released
  }
  
}

/*********************************************************************************************************
The end of file
*********************************************************************************************************/

