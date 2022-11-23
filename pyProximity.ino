int trigPin = 10;
int echoPin = 11;

void setup() {
  // put your setup code here, to run once:

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);

  float dist = pulseIn(echoPin, HIGH);
  float distance = dist*0.033;

  Serial.println(distance);
  delay(1000);
  
}
