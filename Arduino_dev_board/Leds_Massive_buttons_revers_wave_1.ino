// Arduino_dev_board v 1.0
// Massive buttons revers wave leds 1
// V 1.0
int ledPins[] = {8, 9, 10, 11, 12};
int pinCount = 5; // Длина массива
const int inPin1 = 7;
const int inPin2 = 6;
int val1;
int val2;
int timer = 50;

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
    /* 
   Если значение нажатой кнопки больше 700, 
   то 1 (HIGH), иначе 0 (LOW)
    */
   val1 = analogRead(inPin1) > 700 ? HIGH : LOW;
   val2 = analogRead(inPin2) > 700 ? HIGH : LOW;
   if (val1 != LOW) // Влево
   {
       for (int thisPin = 0; thisPin < pinCount; thisPin++)
        {
            digitalWrite(ledPins[thisPin], HIGH);
            delay(timer);
            digitalWrite(ledPins[thisPin], LOW);
        }
   }
   else if (val2 != LOW) // Вправо
   {
       for (int thisPin = pinCount -1; thisPin >=0; thisPin--)
        {
            digitalWrite(ledPins[thisPin], HIGH);
            delay(timer);
            digitalWrite(ledPins[thisPin], LOW);
        }
   }
   else
   {
       for (int thisPin = 0; thisPin < pinCount; thisPin++)
        {
            digitalWrite(ledPins[thisPin], LOW);
        }
   }
}
