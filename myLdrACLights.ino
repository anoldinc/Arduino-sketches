int ldrPin = A0;
int relayPin = 12;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  //int ldrValue = analogRead(ldrPin);

  pinMode(ldrPin, INPUT);
  pinMode(relayPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  int ldrValue = analogRead(ldrPin);

  if(ldrValue<800){
    digitalWrite(relayPin, HIGH);
  }
  else{
    digitalWrite(relayPin, LOW);
  }
  Serial.println(ldrValue);
  delay(500);

}
