#include <SoftwareSerial.h>
#include "DHT.h"

const int DHTPIN = A0;
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
DHT dht (DHTPIN, DHTTYPE);
// Deklarasi PIN Sensor Hujan
SoftwareSerial Hujan(2, 3);// RX, TX

//Data Tampung
int DataSuhu;

void setup() {
  Serial.begin(9600);
  dht.begin();
  Hujan.begin(9600);
//  pinMode (pinAO, INPUT);
}


void loop (){
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print("Temperature : ");
  Serial.println(h);
  Serial.print("Humidity : ");
  Serial.println(t);

  DataSuhu = h;
  Serial.println(DataSuhu);
  Hujan.println(DataSuhu);
  delay (800);
}



//void setup() {
//  Serial.begin(9600);
//  dht.begin();
//  suhu.begin(9600);
//  pinMode (pinAO, INPUT);
//}

//void loop() {
//  //Kesimpulan Bahwa Sensor Hujan Itu Aktif LOW (0)
//  DataAnalog = analogRead(pinAO);
//  Serial.println(DataAnalog);
//  Hujan.println(DataAnalog);
//  delay(1000);
//}
