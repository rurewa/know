
/* Meccano Arduino library required
 *  http://www.meccano.com/meccanoid-opensource
 *  
 *  Demo for smart LEDs hooked to pin 5.
 *  LeRoy Miller, 2017
 *  Feel Free to use this for whatever.
 *  based in part from work found here:
 *  https://gist.github.com/jamesotron/766994
 */


/*    setLEDColor(byte red, byte green, byte blue, byte fadetime)  ->  sets the color and transition/fade time of the Meccano Smart LED module
The bytes RED, GREEN and BLUE  should have a value from 0 - 7   =  a total of 512 options.
There are 8 levels of brightness for each color where 0 is OFF and 7 is full brightness.

The byte FADETIME should have a value from 0 - 7.   
These are preset time values to transition between the current color to the new color.
The bytes are as such:
0 -  0 seconds (no fade, change immediately)
1 -  200ms   (very very fast fade)
2 -  500ms   (very fast fade)
3 -  800ms  (fast fade)
4 -  1 second (normal fade)
5 -  2 seconds (slow fade)
6  - 3 seconds (very slow fade)
7 -  4 seconds  (very very slow fade)

   end  */

#include "MeccaBrain.h"

MeccaBrain led(5);

unsigned int rgbColor[3];

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(5, OUTPUT);

 for (int i=0; i<15; i++) {
led.communicate();
}

}

void loop() {
  // put your main code here, to run repeatedly:

for (int fade=0; fade<8; fade++) {
rgbColor[0] = 255;
rgbColor[1] = 0;
rgbColor[2] = 0;

  for (int decColour = 0; decColour < 3; decColour += 1) {
    int incColour = decColour == 2 ? 0 : decColour + 1;

    // cross-fade the two colours.
    for(int i = 0; i < 255; i += 1) {
      rgbColor[decColour] -= 1;
      rgbColor[incColour] += 1;
      led.communicate();
      led.setLEDColor(rgbColor[0], rgbColor[1], rgbColor[2], fade);
      //delay(5);
    }
  }
}
}
