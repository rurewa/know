#include <NewPing.h> // библиотека сонара
int TRIG = 3; // посылание звука (неточная информация)
int ECHO = 2; // прием звука (неточная информация)
int MAX_DISTANCE = 30; // максимальное расстояние измерения
NewPing sonar(TRIG, ECHO, MAX_DISTANCE); // определение сонара
int DISTANCE; // переменная "расстояние"
int DISTANCE_R;
int DISTANCE_L;
int DISTANCE_F;
int Right_Motor_Speed = 10;
int Left_Motor_Speed = 9;
int Right_Motor_Dir = 12;
int Left_Motor_Dir = 11;
int speed = 150; 
int bank = A6;

void forward( int time )
{
  digitalWrite( Right_Motor_Dir, HIGH );
  analogWrite( Right_Motor_Speed,speed );
  digitalWrite( Left_Motor_Dir, HIGH );
  analogWrite( Left_Motor_Speed, speed );
  delay( time );
}
void backward( int time )
{
  digitalWrite( Right_Motor_Dir, LOW );
  analogWrite( Right_Motor_Speed, speed );
  digitalWrite( Left_Motor_Dir, LOW );
  analogWrite( Left_Motor_Speed, speed );
  delay( time );
}
void stope( int time )
{
  digitalWrite( Right_Motor_Dir, HIGH );
  analogWrite( Right_Motor_Speed, 0 );
  digitalWrite( Left_Motor_Dir, HIGH );
  analogWrite( Left_Motor_Speed, 0 );
  delay( time );  
}
void left( int time )
{
  digitalWrite( Right_Motor_Dir, HIGH );
  analogWrite( Right_Motor_Speed, speed );
  digitalWrite( Left_Motor_Dir, LOW );
  analogWrite( Left_Motor_Speed, speed );
  delay( time );
}
void right( int time )
{
  digitalWrite( Right_Motor_Dir, LOW );
  analogWrite( Right_Motor_Speed, speed );
  digitalWrite( Left_Motor_Dir, HIGH );
  analogWrite( Left_Motor_Speed, speed );
  delay( time );
}
void right_hand_forward( int time )
{
  digitalWrite( Right_Motor_Dir, HIGH );
  analogWrite( Right_Motor_Speed, 255 );
  digitalWrite( Left_Motor_Dir, HIGH );
  analogWrite( Left_Motor_Speed, 0 );
  delay( time );
}
void left_hand_forward( int time )
{
  digitalWrite( Right_Motor_Dir, HIGH );
  analogWrite( Right_Motor_Speed, 0 );
  digitalWrite( Left_Motor_Dir, HIGH );
  analogWrite( Left_Motor_Speed, 255 );
  delay( time );
}

void setup() 
{
  Serial.begin ( 9600 ); // скорость общения с "портом" для вывода инфы на монитор
  pinMode ( Right_Motor_Dir, OUTPUT );
  pinMode ( Right_Motor_Speed, OUTPUT );
  pinMode ( Left_Motor_Dir, OUTPUT );
  pinMode ( Left_Motor_Speed, OUTPUT );
  pinMode ( TRIG, OUTPUT );
  pinMode ( ECHO, INPUT );
  pinMode ( A3, INPUT );
  pinMode ( bank, INPUT );
  pinMode ( A1, INPUT );
  pinMode ( A2, INPUT );

}

