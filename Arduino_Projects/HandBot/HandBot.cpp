// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Рука робота
// V 1.1
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH       650
#define MAX_PULSE_WIDTH       2350
//#define DEFAULT_PULSE_WIDTH   1500
#define FREQUENCY             60
// our servo # counter
uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
}

int pulseWidth(int angle) {
  int pulse_wide, analog_value;
  pulse_wide   = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  return analog_value;
}

void loop() {
  for (int i = 0; i < 110; ++i) {
    pwm.setPWM(8, 0, pulseWidth(i));
    pwm.setPWM(9, 0, pulseWidth(i));
    pwm.setPWM(10, 0, pulseWidth(i));
    delay(30);
  }
  for (int i = 110; i >= 0; --i) {
    pwm.setPWM(8, 0, pulseWidth(i));
    pwm.setPWM(9, 0, pulseWidth(i));
    pwm.setPWM(10, 0, pulseWidth(i));
    delay(30);
  }
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //