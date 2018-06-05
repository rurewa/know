// 16X2 1602A LCD Display with I2C
// v 1.0
// UNO: SDA - A4, SCL - A5
// MEGA: SDA - pin20, SCL - pin21
#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // Устанавливаем дисплей

void setup()
{
  lcd.init();                     
  lcd.backlight();// Включаем подсветку дисплея
  lcd.print("Hello Word!");
  lcd.setCursor(8, 1); // 8-я ячейка, 2-я строка
  lcd.print("LCD 1602");
}
void loop()
{
  // Устанавливаем курсор на вторую строку и нулевой символ.
  lcd.setCursor(0, 1); // 0-я ячейка, чторая строка
  // Выводим на экран количество секунд с момента запуска ардуины
  lcd.print(millis()/1000);
}
