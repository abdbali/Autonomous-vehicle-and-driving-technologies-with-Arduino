const int yağmurPin = A0; // Yağmur sensörünün AO pinini okumak için kullanılan analog pin

void setup() {
  Serial.begin(9600); // Seri monitör için başlat
}

void loop() {
  // Yağmur sensöründen analog değeri oku
  int yağmurDeğeri = analogRead(yağmurPin);

  // Seri monitöre değeri yazdır
  Serial.println(yağmurDeğeri);

  // Eğer yağmur algılanıyorsa (değer belirli bir eşik değerinden büyükse),
  // burada istediğiniz bir tepkiyi verebilirsiniz.
  if (yağmurDeğeri > 500) {
    Serial.println("Yağmur Algılandı!");//veya LED yakma gibi bir tepki verebilirsiniz.
  }

  // Biraz gecikme ekleyin
  delay(1000);
}
