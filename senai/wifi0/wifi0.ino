#include <WiFi.h>

String redeSSID="";
int intensidadeSinal=-9999;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
}

void loop() {
  int n=WiFi.scanNetworks();
  Serial.println("Escaneamento realizado");
  if(n==0){
    Serial.println("Nenhuma rede encontrada");
  }else{
    redeSSID="";
    intensidadeSinal=-9999;
    Serial.print(n);
    Serial.println(" redes encontradas");
    for(int i=0;i<n;++i){
      Serial.print(WiFi.SSID(i));
      Serial.print(": ");
      Serial.println(WiFi.RSSI(i));
      delay(5000);
    }
  }
 
}
