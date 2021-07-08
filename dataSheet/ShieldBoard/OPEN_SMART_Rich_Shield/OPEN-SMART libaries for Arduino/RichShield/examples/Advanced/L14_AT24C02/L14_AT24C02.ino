/************************************************* ************************************************** ******
* OPEN-SMART Rich Shield Lesson 14: AT24C02 
* Learn how to write and read byte form AT24C02 EEPROM and display data byte on the serial monitor of Arduino IDE.
*
* The following functions are available:
* AT24C02.begin();//it run wire.begin.
* AT24C02.read(int data_addr, byte address=0x57);//0x57 is the I2C slave address of AT24C02 onboard.
                                                                       //read the byte from address of data_addr of AT24C02
* AT24C02.write(byte data_addr, byte data, byte address=0x57);//0x57 is the I2C slave address of AT24C02 onboard.
                                                                         //write "data" to the address of data_addr of AT24C02

*********************************************************************************************************/
#include <Wire.h>
#include "RichShieldEEPROM.h"
eeprom AT24C02;

void setup() {
  AT24C02.begin();
  Serial.begin(9600);

  for(int addr = 0; addr < 10; addr++) {
    AT24C02.write(addr, 10+addr);
    delay(100);
  }

  Serial.println("Have writen to memory!");

  for(int addr = 0; addr < 10; addr++) {
    byte r = AT24C02.read(addr);
	Serial.print("address = ");
    Serial.print(addr);
    Serial.print(" - ");
	Serial.print("number = ");
    Serial.print(r);
    Serial.print("\n");
    delay(1000);
  }
  Serial.println("Have read 10 number from AT24C02!");
}

void loop() {
  
}
