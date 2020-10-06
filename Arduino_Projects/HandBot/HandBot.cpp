// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Рука робота. 8 - указательный, 9 - средний, 10 - большой.
// V 1.2
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

const int FREQUENCY = 60;

int pulseWidth(int angle);

void setup() {
  //Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
  // Разгибаем пальцы ладони в начале программы
  pwm.setPWM(8, 0, pulseWidth(0));
  pwm.setPWM(9, 0, pulseWidth(0));
  pwm.setPWM(10, 0, pulseWidth(0));
  delay(250);
}

void loop() {
  // Сгибаем пальцы
  for (int i = 0; i < 110; ++i) {
    pwm.setPWM(8, 0, pulseWidth(i));
    pwm.setPWM(9, 0, pulseWidth(i));
    pwm.setPWM(10, 0, pulseWidth(i));
    delay(15);
  }
  // Разгибаем пальцы
  for (int i = 110; i >= 0; --i) {
    pwm.setPWM(8, 0, pulseWidth(i));
    pwm.setPWM(9, 0, pulseWidth(i));
    pwm.setPWM(10, 0, pulseWidth(i));
    delay(15);
  }
  // Указываем
    pwm.setPWM(8, 0, pulseWidth(0));
    pwm.setPWM(9, 0, pulseWidth(110));
    pwm.setPWM(10, 0, pulseWidth(110));
    delay(2000);
  // Показываем большой палец
    pwm.setPWM(8, 0, pulseWidth(110));
    pwm.setPWM(9, 0, pulseWidth(110));
    pwm.setPWM(10, 0, pulseWidth(0));
    delay(2000);
}

int pulseWidth(int angle) {
  const int MIN_PULSE_WIDTH = 650;
  const int MAX_PULSE_WIDTH = 2350;
  int pulse_wide, analog_value;
  pulse_wide   = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  return analog_value;
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
