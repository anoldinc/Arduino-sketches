int button1= 6;
int button2 = 7;

int redLed = 8;
int greenLed = 9;
int yellowLed = 10;
int blueLed = 11;


void setup() {
  // put your setup code here, to run once:
  for(int i=8;i<12; i++){
    pinMode(i, OUTPUT);
  }
}


void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(button1) == 1){
    digitalWrite(redLed, HIGH);
    delay(500);
    digitalWrite(redLed, LOW);
    delay(500);

    digitalWrite(greenLed, HIGH);
    delay(500);
    digitalWrite(greenLed, LOW);
    delay(500);

    digitalWrite(yellowLed, HIGH);
    delay(500);
    digitalWrite(yellowLed, LOW);
    delay(500);

    digitalWrite(blueLed, HIGH);
    delay(500);    
  }

  else 
  if(digitalRead(button2) == 1){
    digitalWrite(blueLed, HIGH);
    delay(500);   
    digitalWrite(blueLed, LOW);
    delay(500);   

    digitalWrite(yellowLed, HIGH);
    delay(500);   
    digitalWrite(yellowLed, LOW);
    delay(500);  

    digitalWrite(greenLed, HIGH);
    delay(500);   
    digitalWrite(greenLed, LOW);
    delay(500);  

    digitalWrite(redLed, HIGH);
    delay(500);   
  }

}
