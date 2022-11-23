
#include<SPI.h>
String data = "";
String slaveResponse = "";
bool receiving = false;

byte transferAndWait(byte x){
  byte a = SPI.transfer(x);
  delayMicroseconds(20);
  return a;  
}


void setup() {
  // put your setup code here, to run once:
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  Serial.begin(115200);

  
  Serial.println("-------------MASTER TERMINAL----------");
  Serial.println("---SLAVE ANSWERS SENT EXPRESSION--- ");

}

void loop() {
  // put your main code here, to run repeatedly:

  //getting data from serial monitor
  int incoming = Serial.available();
  for(int i=0; i<incoming; i++){
    data += char(Serial.read());
  }

  //sending data to the slave
  digitalWrite(SS, LOW);
  for(int i=0;i<data.length(); i++){
    SPI.transfer(data[i]);
    delay(10);
    receiving = true;
  }
  digitalWrite(SS, HIGH);

 //receiving data from slave
 if(receiving){
  delay(2000);
  digitalWrite(SS, LOW);
  transferAndWait(0);
  char c = '0';
  while((c != '\r') && (c != '\0') && (c != '\n')){
    c = (char)transferAndWait(0);
    slaveResponse += c;
  }
  digitalWrite(SS, HIGH);
  Serial.println("From Slave: ");
  Serial.println("Answer is " +slaveResponse);
  slaveResponse = "";
  receiving = false;
 }
  //resetting everything
  data = "";
  delay(1000);
}
