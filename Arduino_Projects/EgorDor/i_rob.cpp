#include <SoftwareSerial.h>
#define left A2
#define middle A1
#define right A0
double timer ;
int ldp = 12;//
int lds = 10;
int rdp = 13;
int rds = 11;

int runSpeed = 200;

//daln
#include<NewPing.h>;
#define TRIG A3
#define ECHO A4

#define MAX 200
NewPing sonar(TRIG, ECHO, MAX);
//daln
void daln(){

 
//  delay(100);
  int distance = sonar.ping_cm();
  // Serial.println(distance);
   if (distance <= 50 && distance > 5 )
 {
  Serial.println("foud u");
   timer = millis();
  go();

 while (!digitalRead(left) && !digitalRead(middle) && !digitalRead(right)){// ! l_sense - сост лог 1 - white
 }

  delay(200);
  timer = millis() - timer ;
  Serial.println("aaa im in danger");
  back();
  delay(timer);
}
Serial.println("serching for u");
 turnRight();
 delay(100);
 }
void go(){
   runSpeed = 220;
  digitalWrite(ldp, HIGH);
  digitalWrite(rdp, HIGH);
  analogWrite(lds, runSpeed);
  analogWrite(rds, runSpeed);
  
}
void back(){
digitalWrite(ldp, LOW);
  digitalWrite(rdp, LOW);
 analogWrite(lds, runSpeed);
  analogWrite(rds, runSpeed);
}

void stop(){
  analogWrite(lds, 0);
  analogWrite(rds, 0);
}

void goForward(){  

  digitalWrite(ldp, HIGH);
  digitalWrite(rdp, HIGH);
  go();
}

void turnLeft(){
  analogWrite(lds, 100);
  analogWrite(rds, 0);
}

void turnRight(){
   runSpeed = 65;
  digitalWrite(ldp, LOW);
  analogWrite(lds, runSpeed);
  digitalWrite(rdp, HIGH);
  analogWrite(rds, runSpeed + 6);
}
void setup(){
 Serial.begin (9600);
 pinMode(ldp, OUTPUT);
 pinMode(lds, OUTPUT);
 pinMode(rdp, OUTPUT);
 pinMode(rds, OUTPUT);

pinMode(left, INPUT);
pinMode(middle, INPUT);
pinMode(right, INPUT);

  analogWrite(ldp, HIGH);
  analogWrite(rdp, HIGH);
}

  void loop() {
  daln();

 }