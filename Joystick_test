const int VRx = 0;  // Ось X подключена к А0
const int VRy = 1;  // Ось Y подключена к А1
const int SWz = 2;  // Ось Z (кнопка) подключена к пин 2
// Объявляем переменные для хранения значений
int valueX; // Для VRx
int valueY; // Для VRy
int buttonZ = 0;  // Для SWz кнопки

void setup()  // Старт и настройка программы
{
  // Скорость передачи данных в монитор порта
  Serial.begin(9600);
  // Настраиваем пин 2 как ВХОД с подключением 
  // встроенного в Arduino подтягивающего резистора
  pinMode(SWz, INPUT_PULLUP);
}

void loop() // Основная программа. Цикл
{
  // Считываем в переменную значения с А0
  valueX = analogRead(VRx); 
  // Посылаем сообщение в монитор порта
  Serial.print("X: ");
  Serial.print(valueX, DEC);
  // Считываем в переменную значения с А1
  valueY = analogRead(VRy);
  // Посылаем сообщение в монитор порта
  Serial.print(" | Y: ");
  Serial.print(valueY, DEC);
  // Считываем в переменную значения с пин 2
  buttonZ = digitalRead(SWz);
  buttonZ = buttonZ ^ 1;
  // Посылаем сообщение в монитор порта
  Serial.print(" | SW: ");
  Serial.println(buttonZ, DEC);
  delay(1500);  // Задержка 1,5 секунды
}
