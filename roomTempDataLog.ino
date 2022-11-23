#include<Adafruit_Sensor.h>
#include<DHT.h>

#include<SD.h>
#include<SPI.h>

#include<RTClib.h>

#define DHTPIN 2
#define DHTTYPE    DHT11

RTC_DS3231 rtc;
File myFile;
DHT dht(DHTPIN, DHTTYPE);



void setup() {
  // put your setup code here, to run once:

  Serial.begin(57600);

  pinMode(4, OUTPUT);

  //wait for serial port to connect
  while(!Serial){
    
  }

  dht.begin();
  sensor_t sensor;

   if(!rtc.begin()){
   Serial.println("Could not find rtc!");
   while(1);
  }

  //the rtc.lostPower() function returns a 1 when there is a noticable power loss 
  //at the rtc. it returns a zero incase of no power loss

  if(rtc.lostPower()){
    //set time to match computer clock
    //the set time is the time of uploading this sketch to the arduino

    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  //SD.begin(4);

  if(!SD.begin(4)){
    Serial.println("SD card initialisation failed");
    while(1);
  }

  

  //myFile.write("Time,  Temperature,  Humidity");


}

void loop() {
  // put your main code here, to run repeatedly:

  String dataString = "";

  DateTime time = rtc.now();
  dataString += time.timestamp(DateTime:: TIMESTAMP_TIME);
  dataString +=",";
  

  dataString += String(dht.readTemperature());
  dataString +=",";
  dataString += String(dht.readHumidity());
  dataString +=",";
  Serial.println(dataString);
  
  myFile = SD.open("roomDataFinal.txt", FILE_WRITE);
  if(myFile){
    myFile.println(dataString);
    myFile.close();
    
  }
  
  else{
    Serial.println("error opening file");
  }
  delay(3000);

}
