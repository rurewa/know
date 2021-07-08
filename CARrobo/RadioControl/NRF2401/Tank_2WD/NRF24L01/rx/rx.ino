// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// RX. Tank 2WD whitch NRF24L01.
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include "nRF24L01.h"
#include "RF24.h"
// receiver
const int enA = 10;
const int in1 = 4;
const int in2 = 5;
const int enB = 3;
const int in3 = 6;
const int in4 = 7;
RF24 radio(8, 9); // CE, CSN
const byte address[6] = "00001";
char receivedData[32] = "";
int  xAxis, yAxis;
int motorSpeedA = 0;
int motorSpeedB = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() 
{
  if (radio.available()) 
  {   // If the NRF240L01 module received data
    radio.read(&receivedData, sizeof(receivedData)); // Read the data and put it into character array
    xAxis = atoi(&receivedData[0]); // Convert the data from the character array (received X value) into integer
    delay(10);
    radio.read(&receivedData, sizeof(receivedData));
    yAxis = atoi(&receivedData[0]);
    delay(10);
  }
  // Y-axis used for forward and backward control
  if (yAxis < 470) 
  {
    // Set Motor A backward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // Set Motor B backward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    // Convert the declining Y-axis readings for going backward from 470 to 0 into 0 to 255 value for the PWM signal for increasing the motor speed
    motorSpeedA = map(yAxis, 470, 0, 0, 255);
    motorSpeedB = map(yAxis, 470, 0, 0, 255);
  }
  else if (yAxis > 550) 
  {
    // Set Motor A forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // Set Motor B forward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    // Convert the increasing Y-axis readings for going forward from 550 to 1023 into 0 to 255 value for the PWM signal for increasing the motor speed
    motorSpeedA = map(yAxis, 550, 1023, 0, 255);
    motorSpeedB = map(yAxis, 550, 1023, 0, 255);
  }
  // If joystick stays in middle the motors are not moving
  else 
  {
    motorSpeedA = 0;
    motorSpeedB = 0;
  }
  // X-axis used for left and right control
  if (xAxis < 470) 
  {
    // Set Motor A backward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // Set Motor B backward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    // Convert the declining X-axis readings for going backward from 470 to 0 into 0 to 255 value for the PWM signal for increasing the motor speed
    motorSpeedA = map(xAxis, 470, 0, 0, 255);
    motorSpeedB = map(xAxis, 470, 0, 0, 255);
  }
  if (xAxis > 550) 
  {
    // Set Motor A forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // Set Motor B forward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    // Convert the increasing X-axis readings for going forward from 550 to 1023 into 0 to 255 value for the PWM signal for increasing the motor speed
    motorSpeedA = map(xAxis, 550, 1023, 0, 255);
    motorSpeedB = map(xAxis, 550, 1023, 0, 255);
  }
  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
  analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
