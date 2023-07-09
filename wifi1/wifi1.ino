
#include <WiFi.h>

const char* ssid="was"; //rede
const char* password="*****";//senha

void setup() {
 Serial.begin(115200);
 //conectar
 WiFi.begin(ssid,password);

 //Aguardando conexão
 Serial.println();
 Serial.println("Conectando");
 while(WiFi.status ()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
 }
 Serial.println("");
 Serial.println("WiFi conectado");


 // Envia ip através da UART
 Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
