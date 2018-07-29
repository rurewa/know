// 16X2 1602A LCD Display with I2C & Sonar for Arduino dev board 2.0
// v 1.0
// UNO: SDA - A4, SCL - A5
// MEGA: SDA - pin20, SCL - pin21
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h> // Библиотека для работы с I2C экраном
#include <NewPing.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // Устанавливаем дисплей
const int trig = 14;
const int echo = 15;
NewPing sonar(trig, echo);

void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  lcd.init(); // Инициализация LCD
  lcd.backlight();// Включаем подсветку дисплея
  lcd.begin(16, 2);  // Задаем размерность экрана
}
void loop()
{
  Serial.println(sonar.ping_cm());
  // Отсылаем значения в LCD
  lcd.clear(); // Очищаем экран перед получением нового значения
  lcd.setCursor(2, 0); // курсор на 2-й символ 1-й строки
  lcd.print("Distantion:"); // Тест на 1-й строке экрана
  lcd.setCursor(7, 1); // курсор на 7-й символ 2-й строки
  lcd.print(sonar.ping_cm()); // Значения на 2-й строке экрана
  delay(30);
}
