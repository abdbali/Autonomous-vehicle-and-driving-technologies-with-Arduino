#include <Wire.h>
#include <MPU6050.h>
#include <DHT.h>

#define DHTPIN A1   //Sensörün Bağlı Olduğu Pin
#define DHTTYPE DHT11   //Kullanılan Sensörün Tipi(DHT11)

const int ldrPin = A0;    //LDR Modülünün Bağlı Olduğu Pin
const int yagmurPin = A1;   //Yağmur Sensörünün Bağlı Olduğu Pin
const int trigPin = 7;    
const int echoPin = 6;
const int motorPins[] = {8, 9, 10, 11};   //Motorların Bağlı Olduğu Pinler

DHT dht(DHTPIN, DHTTYPE);
MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  Wire.begin();   //Başlat MPU6050
  mpu.initialize();
  dht.begin();    //Başlt DHT11
  for (int i = 0; i < 4; i++) {
    pinMode(motorPins[i], OUTPUT);    //Motor Pinlerini Çıkış Olarak Ayarla
  }
}

void loop() {
  int ldrdegeri = analogRead(ldrPin);    //LDR Değerini Oku
  int yagmurdegeri = analogRead(yagmurPin);    //Yağmur Sensörünün Analog Değerini Oku
  float nem = dht.readHumidity();    //Nem Değerini Oku
  float sicaklik = dht.readTemperature();    //Sıcaklık Değerini Oku

  int16_t ax, ay, az, gx, gy, gz;   //X,Y,Z Ddeğerlerini Tanımla
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);   //X,Y,Z Ddeğerlerini Güncelle

  printSensorData(ldrdegeri, yagmurdegeri, sicaklik, nem, ax, ay, az, gx, gy, gz);
    //Yağmur algılanıyorsa
  if (yagmurdegeri > 500) {
    Serial.println("Yağmur Algılandı");
  }

  controlMotor(true); 
  delay(2000);
  controlMotor(false); 
  delay(1000);
  delay(1000);
}

void printSensorData(int ldr, int yagmur, float sicaklik, float nem, int ax, int ay, int az, int gx, int gy, int gz) {
  Serial.print("LDR Degeri: ");
  Serial.println(ldr);
  Serial.print("Yağmur: ");
  Serial.println(yagmur > 500 ? "Detected" : "Not Detected");
  Serial.print("Sıcaklık: ");
  Serial.print(sicaklik);
  Serial.print(" °C\tNem: ");
  Serial.print(nem);
  Serial.println(" %");
  Serial.print("İvme: ");
  Serial.print("X: "); Serial.print(ax); Serial.print("  ");
  Serial.print("Y: "); Serial.print(ay); Serial.print("  ");
  Serial.print("Z: "); Serial.println(az);
  Serial.print("Jiroskop: ");
  Serial.print("X: "); Serial.print(gx); Serial.print("  ");
  Serial.print("Y: "); Serial.print(gy); Serial.print("  ");
  Serial.print("Z: "); Serial.println(gz);
}

void controlMotor(bool moveForward) {
  digitalWrite(motorPins[0], moveForward ? HIGH : LOW);
  digitalWrite(motorPins[1], moveForward ? LOW : LOW);
  digitalWrite(motorPins[2], moveForward ? HIGH : LOW);
  digitalWrite(motorPins[3], moveForward ? LOW : LOW);
}