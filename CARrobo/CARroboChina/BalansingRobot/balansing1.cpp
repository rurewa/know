// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Балансирующий робот на ADXL345
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>
#include <Wire.h> // Библиотека шины IC2
#include <Adafruit_ADXL345_U.h> // Библиотека гироскопа
#include "motor.h"

// Объект гироскопа
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();

float AccelX = 0;
float AccelY = 0;
float AccelZ = 0;

void axel_test();

void setup(void) {
  setup_motor_system(2, 4, 9, 7, 8, 10);
  Serial.begin(9600);
  /* Инициализация акселероментра */
  if(!accel.begin())   {
    /* Если нет связи с акселерометром */
    Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
    while(1);
  }
}

void loop(void) {
  /* Получаем новые данных с датчика */
  sensors_event_t accelEvent;
  accel.getEvent(&accelEvent);

  AccelX = accelEvent.acceleration.x;
  AccelY = accelEvent.acceleration.y;
  AccelZ = accelEvent.acceleration.z;
  //axel_test();
  if ((AccelX > -7.5) && (AccelX < -6)) { // Back
    Serial.println("Back");
    backward();
  }
  else if ((AccelX < -7.5) && (AccelX > -9)) { // Forward
    Serial.println("Forward");
    forward();
  }
  else {
    Serial.println("Stop");
    _stop();
  }
}

void axel_test() {
  Serial.print(AccelX);
  Serial.print(" | ");
  Serial.print(AccelY);
  Serial.print(" | ");
  Serial.println(AccelZ);
  delay(500);
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //