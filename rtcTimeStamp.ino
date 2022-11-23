//include relevant libraries
#include<RTClib.h>

//create an RTC object
RTC_DS3231 rtc;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);

  //wait for serial port to connect
  while(!Serial){
    
  }

  //configure RTC errors
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

}

void loop() {
  // put your main code here, to run repeatedly:

  //rtc.now()function returns a DateTime object that describes the year, month, day, hour, minute and second
  DateTime time = rtc.now();

  //Full time stamp with date and time
  Serial.println(String("DateTime     ") + time.timestamp(DateTime:: TIMESTAMP_FULL));

  //Date only
  Serial.println(String("DateTime     ") + time.timestamp(DateTime:: TIMESTAMP_DATE));

   //Time only
  Serial.println(String("DateTime     ") + time.timestamp(DateTime:: TIMESTAMP_TIME));
  Serial.println("\n");

  delay(2000);

}
