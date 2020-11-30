#include "Adafruit_seesaw.h"
#include "Adafruit_ADS1015.h"
#include <Wire.h>

Adafruit_seesaw stemma1;
Adafruit_seesaw stemma2;

void setup() {
  Serial.begin(115200);
  stemma1.begin(0x36);
  stemma2.begin(0x37);
}

void loop() {
  float temp1 = stemma1.getTemp();
  uint16_t moist1 = stemma1.touchRead(0);
  float temp2 = stemma2.getTemp();
  uint16_t moist2 = stemma2.touchRead(0);

  Serial.print("Temperature: "); Serial.print(tempC); Serial.println("*C");
  Serial.print("Capacitive: "); Serial.println(capread);
  delay(100);
}
