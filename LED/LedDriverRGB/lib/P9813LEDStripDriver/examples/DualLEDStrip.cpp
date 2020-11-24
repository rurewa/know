//Demo for LED Strip Driver controling dual RGB LED strip by Catalex
//Hardware:LED Strip Driver      *2
//          5 meters of RGB LED strip *2
//Board: Catduino or Arduino UNO R3 
//IDE:   Arduino-1.0
//Function: Cyclically display red, green and blue three colors with 
//          two LED Strip Driver and two RGB LED strip.
//Store: catalex.taobao.com
/***************************************************************/

#include "RGBdriver.h"
#define CIN 3//pins definitions for the driver        
#define DIN 2
RGBdriver Driver(CIN,DIN);

void setup()  
{ 

} 
void loop()  
{ 
  /*Function: SetColor()					          */
  /*Parameters: red:0~255 						    */
  /*            green:0~255						    */
  /*            blue:0~255						    */
  /*Note: the greater the value,the brighter the LED*/
  Driver.begin(); // begin
  Driver.SetColor(255, 0, 0); //Red. first LED strip
  Driver.SetColor(0, 0, 255); //Blue. second LED strip
  Driver.end();
  delay(500);
  Driver.begin(); // begin
  Driver.SetColor(0, 0, 255); //Blue. first LED strip
  Driver.SetColor(0, 255, 0); //Green. second LED strip
  Driver.end();
  delay(500);
  Driver.begin(); // begin
  Driver.SetColor(0, 255, 0); //Green. first LED strip
  Driver.SetColor(255, 0, 0); //Red. second LED strip
  Driver.end();
  delay(500);
}
