#ifndef __RICHSHIELD_LIGHTSENSOR_H__
#define __RICHSHIELD_LIGHTSENSOR_H__

#include <Arduino.h>

class LightSensor{

private:

    uint8_t _pin;

public:

    LightSensor(uint8_t pin=A2)
    {
      _pin = pin;
      pinMode(_pin, INPUT);
    }
    
   float getRes()
   {
     int sensorValue = analogRead(_pin);
     float Rsensor;
     Rsensor=(float)(1023-sensorValue)*10/sensorValue;
	 return Rsensor;//unit is KOhm
   }
};

#endif
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/