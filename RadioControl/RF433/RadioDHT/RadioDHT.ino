// Библиотеку для работы с датчиками серии DHT скачивать с https://github.com/amperka/TroykaDHT
// Библиотеку для работы с радиомодулями скачиваем с сайта: https://iarduino.ru/file/280.html
#include <TroykaDHT.h>
#include <iarduino_RF433_Transmitter.h>   // Подключаем библиотеку для работы с передатчиком
#include <iarduino_RF433_Receiver.h>    // Подключаем библиотеку для работы с приёмником

DHT dht(2, DHT11);    // указываем пин датчика и тип сенсора (DHT11, DHT21, DHT22)
iarduino_RF433_Transmitter radioTX(4);    // Создаём объект radioTX с указанием пина передатчика
iarduino_RF433_Receiver    radioRX(3);    // Создаём объект radioRX с указанием пина приёмника
int trans[2];   // Создаём переменную для передачи данных
int rec[2];   // Создаём переменную для приёма данных
     
void setup() {
  Serial.begin(9600);    // открываем последовательный порт для мониторинга действий в программе
  dht.begin();
  radioTX.begin(1000);    // Устанавливаем скорость передачи данных
  radioTX.openWritingPipe(5);   // Открываем канал для передачи данных (значение может быть от 0 до 7)
  radioRX.begin(1000);    // Устанавливаем скорость приёма данных
  radioRX.openReadingPipe(5);   // Открываем канал для приёма данных (значение может быть от 0 до 7)
  radioRX.startListening();   // Начинаем приём данных
}
     
void loop() {
  dht.read();    // считывание данных с датчика
  switch(dht.getState()) {    // проверяем состояние данных
    case DHT_OK:    // выводим показания влажности и температуры
      trans[0] = dht.getTemperatureC();
      radioTX.write(&trans, sizeof(trans));   // Отправляем данные с указанием размера пачки
      trans[1] = dht.getHumidity();
      radioTX.write(&trans, sizeof(trans));   // Отправляем данные с указанием размера пачки
  }
  delay (200);

  if(radioRX.available()) {    // Если приёмник получил данные
    radioRX.read(&rec, sizeof(rec));    // Читаем полученные данные с указанием размера пачки
    Serial.print("Температура = ");   // Выводим температуру на экран
    Serial.print(rec[0]);
    Serial.println(" C");
    Serial.print("Влажность = ");   // Выводим влажность на экран
    Serial.print(rec[1]);
    Serial.println("% \n");
  }
  delay (1000);
}
