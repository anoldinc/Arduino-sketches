#include<SPI.h>
String data = "";
String slaveResponse = "";
volatile bool responseAvailable = false;
volatile int i = 0;
volatile bool sending = false;

int num1;
int num2;

//**********************
int operationIndex(String a){
  for(int i=0; i<a.length(); i++){
    if(!isDigit(a[i])){
      return i;
    }
  }
}

void extractNumber(String a){
  int operatorIndex= operationIndex(a);
  num1 = a.substring(0, operatorIndex).toInt();
  num2 = a.substring(operatorIndex+1).toInt();
}

String evaluate(String a){
  extractNumber(a);
  int operatorIndex = operationIndex(a);
  char operatorValue = a[operatorIndex];

  if(operatorValue == '-'){
    return String(num1 - num2);
  }

  if(operatorValue == '+'){
    return String(num1 + num2);
  }

  if(operatorValue == '/'){
    return String(num1 / num2);
  }

  if(operatorValue == '*'){
    return String(num1 * num2);
  }
}



//**********************


volatile char c;
volatile boolean process = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  Serial.println("-----------------SLAVE TERMINAL-------------");

  //calling the interrupt function

  SPCR |= _BV(SPE);
  SPI.attachInterrupt();

  pinMode(MISO, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("-----------------SLAVE TERMINAL-------------");

  //printing to the serial monitor
  if(process){
    Serial.print("From Master: ");
    Serial.println(data);
    process = false;
    //Serial.println(evaluate(data));
    slaveResponse = evaluate(data);
    responseAvailable = true;
    sending = true;
    data = "";

  }
    

}

ISR(SPI_STC_vect){
  //reading to the SPDR register
  if(!sending){
    char c = SPDR;
    data += c;
    if ((c == '\0') || (c == '\n') || (c == '\r')){
      process = true;
    }
  }else{
    if(responseAvailable){
        SPDR = slaveResponse[i++];
        if(i == slaveResponse.length() + 2){
          slaveResponse = "";
          responseAvailable = false;
          i = 0;
          sending = false;
        }
    }
  } 
}
