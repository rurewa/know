// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Балансирующий робот на mpu6050
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>
#include <Wire.h> // Библиотека шины IC2
#include <Adafruit_ADXL345_U.h> // Библиотека гироскопа
#include "DualVNH5019MotorShield.h" // Библиотека двигателей
// Объект гироскопа
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();
// Объект моторов
DualVNH5019MotorShield md;

float AccelX = 0;
float AccelY = 0;
float AccelZ = 0;


void setup(void) {
  pinMode(3, INPUT);
  pinMode(5, INPUT);
  pinMode(11, INPUT);
  pinMode(13, INPUT);
  md.init(); // Инициация двигателей
  Serial.begin(9600);
  /* Инициализация акселероментра */
  if(!accel.begin())   {
    /* Если нет связи с акселерометром */
    Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
    while(1);
  }
}

void loop(void) {
  /* Get a new sensor event */
  sensors_event_t accelEvent;
  accel.getEvent(&accelEvent);

  md.setM1Speed(-200); // Мотор 1
  md.setM2Speed(-200); // Мотор 2
  delay(100);
  md.setM1Speed(200); // Мотор 1
  md.setM2Speed(200); // Мотор 2
  delay(100);

  AccelX = accelEvent.acceleration.x;

  /*if ((AccelX > -7.5) && (AccelX < 2)) { // Back
    Serial.println("Back");
    md.setM1Speed(-200); // Мотор 1
    md.setM2Speed(-200); // Мотор 2
    delay(50);
    md.setM1Speed(200); // Мотор 1
    md.setM2Speed(200); // Мотор 2
    delay(50);
  }
  else if ((AccelX < -7.5) && (AccelX > -16)) { // Forward
    Serial.println("Forward");
    md.setM1Speed(200); // Мотор 1
    md.setM2Speed(200); // Мотор 2
    delay(50);
    md.setM1Speed(-200); // Мотор 1
    md.setM2Speed(-200); // Мотор 2
    delay(50);
  }

  else {
    Serial.println("Stop");
    md.setM1Speed(0); // Мотор 1
    md.setM2Speed(0); // Мотор 2
  }

  Serial.print(AccelX);
  Serial.print("  | ");
  delay(1000);*/
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //