// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Азбука Морзе. Обновлённый вариант
//
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

void setup() {
  pinMode(12, OUTPUT);
}

void loop() {
  int delayTime = 2500;
  threeDots(200, 500);
  delay(delayTime);
  threeDashes(1000, 500);
  delay(delayTime);
  threeDots(200, 500);
  delay(delayTime);
}

void threeDots(int timeHigh, int timeLow) {
  for (int i = 0; i < 3; ++i) {
    digitalWrite(12, HIGH);
    delay( timeHigh);
    digitalWrite(12, LOW);
    delay(timeLow);
  }
}

void threeDashes(int timeHigh, int timeLow) {
  for (int i = 0; i < 3; ++i) {
    digitalWrite(12, HIGH);
    delay(timeHigh);
    digitalWrite(12, LOW);
    delay(timeLow);
  }
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
