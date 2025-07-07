#include <LiquidCrystal_I2C.h>
#include <DHT.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

DHT dht(4, DHT22);
void setup() {
  lcd.init();
  dht.begin();
  lcd.print("Temp, humid:");
}

void loop() {
  lcd.setCursor(0,1);
  lcd.println (dht.readTemperature());
  lcd.print(dht.readHumidity());
}
