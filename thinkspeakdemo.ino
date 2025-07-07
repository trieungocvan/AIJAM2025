////////////////Khai báo thư viện/////////////////////
#include <WiFi.h>
#include "ThingSpeak.h"

/////////////////Khai báo hằng số////////////////////
#define WIFI_NAME  "Wokwi-GUEST"
#define WIFI_PASSWORD  ""
#define CHANNEL_ID 2695758
#define API_KEY "CQMXUXQ6K1AT7OW2"


/////////////////Khai báo đối tượng////////////////////
WiFiClient client; 

void setup(){
  Serial.begin(9600); // Initialize the serial communication at a baud rate of 115200
  WiFi.begin(WIFI_NAME, WIFI_PASSWORD); // Connect to the WiFi network
  while (WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.println("Wifi not connected"); // Print a message if WiFi is not connected
  }
  Serial.println("Wifi connected !"); // Print a message if WiFi is connected
  ThingSpeak.begin(client); 
}

void loop(){
  // setField(Số thự tự field cần viết, giá trị muốn viết)
  ThingSpeak.setField(1,1); 
  ThingSpeak.setField(2,5); 
  ThingSpeak.setField(3,2000); 

  int x = ThingSpeak.writeFields(CHANNEL_ID,API_KEY); 

  if(x == 200){
    Serial.println("Data pushed successfully"); // Print a message if the data was successfully pushed to ThingSpeak
  }else{
    Serial.println("Push error" + String(x)); // Print an error message with the HTTP status code if there was an error pushing the data
  }
  delay(10000);
}