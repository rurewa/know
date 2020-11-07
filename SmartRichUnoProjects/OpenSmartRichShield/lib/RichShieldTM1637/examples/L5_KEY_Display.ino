/************************************************* *************************************************
* OPEN-SMART Rich Shield Lesson 5: Press key and display
* You can learn about detecting keys, digital increase, reduce, clear operation of the digital display 
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
    count++;
  }
  else if(keynum == 2)//if you press K2
  {
    count--;
  }
 
  disp.display(count);
  delay(50);//
}

/*********************************************************************************************************
The end of file
*********************************************************************************************************/
