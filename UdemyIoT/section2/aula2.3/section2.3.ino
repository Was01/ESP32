//Incluo biblioteca
#include <WiFiManager.h>

//Objeto do Wifi do AP
WiFiManager wifiManager;



//Define o pino para reset das definicoes de wifi
int pino_reset = 5;

//Configurações iniciais *******************
void setup() {
  //Definindo que o sinal irá sair para ligar o led da placa
  pinMode(15, OUTPUT);
  //Definindo que o interruptor irá receber um sinal
  pinMode(pino_reset, INPUT);

  //Especifico a comunicação com o monitor
  Serial.begin(115200); 

  //Cria um AP (Access Point) ("nome da rede", "senha da rede")
  wifiManager.setConfigPortalTimeout(240);
  if (!wifiManager.autoConnect("ESP32-WIFI-Was", "12345678")) {
    Serial.println(F("Falha na conexao. Resetar e tentar novamente..."));
    delay(3000);
    ESP.restart();
    delay(5000);
  }
  //Mensagem caso conexao Ok
  Serial.println(F("Conectado na rede Wifi."));
  Serial.print(F("Endereco IP: "));
  Serial.println(WiFi.localIP());
}

//Programa principal ***********************
void loop() {
  //Se o botão de reset for pressionado
  if (digitalRead(pino_reset) == LOW) {
  
    digitalWrite(15,LOW); //Apaga LED
    
    //Apaga os dados da rede wifi gravados na memoria e abre AP
    WiFiManager wifiManager;
    wifiManager.resetSettings();
    Serial.println("Configuracoes zeradas!");
    ESP.restart();  
  }

  if(WiFi.status()== WL_CONNECTED){ //Se conectado na rede      
    digitalWrite(15,HIGH); //Acende LED              
  }else{
    digitalWrite(15,LOW); //Apaga LED
    wifiManager.autoConnect();//Função para se autoconectar na rede caso caia    
  }

}