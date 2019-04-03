// Arduino_dev_board v 1.0
// Massive whitch PWM fade brightness
// V 1.0
// Массив с номерами пинов (8 и 12 без ШИМ!)
int ledPins[] = {8, 9, 10, 11, 12};
int pinCount = 5; // Длина массива
int brightness = 0;
int fadeAmount = 3;

void setup() 
{
    // Элементы массива нумеруются от 0 до 4 или (pinCount -1)
    for (int thisPin = 0; thisPin < pinCount; thisPin++)
    {
        // Используем оператор for для определения
        // пинов как ВЫХОД
        pinMode(ledPins[thisPin], OUTPUT);
    }
}

void loop() 
{
    for (int thisPin = 0; thisPin < pinCount; thisPin++)
    {
       // Устанавливаем яркость пинов
       analogWrite(ledPins[thisPin], brightness);
       // Изменение яркости
       brightness = brightness + fadeAmount;
       // Изменение значения затухания на аналогичное
       // с противоположным знаком
       if (brightness == 0 || brightness == 255) 
        {
        fadeAmount = -fadeAmount;
        }
    }    
// задержка в 30 для отслеживания эффекта затухания
delay(100);
}
