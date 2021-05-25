// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Пример выполнения простых логических операций
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

void setup() {
  Serial.begin(9600);
  int a = 5;
  int b = 10;
  int result = a < b;
  Serial.print("a < b: ");
  Serial.println(result);
  result = a > b;
  Serial.print("a > b: ");
  Serial.println(result);
  result = a == b;
  Serial.print("a == b: ");
  Serial.println(result);
  result = a != b;
  Serial.print("a != b: ");
  Serial.println(result);
  result = (a == b) && (a < b);
  Serial.print("(a == b) && (a < b): ");
  Serial.println(result);
  result = (a == b) || (a < b);
  Serial.print("(a == b) || (a < b): ");
  Serial.println(result);
  result = (a != b) && (a < b);
  Serial.print("(a != b) && (a < b): ");
  Serial.println(result);
  result = (a != b) || (a < b);
  Serial.print("(a != b) || (a == b): ");
  Serial.println(result);
  // С использованием тернарного оператора
  Serial.println(a > b ? "True" : "False");
  Serial.println(a < b ? "True" : "False");
  Serial.println(a == b ? "True" : "False");
  Serial.println(a != b ? "True" : "False");
}

void loop() {

}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
