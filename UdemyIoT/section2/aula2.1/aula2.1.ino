//Para funcionar o WiFi
#include <WiFi.h>

const char* SSID = "***"; //Nome da rede WI-FI que deseja se conectar
const char* PASSWORD = "****"; //Senha da rede WI-FI que deseja se conectar

//Configurações iniciais *******************
void setup() {
  //Especifico a comunicação com o monitor
  Serial.begin(115200);
  //Fica em loop até conectar
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
      delay(100);
      Serial.println(".");
  } 
  //Mostro o IP obtido no monitor
  Serial.println("IP obtido: ");
  Serial.println(WiFi.localIP());
}

//Programa principal ***********************
void loop() {


}
