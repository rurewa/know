// Joystick test with LCD 1602-I2C 
// V 1.0
// 16X2 1602 LCD Display with I2C 
// UNO: SDA - A4, SCL - A5
// MEGA: SDA - pin20, SCL - pin21

#include <Wire.h> // Библиотека для устройств I2C
#include <LiquidCrystal_I2C.h> // Библиотека для ЖК с I2C
/* Устанавливаем ЖК-дисплей 0x27 для 16-ти символьного
и 2-строчного дисплея */
LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  // Скорость передачи данных в монитор порта
  Serial.begin(9600);
  // Настраиваем пин 2 как ВХОД с подключением 
  // встроенного в Arduino подтягивающего резистора
  pinMode(2, INPUT_PULLUP);
  lcd.init(); // Инициализация LCD                    
  lcd.backlight();// Включаем подсветку дисплея
  lcd.begin(16, 2);  // Задаем размерность экрана
}

void loop()
{
  int valueX = map(analogRead(A0), 0, 1024, -256, 255);
  int valueY = map(analogRead(A1), 0, 1024, -256, 255);
  int buttonZ = digitalRead(2);
  buttonZ = !buttonZ;
  lcd.clear(); // Очищаем экран перед получением нового значения
  lcd.setCursor(0, 0); // курсор на 0-й символ 1-й строки
  lcd.print("VALUE X:"); // Тест на 1-й строке экрана
  lcd.setCursor(9, 0); // курсор на 9-й символ 1-й строки
  lcd.print(valueX); // Значение на 2-й строке экрана
  lcd.setCursor(0, 1); // курсор на 0-й символ 2-й строки
  lcd.print("VALUE Y:"); // Тест на 2-й строке экрана
  lcd.setCursor(9, 1); // курсор на 9-й символ 2-й строки
  lcd.print(valueY); // Значение на 2-й строке экрана
  lcd.setCursor(14, 0); // курсор на 1-й символ 1-й строки
  lcd.print("S"); // Тест на 1-й строке экрана
  lcd.setCursor(15, 0); // курсор на 15-й символ 2-й строки
  lcd.print(buttonZ); // Значение на 1-й строке экрана
  delay(50);
}
