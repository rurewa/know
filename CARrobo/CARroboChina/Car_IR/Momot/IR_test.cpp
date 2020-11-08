// Подключение библиотеки IRremote.h.
#include <IRremote.h> //Подключаем глобально библиотеку из Arduino IDE.
//#include "IRremote.h" // Подключаем локально библиотеку из текущего каталога
// Порт Arduino для приемника.
int RECV_PIN = 7;
//Создаем объект IR-приемник.
IRrecv irrecv(RECV_PIN);
//Создаем структуру результата приема данных IR-канала.
decode_results results;
void setup()
{
  // Устанавливаем скорость порта связи с ПК.
  Serial.begin(9600);
  // Запуск IR-приемника.
  irrecv.enableIRIn(); 
}
void loop() {
  // Если пришли данные. 
  if (irrecv.decode(&results)) {
    // Послать полученные данные на ПК в 16-ом представлении.
    Serial.println(results.value, HEX);
    //Готов к приему.
    irrecv.resume(); 
  }
  delay(100);
}

