#include <DHT.h>
//define tên biến gtri
#define DHTTYPE DHT22
#define DHTPIN 2

DHT   dhtSensor(DHTPIN, DHTTYPE);

void setup() {
Serial.begin(9600); 
//điền tốc độ baud
dhtSensor.begin();
}

void loop() {
float temp = dhtSensor.readTemperature();
float humi = dhtSensor.readHumidity();

Serial.print("Temp = ");
Serial.println(temp);
Serial.print("Humi = ");
Serial.println(humi);
delay(1000);
}
