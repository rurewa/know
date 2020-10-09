// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// SmartBin. Умная коробка для мусора
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include<Servo.h>
#include<NewPing.h>

Servo myservo;
const int TRIG = 4;
const int ECHO = 6;

NewPing sonar(TRIG, ECHO, 100);

void setup() {
  myservo.attach(9);
  pinMode(TRIG, OUTPUT);
  Serial.begin(9600);  
}

void loop() {
  int val = sonar.ping_cm();
  if (val < 15) {
    myservo.write(180);
  }
  else {
    myservo.write(20);
    delay(1000);
  }
  Serial.println(sonar.ping_cm());
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
