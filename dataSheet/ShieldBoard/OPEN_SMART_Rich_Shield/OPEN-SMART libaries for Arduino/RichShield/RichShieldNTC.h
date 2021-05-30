/*
    LM75 - An arduino library for the LM75 temperature sensor
    Copyright (C) 2011  Dan Fekete <thefekete AT gmail DOT com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _RICHSHIELD_NTC_h
#define _RICHSHIELD_NTC_h

#include <Arduino.h>

#define SAMPLING_RESISTOR	10000//the sampling resistor is 10k ohm
#define NTC_R25 10000//the resistance of the NTC at 25'C is 10k ohm
#define NTC_B   3950


class NTC {
    uint8_t _pin;
public:
	NTC(uint8_t sensor_pin=A1){_pin = sensor_pin;}
 
    float getTemperature()
    {
    	float temperature,resistance;
    	int a;
    	a = analogRead(_pin);
    	resistance   = (float)a*SAMPLING_RESISTOR/(1024-a); //Calculate the resistance of the thermistor
    	/*Calculate the temperature according to the following formula.*/
    	temperature  = 1/(log(resistance/NTC_R25)/NTC_B+1/298.15)-273.15;
    	return temperature;
    }

};

#endif
