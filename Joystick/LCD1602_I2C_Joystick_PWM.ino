// LCD1602 I2C Joystick PWM
// V 1.0
#include <Wire.h> // Библиотека для устройств I2C
#include <LiquidCrystal_I2C.h> // Библиотека для ЖК с I2C
/* Устанавливаем ЖК-дисплей 0x27 для 16-ти символовольного
и 2-строчного дисплея */
LiquidCrystal_I2C lcd(0x27,16,2);
const int VRx = 0;
int val = 0;


void setup()
{
    Serial.begin(9600);
    lcd.init(); // Инициализация LCD
    lcd.backlight();// Включаем подсветку дисплея
    lcd.begin(16, 2);  // Задаем размерность экрана
}

void loop()
{
    val = map (analogRead(VRx), 0, 1023, -255, 255); // Преобразуем их в ШИМ-диапазон
    int uS2 = val;
    Serial.print("PWM: ");
    Serial.println(val); // Отсылаем значения в монитор порта
    lcd.clear(); // Очищаем экран перед получением нового значения
    lcd.setCursor(4, 0); // курсор на 4-й символ 1-й строки
    lcd.print("PWM"); // Тест на 1-й строке экрана
    lcd.setCursor(7, 1); // курсор на 7-й символ 2-й строки
    lcd.print(uS2); // Значения на 2-й строке экрана
    delay(100);
}
