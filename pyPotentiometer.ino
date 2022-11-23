int potPin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int potVal = analogRead(potPin);
  Serial.println(potVal);

}
