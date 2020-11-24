//Demo for LED Strip Driver controling single RGB LED strip by Catalex
//Hardware: A LED Strip Driver and 5 meters of RGB LED strip
//Board: Carduino or Arduino UNO R3
//IDE:   Arduino-1.0
//Function: Show 7 colors with a single RGB LED.
//Store: catalex.taobao.com
/***************************************************************/
#include "RGBdriver.h"
#define CLK 3//pins definitions for the driver
#define DIO 2
RGBdriver Driver(CLK,DIO);

void setup() {

}
void loop()
{
  /*Function: SetColor()					          */
  /*Parameters: red:0~255 						    */
  /*            green:0~255						    */
  /*            blue:0~255						    */
  /*Note: the greater the value,the brighter the LED*/
  Driver.begin();
  Driver.SetColor(100, 0, 0); //Red
  Driver.end();
  delay(500);
  Driver.begin();
  Driver.SetColor(0, 100, 0); //Green
  Driver.end();
  delay(500);
  Driver.begin();
  Driver.SetColor(0, 0, 100);//Blue
  Driver.end();
  delay(500);
  Driver.begin();
  Driver.SetColor(100, 100, 0);//Yellow
  Driver.end();
  delay(500);
  Driver.begin();
  Driver.SetColor(0, 100, 100);//Cyan
  Driver.end();
  delay(500);
  Driver.begin();
  Driver.SetColor(100, 0, 100);//Magenta
  Driver.end();
  delay(500);
  Driver.begin();
  Driver.SetColor(100, 100, 100);//White
  Driver.end();
  delay(500);
  Driver.begin();
  Driver.SetColor(0, 0, 0);//all LED is off
  Driver.end();
  delay(500);
}
