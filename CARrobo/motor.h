// Объявляем переменные для хранения состояния двух моторов.
int motor_L1, motor_L2;
int motor_R1, motor_R2;
//===============================================
// Функция инициализации управления моторами.
void setup_motor_system(int L1, int  L2, int  R1, int R2)
{
  // Заносятся в переменные номера контактов (пинов) Arduino.
  motor_L1 = L1; motor_L2 = L2;
  // Для левых и правых моторов робота.
  motor_R1 = R1; motor_R2 = R2;
  // Переводятся указанные порты в состояние вывода данных.
  pinMode(motor_L1, OUTPUT);
  pinMode(motor_L2, OUTPUT);
  pinMode(motor_R1, OUTPUT);
  pinMode(motor_R2, OUTPUT);
}
//===============================================
// движение вперед.
void forward()
{
  // Если двигатель будет работать не в ту сторону,
  // поменять на нем контакты местами.
  digitalWrite(motor_L1, HIGH);
  digitalWrite(motor_L2, LOW);
  digitalWrite(motor_R1, HIGH);
  digitalWrite(motor_R2, LOW);
}
//===============================================
// Поворот налево с блокировкой левых колес.
void forward_left()
{
  // блокировка вращения левых колес.
  digitalWrite(motor_L1, LOW);
  digitalWrite(motor_L2, LOW);
  // правые колеса вращаются.
  digitalWrite(motor_R1, HIGH);
  digitalWrite(motor_R2, LOW);
}
//===============================================
// Поворот направо с блокировкой правых колес.
void forward_right()
{
  // левые колеса вращаются.
  digitalWrite(motor_L1, HIGH);
  digitalWrite(motor_L2, LOW);
  // блокировка вращения правых колес.
  digitalWrite(motor_R1, LOW);
  digitalWrite(motor_R2, LOW);
}
// Поворот налево на месте.
void left()
{
  // левые колеса вращаются назад.
  digitalWrite(motor_L1, LOW);
  digitalWrite(motor_L2, HIGH);
  // правые колеса вращаются вперед.
  digitalWrite(motor_R1, HIGH);
  digitalWrite(motor_R2, LOW);
}
//===============================================
// Поворот направо на месте.
void right()
{
  // левые колеса вращаются вперед.
  digitalWrite(motor_L1, HIGH);
  digitalWrite(motor_L2, LOW);
  // правые колеса вращаются назад.
  digitalWrite(motor_R1, LOW);
  digitalWrite(motor_R2, HIGH);
}


// Включаем движение назад.
void backward()
{
  // Смена направления вращения двигателей.
  digitalWrite(motor_L2, HIGH);
  digitalWrite(motor_L1, LOW);
  digitalWrite(motor_R2, HIGH);
  digitalWrite(motor_R1, LOW);
}
//===============================================
// Включаем движение назад.
void backward_left()
{
  // Смена направления вращения двигателей.
  digitalWrite(motor_L2, LOW);
  digitalWrite(motor_L1, HIGH);
  digitalWrite(motor_R2, HIGH);
  digitalWrite(motor_R1, LOW);
}
//===============================================
// Включаем движение назад.
void backward_right()
{
  // Смена направления вращения двигателей.
  digitalWrite(motor_L2, HIGH);
  digitalWrite(motor_L1, LOW);
  digitalWrite(motor_R2, LOW);
  digitalWrite(motor_R1, HIGH);
}
//===============================================


void _stop()
{
  // Блокировка всех колес.
  digitalWrite(motor_L2, LOW);
  digitalWrite(motor_L1, LOW);
  digitalWrite(motor_R2, LOW);
  digitalWrite(motor_R1, LOW);
}
