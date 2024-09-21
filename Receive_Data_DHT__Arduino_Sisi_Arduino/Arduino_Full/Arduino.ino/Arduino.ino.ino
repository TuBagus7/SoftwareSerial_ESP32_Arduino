#include <SoftwareSerial.h>
#include "DHT.h"

const int DHTPIN = A0;
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);

// Deklarasi PIN Sensor Hujan
SoftwareSerial Hujan(2, 3); // RX, TX

void setup() {
  Serial.begin(9600);
  dht.begin();
  Hujan.begin(9600);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Gabungkan data suhu dan kelembaban dalam format "t,h"
  String dataToSend = String(t) + "," + String(h);

  // Kirim data ke ESP32
  Hujan.println(dataToSend);
  
  // Tampilkan data di serial monitor
  Serial.println("Data dikirim: " + dataToSend);

  delay(2000); // Tunggu 2 detik sebelum pengiriman berikutnya
}
