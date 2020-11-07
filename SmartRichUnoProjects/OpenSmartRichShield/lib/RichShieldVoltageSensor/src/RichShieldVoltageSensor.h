#ifndef _RICHSHIELD_VoltageSensor_H__
#define _RICHSHIELD_VoltageSensor_H__

#include <Arduino.h>
#define GAIN 0.18// Vread = VIN * GAIN
#define ADC_REF 5  //reference voltage of ADC is 5v


class VoltageSensor{

private:

    uint8_t _pin;
    uint8_t samples;  //The number of sampling
public:

    VoltageSensor(uint8_t pin = A3)
    {
      _pin = pin;  
	  samples = 10;  //The number of sampling
    }
	float read()
    {
      int sensorValue;
      long  sum=0;
      for(uint8_t i = 0;i < samples;i ++)
      {  
        sensorValue=analogRead(_pin);
        sum += sensorValue;
        delay(2);
      }   
      sensorValue = sum / samples;//Calculate the average
      float vol = sensorValue*ADC_REF/1023.00/GAIN;
	  return vol;
    }
};

#endif
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/