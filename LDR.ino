const int ldrPin = A0; // LDR modülünün bağlı olduğu analog pin

void setup() {
  Serial.begin(9600); // Seri monitör için başlat
}

void loop() {
  // LDR değerini oku
  int ldrValue = analogRead(ldrPin);

  // Seri monitöre değeri yazdır
  Serial.println(ldrValue);

  // Burada istediğiniz bir tepkiyi verebilirsiniz.
  // Örneğin, belirli bir ışık seviyesinin altında bir şey yapabilirsiniz.
  if (ldrValue < 500) {
    Serial.println("Düşük Işık Seviyesi Algılandı!");
  }