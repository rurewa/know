/************************************************* ************************************************** ******
* OPEN-SMART Rich Shield Lesson 11: Temperature and humidity measurement and display
* Through the DHT11 measurement module to obtain the temperature and humidity, and display on the digital tube. 
*
* The following functions are available:
* dht.begin();//DHT11 initialization
* dht.readTemperature(); // get the temperature value, and return float-point number 
* dht.readHumidity(); // get the Humidity value, and return float-point number 

* displayTemperature(int8_t temperature); // display temperature, at the end of the value of the word added "C" is the degree of Celsius
* displayHumidity(int8_t humi); // display humidity, at the end of the value of the word added "H"

* disp.init(); // initialization
* disp.display(int8_t DispData []); // display the numbers in the array
* // For example, the array is {1,2,3,4}, then show 1234
************************************************** ************************************************** *****/

#include <Wire.h>

#include "RichShieldDHT.h"
#include "RichShieldTM1637.h"
#define CLK 10//CLK of the TM1637 IC connect to D10 of OPEN-SMART UNO R3
#define DIO 11//DIO of the TM1637 IC connect to D11 of OPEN-SMART UNO R3
TM1637 disp(CLK,DIO);

DHT dht;

void setup() {
	disp.init();  
	dht.begin();
}

void loop() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    displayError();
  } 
  else{
    displayTemperature((int8_t)t);//
    delay(3000);
    displayHumidity((int8_t)h);//
    delay(2000);
  }
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

void displayHumidity(int8_t humi)
{
  int8_t temp[4];
  if(humi < 100)temp[0] = INDEX_BLANK;
  else temp[0] = humi/100;
  humi %= 100;
  temp[1] = humi / 10;
  temp[2] = humi % 10;
  temp[3] = 18;	          //index of 'H' for celsius degree symbol.
  disp.display(temp);
}

void displayError()
{
  disp.display(3,14);//display "E"
}