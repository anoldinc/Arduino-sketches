const int buzzer = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  tone(buzzer, 10000);
  delay(300);
  noTone(buzzer);
  delay(300);

}
