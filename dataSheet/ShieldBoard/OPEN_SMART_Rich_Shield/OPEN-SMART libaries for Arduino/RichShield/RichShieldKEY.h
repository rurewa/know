#ifndef _RICHSHIELD_KEY_H__
#define _RICHSHIELD_KEY_H__

#include <Arduino.h>


class Key{

private:

    uint8_t out[2];

public:

    Key(uint8_t K1_pin = 9, uint8_t K2_pin = 8)
    {
        out[0] = K1_pin;
		out[1] = K2_pin;
		for(uint8_t i=0; i < 2; i++){
          pinMode(out[i], INPUT);
          digitalWrite(out[i], HIGH);
		}
        
    }
    
    uint8_t get()                        
    {
      for(uint8_t i=0; i < 2; i++){
          if(!digitalRead(out[i])){
		  	delay(10);
		  	if(!digitalRead(out[i])) return i+1;
          }
		}
	  return 0;
    }
    uint8_t getLongPress()
    {
      for(unsigned int i=0; i < 2; i++){
          if(!digitalRead(out[i])){
		  	for(unsigned int j=0; j < 150; j++){
		  	delay(20);
		  	if(digitalRead(out[i])) return 0;
		  	}
			return i+1;
          }
		}
    }
};

#endif
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/