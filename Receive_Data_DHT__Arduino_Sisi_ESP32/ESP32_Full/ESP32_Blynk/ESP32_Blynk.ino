#define BLYNK_TEMPLATE_ID "TMPL6ns_u3Wgr"
#define BLYNK_TEMPLATE_NAME "Medical"
#define BLYNK_AUTH_TOKEN "FopjY2aXyI3vt5dxtDDBJApXk_m801JC"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "SoftwareSerial.h"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Redmi Note 10 Pro";
char pass[] = "1sampai8";

SoftwareSerial Hujan(16, 17); // RX, TX

#define VPIN_suhu V0
#define VPIN_hum V1

BlynkTimer timer;

void setup() {
  Serial.begin(9600);
  Hujan.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  Blynk.run();
  
  if (Hujan.available() > 0) {
    String dataFromArduino = "";
    
    // Membaca data yang dikirim dari Arduino
    while (Hujan.available() > 0) {
      char incomingChar = Hujan.read();
      dataFromArduino += incomingChar;
      delay(10); // Hindari membaca terlalu cepat
    }

    dataFromArduino.trim();

    // Pisahkan data berdasarkan koma
    int commaIndex = dataFromArduino.indexOf(',');
    if (commaIndex > 0) {
      String suhu = dataFromArduino.substring(0, commaIndex);
      String hum = dataFromArduino.substring(commaIndex + 1);

      // Tampilkan data di serial monitor
      Serial.println("Suhu: " + suhu);
      Serial.println("Kelembaban: " + hum);

      // Kirim data ke Blynk
      Blynk.virtualWrite(VPIN_suhu, suhu);
      Blynk.virtualWrite(VPIN_hum, hum);
    }
  }

  delay(1000); // Delay untuk loop
}
