// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// https://github.com/adafruit/Adafruit-Motor-Shield-library
// Для экскаватора с lcd дисплеем
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

#include <Arduino.h>
#include <LiquidCrystal_I2C.h> // Библиотека I2C дисплея
#include <AFMotor.h>           // Фирменная библиотека Adafruit Motor Shield

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Устанавливаем дисплей

AF_DCMotor Motor1(1); // Объект мотора 2 из библиотеки
AF_DCMotor Motor3(3); // Объект мотора 3 из библиотеки
AF_DCMotor Motor4(4); // Объект мотора 4 из библиотеки

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

void RunMotor(int aPin, AF_DCMotor &aMotor, int aLine = -1, const char *aName = NULL) { 
  int __v = map(analogRead(aPin), 0, 1023, -127, 127);

  if (aLine > 0 && aName && *aName) {
    lcd.setCursor(0, aLine); // 0-я ячейка, 1-я строка
    lcd.print(aName);
    lcd.setCursor(10, aLine);
    lcd.print(__v);
    lcd.print("   ");
  }

  if (__v >= -10 && __v <= 10) aMotor.run(RELEASE);
  else if (__v > 11) aMotor.run(FORWARD), aMotor.setSpeed(__v);
  else if (__v < -11) aMotor.run(BACKWARD), aMotor.setSpeed(-__v);
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

void setup() {
  lcd.init();                     
  lcd.backlight();// Включаем подсветку дисплея
  Motor1.run(RELEASE);
  Motor3.run(RELEASE);
  Motor4.run(RELEASE);
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

void loop() {  
  RunMotor(A1, Motor1, 0, "Axis X");
  RunMotor(A2, Motor4, 1, "Axis Y");
  RunMotor(A3, Motor3);
}
