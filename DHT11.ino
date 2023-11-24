#include <DHT.h>

#define DHTPIN 2  // DHT11 sensörünün bağlı olduğu dijital pin
#define DHTTYPE DHT11  // Kullandığınız sensör tipini belirtin

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Sıcaklık ve nem değerlerini oku
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Verileri seri monitöre yazdır
  Serial.print("Sıcaklık: ");
  Serial.print(temperature);
  Serial.print(" °C\tNem: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Bir saniye bekle
  delay(1000);
}
