#ifndef __RICHSHIELD_PassiveBUZZER_H__
#define __RICHSHIELD_PassiveBUZZER_H__

#include <Arduino.h>


class PassiveBuzzer{

private:

    uint8_t _pin;

public:

    PassiveBuzzer(uint8_t pin=3)
    {
      _pin = pin;
      pinMode(_pin, OUTPUT);
      off();
    }
	void playTone(long note, long millisecond) {
		long frequency = note; 
		long length = millisecond;
		if(frequency > 0){
    	long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
    	//// 1 second's worth of microseconds, divided by the frequency, then split in half since
    	//// there are two phases to each cycle
    	long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
    	//// multiply frequency, which is really cycles per second, by the number of seconds to
    	//// get the total number of cycles to produce
    	for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
        	digitalWrite(_pin, HIGH); // write the buzzer pin high to push out the diaphram
        	delayMicroseconds(delayValue); // wait for the calculated delay value
        	digitalWrite(_pin, LOW); // write the buzzer pin low to pull back the diaphram
        	delayMicroseconds(delayValue); // wait again or the calculated delay value
    	}
		}
		else delay(millisecond);
	}
    inline void off()                        
    {
      digitalWrite(_pin, LOW);
    }
};

#endif
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/