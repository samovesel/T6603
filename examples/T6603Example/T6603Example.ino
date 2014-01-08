#include "SoftwareSerial.h"
#include <T6603.h>

T6603 sensor;

void setup() {
    Serial.begin(19200);
    sensor.begin(10, 11);  
}

void loop() {
    Serial.println(sensor.get_co2());
    delay(2000);
}