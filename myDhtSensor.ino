#include<DHT.h>
#include<Adafruit_Sensor.h>
#include <DHT_U.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

Adafruit_SSD1306 display(128, 32, &Wire, 4);

void setup() {
  // put your setup code here, to run once:

  //Serial.begin(9600);
  dht.begin();

   if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.display();
  display.clearDisplay();

  display.setTextSize(1);             
  display.setTextColor(SSD1306_WHITE);       
  display.setCursor(0,0); 

  display.print("HUMIDITY \n and \n TEMPERATURE \n SENSOR");
  display.display(); 
  delay(2000);
  display.clearDisplay(); 

}

void loop() {
  // put your main code here, to run repeatedly:

  delay(3000);

  float humidity = dht.readHumidity();
  float temp = dht.readTemperature();

  display.clearDisplay();
  display.setTextSize(1);             
  display.setTextColor(SSD1306_WHITE);        
  display.setCursor(0,0);


  display.print("Humidity: ");
  display.print( String(humidity));
  display.println(" %");

  
  display.print("\nTemp: ");
  display.print (String(temp));
  display.println(" deg Celcius");

  display.display();

}
