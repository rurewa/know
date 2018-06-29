#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// transmitter
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";
char xyData[32] = "";
String xAxis, yAxis;

void setup() 
{
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() 
{
  
  xAxis = analogRead(A0); // Считываем покаания по X
  yAxis = analogRead(A1); // Считываем показания по Y
  // Значение по Х
  xAxis.toCharArray(xyData, 5); // Переводим значения X в массив символов
  radio.write(&xyData, sizeof(xyData)); // Отправляем данные массива X в другой модуль NRF24L01
  // Значение по Y
  yAxis.toCharArray(xyData, 5);
  radio.write(&xyData, sizeof(xyData));
  delay(20);
}
