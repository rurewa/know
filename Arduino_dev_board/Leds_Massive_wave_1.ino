// Arduino_dev_board v 1.0
// Massive leds wave
// V 1.0
int timer = 100;
// Массив с номерами пинов
int ledPins[] = {8, 9, 10, 11, 12};
int pinCount = 5; // Длина массива

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
   // Итерации (повторения) от наименьшего к большему
   for (int thisPin = 0; thisPin < pinCount; thisPin++)
   {
       digitalWrite(ledPins[thisPin], HIGH);
       delay(timer);
       digitalWrite(ledPins[thisPin], LOW);
   }
   // Итерации (повторения) от наибольшего к меньшему
   for (int thisPin = pinCount -1; thisPin >=0; thisPin--)
   {
       digitalWrite(ledPins[thisPin], HIGH);
       delay(timer);
       digitalWrite(ledPins[thisPin], LOW);
   }
}
