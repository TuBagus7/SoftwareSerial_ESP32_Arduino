#include "SoftwareSerial.h"
SoftwareSerial Hujan(16, 17); // RX, TX

void setup() {
  Serial.begin(9600);
  Hujan.begin(9600);
}

void loop() {
  String data_hujan = "";
  while (Hujan.available() > 0)
  {
    data_hujan += char(Hujan.read());
  }
  data_hujan.trim();
  Serial.println("Data Sensor Dari Arduino: "+data_hujan);
  delay(1000);
}
