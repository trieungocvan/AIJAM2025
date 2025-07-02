#include <Wifi.h>

#define ssid "BKSTAR_T2_02"
#define pass "STEMSTAR"
#define channelid ""
#define key ""

WiFiClient client;

void setup() {
  Serial.begin(9600);
  wifi.begin(ssid,pass);
  while(wifi.status != WF_CONNECTED){
    delay(1000);
    Serial.print(".");
  }
  Serial.println("Connected");
  ThinkSpeak.begin(client);
}

void loop() {
  

}
