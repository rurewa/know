// Blink_through_millis_static.ino
// V 1.0

void blink() 
{
  // static меняет время жизни переменной на время работы программы
  static unsigned long blink_time = millis();
  if (millis() >= blink_time) 
  {       // настало ли время мигнуть
    digitalWrite(9, !digitalRead(9));  // выключаем/включаем LED на 3,5 сек. 
    blink_time = millis() + 100;      // задаём время следующего переключения
  }
}

void setup() 
{
  pinMode(9, OUTPUT);
}
 
void loop() 
{ 
  blink();
}
