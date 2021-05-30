#ifndef _RICHSHIELD_EEPROM_h

#define _RICHSHIELD_EEPROM_h

#include <Arduino.h>
#include <Wire.h>



class eeprom {
    uint8_t _pin;
public:
	eeprom() {};
    
    void begin(){Wire.begin();}
	void write(byte data_addr, byte data, byte address=0x57) {
	  Wire.beginTransmission(address);
	  Wire.write(data_addr);
	  Wire.write(data);
	  Wire.endTransmission();
	}

	byte read(int data_addr, byte address=0x57) {
    Wire.beginTransmission(address);
    Wire.write(data_addr);
    Wire.endTransmission();
  
    Wire.requestFrom(address, 1);
    if(Wire.available())
      return Wire.read();
    else
      return 0xFF;
   }
};

#endif
