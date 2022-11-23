#include<DHT.h>
#include<Adafruit_Sensor.h>
#include<DHT_U.h>

#define DHTPIN 6
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:

  dht.begin();
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  delay(3000);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  Serial.println(temperature);

}
