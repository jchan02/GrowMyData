#include "Adafruit_seesaw.h"
#include "Adafruit_ADS1015.h"
#include "DHT.h"
#include "Wire.h"

#define DHTTYPE DHT11

Adafruit_seesaw stemma1;
Adafruit_seesaw stemma2;
Adafruit_ADS1115 adc;
DHT dht(1, DHTTYPE);

void setup() {
  Serial.begin(9600);
  stemma1.begin(0x36);
  stemma2.begin(0x37);
  adc.begin();
  dht.begin();
}

void loop() {
  int16_t adc0, adc1, adc2, adc3;
 
  float temp1 = stemma1.getTemp();
  uint16_t moist1 = stemma1.touchRead(0);
  float temp2 = stemma2.getTemp();
  uint16_t moist2 = stemma2.touchRead(0);
  light = adc.readADC_SingleEnded(0);
  float humidity = dht.readHumidity();

  Serial.print("Temperature (1): "); Serial.print(temp1); Serial.println("C");
  Serial.print("Capacitive (1): "); Serial.println(moist1);
  Serial.print("Temperature (2): "); Serial.print(temp2); Serial.println("C");
  Serial.print("Capacitive (2): "); Serial.println(moist2);
  Serial.print("Light: "); Serial.println(light);
  Serial.print("Humidity: "); Serial.println(humidity);
  delay(1000);
}
