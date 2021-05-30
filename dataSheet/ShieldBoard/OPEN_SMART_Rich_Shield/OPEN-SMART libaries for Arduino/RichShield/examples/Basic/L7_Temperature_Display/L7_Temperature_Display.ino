/************************************************* ************************************************** ******
* OPEN-SMART Rich Shield Lesson 7: Temperature measurement and display
* Through the NTC temperature measurement module to obtain the temperature, and display on the digital tube. 
*
* The following functions are available:
* temper.getTemperature(); // get the temperature value, and return float-point number 
*
* displayTemperature(int8_t temperature); // display temperature, at the end of the value of the word added C is the degree of Celsius
*
* disp.init(); // initialization
* disp.display(int8_t DispData []); // display the numbers in the array
* // For example, the array is {1,2,3,4}, then show 1234
************************************************** ************************************************** *****/

#include <Wire.h>

#include "RichShieldTM1637.h"
#include "RichShieldNTC.h"

#define NTC_PIN A1 //SIG pin of NTC module connect to A1 of IO Shield, that is pin A1 of OPEN-SMART UNO R3
NTC temper(NTC_PIN);  

#define CLK 10//CLK of the TM1637 IC connect to D10 of OPEN-SMART UNO R3
#define DIO 11//DIO of the TM1637 IC connect to D11 of OPEN-SMART UNO R3
TM1637 disp(CLK,DIO);

void setup()
{
  disp.init();//The initialization of the display
  delay(1000);//
}

void loop()
{
  float celsius;
  celsius = temper.getTemperature();//get temperature
  displayTemperature((int8_t)celsius);//
  delay(1000);//delay 1000ms
}
/************************************************* *********************/
/* Function: Display temperature on 4-digit digital tube */
/* Parameter: -int8_t temperature, temperature range is -40 ~ 125 degrees celsius */
/* Return Value: void */

void displayTemperature(int8_t temperature)
{
  int8_t temp[4];
  if(temperature < 0)
	{
		temp[0] = INDEX_NEGATIVE_SIGN;
		temperature = abs(temperature);
	}
	else if(temperature < 100)temp[0] = INDEX_BLANK;
	else temp[0] = temperature/100;
	temperature %= 100;
	temp[1] = temperature / 10;
	temp[2] = temperature % 10;
	temp[3] = 12;	          //index of 'C' for celsius degree symbol.
	disp.display(temp);
}
/*********************************************************************************************************
The end of file
*********************************************************************************************************/