void loop() 
{
  unsigned int DISTANCE = sonar.ping_cm(); // читаем показания сонара в сантиметра
  delay ( 40 );  //  ждем для чтения сонара
  Serial.println (DISTANCE);
  if ( DISTANCE == 0 )
  {
    right ( 50 );  //  крутимся направо в поисках объекта 
    stope ( 1 );  // стоп
  }
  if ( DISTANCE < 30 && DISTANCE > 0 )
  {
    //right ( 35 );  // докручиваемся примерно до центра объекта
    stope ( 1 );
    while ( true )
    {
      unsigned int DISTANCE = sonar.ping_cm(); // читаем показания сонара в сантиметра
      delay ( 40 );
      int color = analogRead( A3 );  //  чтение датчика линии края поля
      if ( color > 500 && DISTANCE > 0 )  // если робот не доехал до линии
      {
        forward ( 20 );
        stope ( 1 ); 
      }
      if ( color < 500 )  // если робот доехал до линии
      {
        while (true)  // начало цикла выравнивания по линии для более менее ровного отъезда назад
        {
          int Line_R = analogRead (A1); // чтиние правого датчика линии
          int Line_L = analogRead (A2); // чтение левого датчика линии
          int Line_F = analogRead (A3); // чтание центрального датчика линии
          if (Line_F < 500 && Line_R > 500 && Line_L > 500)
          {
            forward ( 5 );
            stope ( 1 );
          }
          if ( Line_R < 500 && Line_L > 500 )
          {
            left_hand_forward ( 10 );
            stope ( 1 );
          }
          if ( Line_L < 500 && Line_R > 500 )
          {
            right_hand_forward ( 10 );
            stope ( 1 );
          }
          if (Line_R < 500 && Line_L < 500 )
          {
            backward ( 1500 );
            stope ( 10 );
            return;
          }
        }
      }
      if ( DISTANCE == 0 ) // если объект пропал из поля работы сонара, начинаем поиск объекта
      {
        int MAX_DISTANCE = 20;  //  определение максимально рабочей дистанции для чтения сонара
        unsigned int DISTANCE_F = sonar.ping_cm();  //  Ищем прямо сонаром
        delay( 40 );  //  ждем для чтения сонара
        right( 150 );  //  разворот направо
        stope( 1 );  // стоп на всякий случай
        unsigned int DISTANCE_R = sonar.ping_cm();  // Проверяем наличие объекта перед нами (в позиции правее) 
        delay( 40 );
        left( 300 );  //  разворот налево
        stope( 1 );  //  стоп на всякий случай
        unsigned int DISTANCE_L = sonar.ping_cm();  //  Проверяем наличие объекта перед нами (в позиции левее) 
        delay( 40 );
        if( DISTANCE_F > DISTANCE_R && DISTANCE_F > DISTANCE_L )  //  если объект прямо 
        {
          right( 150 );  //  разворот направо
          stope( 1 );
          return;
        }
        if( DISTANCE_R > DISTANCE_F && DISTANCE_R > DISTANCE_L )  // если объект находится справа
        {
          right( 300 );  //  разворот направо
          stope( 1 );
          return;
        }
        if( DISTANCE_L > DISTANCE_F && DISTANCE_L > DISTANCE_R )  //  если объект находится слева 
        {
          stope ( 10 );
          return; 
        }
        if( DISTANCE_F == 0 && DISTANCE_R == 0 && DISTANCE_L == 0 )  //  если не нашли объекта
        {
          backward( 750 );  //  назад
          stope( 10 );   //  стоп на всякий случай
          return;
        }
      }
      if ( DISTANCE < 3 && DISTANCE >0 )  // подъехали к объекту на расстояние чтения цвета банки
      {
        forward (50); // выравниваем банку для чтения цвета
        stope (1);
        int bank_color = analogRead ( bank ); // чтение цвета банки
        if ( bank_color > 800 ) // если банка черная
        {
          backward ( 750 );
          right ( 300 );
          stope ( 1000 );
          return;
        }
        if ( bank_color < 800 ) // если банка белая
        {
        delay (500);
        }
        while ( true )
        {
          int color = analogRead( A3 );  //  чтение датчика линии края поля
          if ( color > 500 ) // если робот не доехал до линии края поля
          {
            forward ( 10 ); 
          }
          if ( color < 500 ) // если робот доехал до линии края поля
          {
            while ( true ) // начало цикла выравнивания по линии для более менее ровного отъезда назад
            {
              int Line_R = analogRead (A1);
              int Line_L = analogRead (A2); 
              int Line_F = analogRead (A3);
              if (Line_F < 500 && Line_R > 500 && Line_L > 500)
              {
                forward ( 5 );
                stope ( 1 );
              }
              if ( Line_R < 500 && Line_L > 500 )
              {
                left_hand_forward ( 20 );
                stope ( 1 );
              }
              if ( Line_L < 500 && Line_R > 500 )
              {
                right_hand_forward ( 20 );
                stope ( 1 );
              }
              if (Line_R < 500 && Line_L < 500 )
              {
                backward ( 1700 );
                stope ( 10 );
                return;
              }
            }
          }
        }
      }
    }
  }
}  
