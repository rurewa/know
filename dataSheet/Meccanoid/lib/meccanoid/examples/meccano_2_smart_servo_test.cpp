/* Meccano Arduino library required
 *  http://www.meccano.com/meccanoid-opensource
 *
 *  Demo for 2 smart servos hooked to pin 5.
 *  LeRoy Miller, 2017
 *  Feel Free to use this for whatever.
 */
#include <Arduino.h>
#include "MeccaBrain.h"

MeccaBrain servo(5);

/*   setServoColor(int servoNum, byte color)  ->  sets the color of the Meccano Smart Servo module
The byte SERVONUM refers to the order of the servo in the chain.  The first servo plugged into your Arduino is 0.
The next servo is 1.  The third servo is 2.   The last servo in a chain of 4 servos is 3.

The byte COLOR is a value  0xF0 - 0xF7 which has 8 possible colors (including all off and all on)
 0xF7  =  R, G,B – all On
 0xF6  =  G, B  - On;   R – Off
 0xF5  =  R, B  - On;   G – Off
 0xF4  =  B  - On;   R, G – Off
 0xF3  =  R,G – On;   B - Off
 0xF2  =  G  - On;   R, B – Off
 0xF1  =  R – On,   G, B – Off
 0xF0  =  R, G,B  – all Off

For example, if you want to set the servo at position 0 to Red and the servo at position 2 to Blue-Green, you would send the following two commands
setServoColor(0,0xF1)
setServoColor(2,0xF6)

setServoPosition(int servoNum, byte pos)  ->   sets a specific servo to a certain position
The byte SERVONUM refers to the order of the servo in the chain.  The first servo plugged into your Arduino is 0.
The next servo is 1.  The third servo is 2.   The last servo in a chain of 4 servos is 3.

The byte POS refers to the servo position  0x00 - 0xEF, which equals to a full 180 degree range.
0x00 = full clockwise
0xEF = full counter clockwise
*/

//A STEP of 20 causes problems, it appears the servos need more power
#define STEP 1
/*This changes how fast the servo moves by changing how far it moves on each loop.
 * It has less to do with speed and more to do with position of the servo.
 * If you see weird issues, or your servos don't change color you probably
 * have a power issue.
 */

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
 pinMode(16, OUTPUT);

 for (int i=0; i<51; i++) {
   servo.communicate();
}

}

void loop(){
  servo.communicate();
  servo.setServoColor(0, 0xF4);
  servo.setServoColor(1, 0xF2);

 for (int i=0; i<239; i = i+ STEP) {
servo.communicate();
    servo.setServoPosition(0,  i);
    servo.setServoPosition(1, 239 - i);
 }

  servo.communicate();
  servo.setServoColor(1, 0xF4);
  servo.setServoColor(0, 0xF2);

 for (int i=239; i>0; i= i-STEP) {
  servo.communicate();
  servo.setServoPosition(0, i);
  servo.setServoPosition(1, 239 - i);

 }
}









