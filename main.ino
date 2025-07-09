#include <DHT.h>


#define DHTPIN 7        
#define DHTTYPE DHT11    
#define MQ_PIN A5        
#define BUZZER_PIN 2    

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(MQ_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(BUZZER_PIN, LOW);  
}

void loop() {

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); 


  int gasValue = analogRead(MQ_PIN); 
  
  Serial.print("Nhiệt độ: "); Serial.print(temperature); Serial.println(" *C");
  Serial.print("Độ ẩm: "); Serial.print(humidity); Serial.println(" %");
  Serial.print("Giá trị khí gas (ADC): "); Serial.println(gasValue);
  Serial.println("---------------------------");

 
  if (temperature > 31 || gasValue > 2000) {
    digitalWrite(BUZZER_PIN, LOW); 
  } else {
    digitalWrite(BUZZER_PIN, HIGH);  
  }

  delay(2000); 
}