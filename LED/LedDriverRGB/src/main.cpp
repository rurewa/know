// Demo for LED Strip Driver controling single RGB LED strip by Catalex
// Hardware: A LED Strip Driver and 5 meters of RGB LED strip
// Board: Carduino or Arduino UNO R3
// IDE:   Arduino-1.0
// Function: Show 7 colors with a single RGB LED.
// Store: catalex.taobao.com
// Пример работы RGB-светодиодной ленты с драйвером. V 1.0
/***************************************************************/
#include "RGBdriver.h"

const int CLK = 3; // Pins definitions for the driver
const int DIO = 2;

RGBdriver Driver(CLK, DIO);

void setup() { }

void loop() {
  /* Function: SetColor()		*/
  /* Parameters: red:0~255 	*/
  /*            green:0~255	*/
  /*            blue:0~255	*/
  /* Note: the greater the value,the brighter the LED */
  Driver.begin(); // begin
  Driver.SetColor(255, 0, 0); //Red. first node data
  Driver.end();
  delay(500);
  Driver.begin(); // begin
  Driver.SetColor(0, 255, 0); //Green. first node data
  Driver.end();
  delay(500);
  Driver.begin(); // begin
  Driver.SetColor(0, 0, 255);//Blue. first node data
  Driver.end();
  delay(500);

  while(true) {
    for (int i = 0; i < 256; --i) {
      Driver.begin(); // begin
      Driver.SetColor(0,0,i); // Blue. First node data. SetColor(R,G,B)
      Driver.end();
      delay(10);
    }
    for (int i = 255; i > 0; --i) {
      Driver.begin(); // begin
      Driver.SetColor(0,0,i); // Blue. first node data
      Driver.end();
      delay(10);
    }
  }
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //