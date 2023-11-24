#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(9600);

  // MPU6050'yi başlat
  Wire.begin();
  mpu.initialize();

  // Başlatma sırasında bir hata olup olmadığını kontrol et
  if (mpu.testConnection()) {
    Serial.println("MPU6050 bağlantısı başarılı!");
  } else {
    Serial.println("MPU6050 bağlantı hatası!");
    while (1);
  }
}

void loop() {
  // Sensör verilerini al
  mpu.getMotion6();

  // Ivme verilerini al
  int16_t ax = mpu.getAccelerationX();
  int16_t ay = mpu.getAccelerationY();
  int16_t az = mpu.getAccelerationZ();

  // Gyro verilerini al
  int16_t gx = mpu.getRotationX();
  int16_t gy = mpu.getRotationY();
  int16_t gz = mpu.getRotationZ();

  // Seri monitöre verileri yazdır
  Serial.print("Ivme: ");
  Serial.print("X: "); Serial.print(ax); Serial.print("  ");
  Serial.print("Y: "); Serial.print(ay); Serial.print("  ");
  Serial.print("Z: "); Serial.println(az);

  Serial.print("Gyro: ");
  Serial.print("X: "); Serial.print(gx); Serial.print("  ");
  Serial.print("Y: "); Serial.print(gy); Serial.print("  ");
  Serial.print("Z: "); Serial.println(gz);

  Serial.println();

  // Kısa bir gecikme ekle
  delay(500);
}
