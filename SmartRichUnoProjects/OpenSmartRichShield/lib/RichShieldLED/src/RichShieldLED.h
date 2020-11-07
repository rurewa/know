#ifndef _RICHSHIELD_LED_H__
#define _RICHSHIELD_LED_H__

#include <Arduino.h>


class LED{

private:

    uint8_t led[4];

public:

    LED(uint8_t led1=7, uint8_t led2=6, uint8_t led3=5, uint8_t led4=4)
    {
        led[0] = led1;
		led[1] = led2;
		led[2] = led3;
		led[3] = led4;
		for(unsigned int i=0; i < 4; i++){
          pinMode(led[i], OUTPUT);
          off(i+1);
		}
        
    }
	
   void on(uint8_t num)//num = 1, 2, 3, 4
   {
     if((num > 0) && (num < 5))
	 	digitalWrite(led[num-1], HIGH);
   }
   void off(uint8_t num)//num = 1, 2, 3, 4
   {
     if((num > 0) && (num < 5))
       digitalWrite(led[num-1], LOW);
   }
   
};

#endif
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/