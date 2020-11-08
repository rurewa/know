// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Робот с использованием L298P Motor Shield от Keyes управляемый Bluetooth
// и джойстиком
// Код приёмника
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

int E1 = 10;      // Motor A1
int M1 =  12;     // Motor A2 (left motor)
int E2 =  11;     // Motor B1
int M2 =  13;     // Motor B2 (right motor)
int SPEED = 200;  // Speed PWM 0 - 255

int xAxis, yAxis;
unsigned int  x = 0;
unsigned int  y = 0;
int motorSpeedA = 0;
int motorSpeedB = 0;

void setup() {
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  Serial.begin(38400); // Default communication rate of the Bluetooth module
}
void loop() {
  // Значение по умолчанию - отсутствие движения, когда джойстик остается в центре
  x = 510 / 4;
  y = 510 / 4;
  // Прочитайте входящие данные с джойстика или основного устройства Bluetooth
  while (Serial.available() >= 2) {
    x = Serial.read();
    delay(10);
    y = Serial.read();
  }
  delay(10);
  // Преобразуйте диапазон 0 - 255 в 0 - 1023, подходящий для кода управления двигателем ниже
  xAxis = x*4;
  yAxis = y*4;
  // Y-axis used for forward and backward control
  if (yAxis < 470) {
    // Set Motor A backward
    digitalWrite(M1, LOW);
    // Set Motor B backward
    digitalWrite(M2, LOW);
    // Преобразование уменьшающихся показаний оси Y для перехода назад от 470 в 0 в значение от 0 до 255 для сигнала ШИМ для увеличения скорости двигателя
    motorSpeedA = map(yAxis, 470, 0, 0, 255);
    motorSpeedB = map(yAxis, 470, 0, 0, 255);
  }
  else if (yAxis > 550) {
    // Set Motor A forward
    digitalWrite(M1, HIGH);
    // Set Motor B forward
    digitalWrite(M2, HIGH);
    // Преобразование увеличенных показаний оси Y для перехода от 550 до 1023 в значение от 0 до 255 для сигнала ШИМ для увеличения скорости двигателя
    motorSpeedA = map(yAxis, 550, 1023, 0, 255);
    motorSpeedB = map(yAxis, 550, 1023, 0, 255);
  }
  // Если джойстик находится в середине, двигатели не двигаются
  else {
    motorSpeedA = 0;
    motorSpeedB = 0;
  }
  // Ось X используется для управления левым и правым
  if (xAxis < 470) {
    // Преобразование уменьшающихся показаний по оси X от 470 до 0 в значение от 0 до 255
    int xMapped = map(xAxis, 470, 0, 0, 255);
    // Перемещение влево - уменьшение скорости левого двигателя, увеличение скорости вращения вправо
    motorSpeedA = motorSpeedA - xMapped;
    motorSpeedB = motorSpeedB + xMapped;
    // Confine the range from 0 to 255
    if (motorSpeedA < 0) {
      motorSpeedA = 0;
    }
    if (motorSpeedB > 255) {
      motorSpeedB = SPEED;
    }
  }
  if (xAxis > 550) {
    // Преобразование увеличенных показаний оси Х от 550 до 1023 в значение от 0 до 255
    int xMapped = map(xAxis, 550, 1023, 0, 255);
    // Двигайтесь вправо - уменьшите правую скорость двигателя, увеличьте левую скорость двигателя
    motorSpeedA = motorSpeedA + xMapped;
    motorSpeedB = motorSpeedB - xMapped;
    // Confine the range from 0 to 255
    if (motorSpeedA > 255) {
      motorSpeedA = SPEED;
    }
    if (motorSpeedB < 0) {
      motorSpeedB = 0;
    }
  }
  // Не допускайте жужжания на низких скоростях (отрегулируйте в соответствии с вашими моторами. Мое двигатели не могли начать движение, если значение ШИМ было ниже значения 70)
  if (motorSpeedA < 70) {
    motorSpeedA = 0;
  }
  if (motorSpeedB < 70) {
    motorSpeedB = 0;
  }
  analogWrite(E1, motorSpeedA); // Send PWM signal to motor A
  analogWrite(E2, motorSpeedB); // Send PWM signal to motor B
}
