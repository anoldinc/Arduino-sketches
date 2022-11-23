//including sensor library
#include<DHT.h>
#include<Adafruit_Sensor.h>
#include <DHT_U.h>

//including WiFi library
#include<WiFi.h>
#include<Arduino.h>

//including thingSpeak library
#include<ThingSpeak.h>

//define DHT variables
#define DHTPIN 14
#define DHTTYPE DHT22

//define WiFi name
#define WIFI_NETWORK "General"
//define WiFi password
#define WIFI_PASSWORD "general123"

//create a DHT object
DHT dht(DHTPIN, DHTTYPE);

//create a WiFi client to connect to thingSpeak
WiFiClient client;

//creating channel number
unsigned long myChannelNumber = 1929733;
const char* APIkey = "16E1YGUE67WMNTJB";

//function that connects esp32 to specified WiFi network
void connectToWifi(){
  Serial.print("Connecting to WiFi");
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_NETWORK, WIFI_PASSWORD);

  unsigned long startAttemptTime = millis();

  while(WiFi.status() !=WL_CONNECTED && millis() - startAttemptTime <5000){
    Serial.print(".");
    delay(100);
    }

  if(WiFi.status() != WL_CONNECTED){
    Serial.println("Failed to connect to Wifi");
  }
  else{
       Serial.print("Connected to ");
       Serial.print(WIFI_NETWORK);
       Serial.println(WiFi.localIP());       
  }
}

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  dht.begin();
  ThingSpeak.begin(client); //initialise thingspeak
  connectToWifi();

}

void loop() {
  // put your main code here, to run repeatedly:

  float humidity = dht.readHumidity();
  float temp = dht.readTemperature();

  Serial.print("Humidity(%): ");
  Serial.println(humidity);

  Serial.print("Temp(deg CelC): ");
  Serial.println(temp);

  //set fields with values
  ThingSpeak.setField(1, temp);
  ThingSpeak.setField(2, humidity);

  int x= ThingSpeak.writeFields(myChannelNumber, APIkey);

  if(x == 200){
    Serial.println("Channel update successful.");
    }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
    }
      
  Serial.print("\n");
  delay(16000);
}
