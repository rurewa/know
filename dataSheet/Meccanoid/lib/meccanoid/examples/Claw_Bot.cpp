#include "MeccaBrain.h"

MeccaBrain servo(5);
 
const int TRIG_PIN = 3;
const int ECHO_PIN = 4; 
 
void setup() {
  // initialize serial communication:
  Serial.begin(9600);
 
  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
}
 
void loop(){
  servo.communicate();

  long duration, distanceCm, distanceIn;
 
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN,HIGH);
 
  // convert the time into a distance
  distanceCm = duration / 29.1 / 2 ;
  distanceIn = duration / 74 / 2;
 
  if (distanceCm <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distanceIn);
    Serial.print("in, ");
    Serial.print(distanceCm);
    Serial.print("cm");
    Serial.println();
  }

  if(distanceIn > 3){
    servo.setServoPosition(0,0xF0);
    servo.setServoPosition(1,0x00);
    
  }else if(distanceIn <= 3){
    servo.setServoPosition(0,0x7F);
    servo.setServoPosition(1,0x90);
  }

  delay(500);
}









