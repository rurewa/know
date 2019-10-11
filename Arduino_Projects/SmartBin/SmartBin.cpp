// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// SmartBin. Умная коробка для мусора
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include<Servo.h>
#include<NewPing.h>

Servo myservo;
const int trig = 4;
const int echo = 6;

NewPing sonar(trig, echo, 100);

void setup() {
  myservo.attach(9);
  pinMode(trig, OUTPUT);
  Serial.begin(9600);  
}

void loop() {
  int val = sonar.ping_cm();
  if (val < 15) {
    myservo.write(180);
  }
  else {
    myservo.write(10);
  }
  Serial.println(sonar.ping_cm());
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
