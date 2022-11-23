int counter = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print(counter);
  Serial.println(" Elizabeths");
  counter +=1;
  delay(1000);

}
