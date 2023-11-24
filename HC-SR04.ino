// HC-SR04 ultrasonik sensör pin tanımları
const int trigPin = 7;
const int echoPin = 6;

// Mesafe ölçümü için değişkenler
long mesafe;
long sure;

void setup() {
  Serial.begin(9600); // Seri iletişim başlat
  pinMode(trigPin, OUTPUT); // Trig pinini çıkış olarak ayarla
  pinMode(echoPin, INPUT); // Echo pinini giriş olarak ayarla
}

void loop() {
  // Trig pinine kısa bir darbe gönder
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Echo pininden gelen süreyi ölç
  sure = pulseIn(echoPin, HIGH);

  // Mesafeyi hesapla (Ses hızı 343 m/s, sensör iki yönlü çalıştığı için 2 ile çarpılır)
  mesafe = (sure / 2) * 0.0343;

  // Mesafeyi seri monitöre yazdır
  Serial.print("Mesafe: ");
  Serial.print(mesafe);
  Serial.println(" cm");

  // 1 saniye bekle
  delay(1000);
}