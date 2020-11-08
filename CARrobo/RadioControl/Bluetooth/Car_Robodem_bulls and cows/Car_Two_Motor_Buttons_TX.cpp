// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Робот с использованием L293D управляемый Bluetooth и пультом с кнопками (быки и коровы)
// Код приёмника
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
int forward = 3;
int backward = 5;
int left = 6;
int right = 4;

void setup() {
  Serial.begin(38400);
}
void loop() {  
  char state = 0;
  if (digitalRead(forward) == 1) bitSet(state, 0);
  if (digitalRead(backward) == 1) bitSet(state, 1);
  if (digitalRead(left) == 1) bitSet(state, 2);
  if (digitalRead(right) == 1) bitSet(state, 3);
  Serial.write(state);
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
