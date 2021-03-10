// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// Простая символьная волна на экране 1602 от потенциометра
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
#include <Arduino.h>
#include <LiquidCrystal_I2C.h> // Библиотека I2C дисплея

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Устанавливаем дисплей

// Определяем группу ячеек в массиве
const int CELL[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

byte cellOne[8] = { // Массив символа закрашенной ячейки
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

byte cellOff[8] = { // Массив символа незакрашенной ячейки
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

void setup() {
  Serial.begin(9600);
  // Экран 1602
  lcd.init(); // Инициализация LCD
  lcd.backlight();// Включаем подсветку дисплея
  lcd.begin(16, 2);  // Задаем размерность экрана (16 - ячеек, 2 - срок)
  lcd.clear(); // Очищаем экран перед получением нового значения
  lcd.createChar(0, cellOne);
  lcd.createChar(1, cellOff);
}

void loop() {
  lcd.setCursor(0, 1);
	lcd.write(byte(0));
  const int pinPot = A7; // Пин потенциометра
  int valPot = analogRead(pinPot); // Считываем с потенциометра
  int count_Cell = 0; // Для значений текущего числа от 0 до 16
  count_Cell = map (valPot, 0, 1023, 0, 16); // Масштабируем значения, поступаемые из потенциометра
  for (int i = 0; i <= 15; i++) { // Перечисляем от 0 до 16-и
    if (i < count_Cell) { // Если число перечисления < текущего
      lcd.setCursor(CELL[i], 0); // Ячейка из счётчика 1-й строки
      lcd.print("*"); // Выводим на экран звёздочки
      lcd.setCursor(CELL[i], 1); // Ячейка из счётчика 2-й строки
	    lcd.write(byte(0)); // Выводим на экран закрашенную ячейку
    }
    else {
      lcd.setCursor(CELL[i], 0); // Ячейка из счётчика 1-й строки
      lcd.print(" "); // Выводим на экран пробелы
      lcd.setCursor(CELL[i], 1); // Ячейка из счётчика 2-й строки
	    lcd.write(byte(1)); // Выводим на экран незакрашенную ячейку
    }
  }
  Serial.println(count_Cell); // Для диагностики
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
