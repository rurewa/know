#include <Arduino.h>
// 16X2 1602A LCD Display with I2C witch POT end motor
// v 1.0
// UNO: SDA - A4, SCL - A5
// MEGA: SDA - pin20, SCL - pin21
#include <Arduino.h>
#include <LiquidCrystal_I2C.h> // Библиотека для работы с I2C экраном
LiquidCrystal_I2C lcd(0x27,16,2);  // Устанавливаем дисплей
const int pot = 1;
const int motor = 3;
int val;
int valPWM;

void setup()
{
  Serial.begin(9600);
  lcd.init(); // Инициализация LCD
  lcd.backlight();// Включаем подсветку дисплея
  lcd.begin(16, 2);  // Задаем размерность экрана*/
  pinMode(3, OUTPUT); // Motor
}
void loop()
{
  val = analogRead(pot);
  valPWM = analogRead(pot);
  valPWM = map(valPWM, 0, 1023, 0, 254); // Преобразуем значения в ШИМ
  analogWrite(motor, valPWM); // Управляем мотором
  // Отсылаем значения в монитор порта
  Serial.print("Analog ");
  Serial.print(val);
  Serial.print(" PWM: ");
  Serial.println(valPWM);
  // Отсылаем значения в LCD
  lcd.clear(); // Очищаем экран перед получением нового значения
  lcd.setCursor(0, 0); // курсор на 4-й символ 1-й строки
  lcd.print("Analog:"); // Тест на 1-й строке экрана
  lcd.setCursor(9, 0); // курсор на 7-й символ 2-й строки
  lcd.print(val); // Значения на 2-й строке экрана
  lcd.setCursor(0, 1); // курсор на 4-й символ 1-й строки
  lcd.print("PWM:"); // Тест на 1-й строке экрана
  lcd.setCursor(9, 1); // курсор на 7-й символ 2-й строки
  lcd.print(valPWM); // Значения на 2-й строке экрана
  delay(100);
}
