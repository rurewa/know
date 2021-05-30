/************************************************* *************************************************
* OPEN-SMART Rich Shield Lesson 3:  Light Sensor
* You can learn how to know the ambient light is dark or bright.  And display illuminance on the digital tube.
*
* The following functions are available:
*
* lightsensor.getRes();//it return the resistance of the light sensor, the darker the ambient light, the larger the resistance.
*
************************************************** ************************************************** *****/
#include <math.h>
#include <Wire.h>

#include "RichShieldLightSensor.h"
#include "RichShieldTM1637.h"
	
#define CLK 10//CLK of the TM1637 IC connect to D10 of OPEN-SMART UNO R3
#define DIO 11//DIO of the TM1637 IC connect to D11 of OPEN-SMART UNO R3
TM1637 disp(CLK,DIO);

#define LIGHTSENSOR_PIN A2//SIG pin of Rocker Switch module connect to A0 of IO Shield, that is pin A2 of OPEN-SMART UNO R3
LightSensor lightsensor(LIGHTSENSOR_PIN);

void setup() {
  Serial.begin(9600); //Set baud rate of serial port to be 9600bps, burn the program and open the serial monitor 
                     //on the upper right corner of Arduino IDE to check the sensor data.
  disp.init();//The initialization of the display
  
}
void loop() {
  float Rsensor = lightsensor.getRes();//if Rsensor is larger than 40 KOhm, the ambient light is very dark.
                                       //if Rsensor is smaller than 10 KOhm, the ambient light is bright.
  Serial.println("The resistance of the Light sensor is "); 
  Serial.print(Rsensor,1);
  Serial.println(" KOhm");
  
  float lux;
  lux = 325*pow(Rsensor,-1.4);
  disp.display(lux);//Illuminance
  
  Serial.print("Illuminance is almost "); // may be it is not exactly right
  Serial.print(lux,1);
  Serial.println(" lux");
  delay(1000);  
}


/*********************************************************************************************************
The end of file
*********************************************************************************************************/
