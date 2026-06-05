//Incluo biblioteca
#include <WiFiManager.h>

//Objeto do Wifi do AP
WiFiManager wifiManager;

//Defino o pino d15
int LED = 15;

//Define o pino para reset das definicoes de wifi (D5)
int pino_reset = 5;

//Define o pino do led (D4)
int pino_led = 4;

//Defino a porta do servidor Web
WiFiServer server(80);

//Configurações iniciais *******************
void setup() {
  //Definindo que o sinal irá sair para ligar o led da placa
  pinMode(LED, OUTPUT);
  //Definindo que o interruptor irá receber um sinal
  pinMode(pino_reset, INPUT_PULLUP);
  //Pino de saída para ligar led
  pinMode(pino_led, OUTPUT);

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
  
  //Inicia o servidor web
  server.begin(); 
}

//Programa principal ***********************
void loop() {
  //Se o botão DE RESETfor pressionado
  if (digitalRead(pino_reset) == LOW) {
  
    digitalWrite(LED,LOW); //Apaga LED
    Serial.println("Abertura Portal"); //Abre o portal
    
    //Apaga os dados da rede wifi gravados na memoria e reinicia o ESP
    WiFiManager wifiManager;
    wifiManager.resetSettings();
    Serial.println("Configuracoes zeradas!");
    ESP.restart();  
  }

  if(WiFi.status()== WL_CONNECTED){ //Se conectado na rede      
    digitalWrite(LED,HIGH); //Acende LED para informar que entrou na rede       
  }else{
    digitalWrite(LED,LOW); //Apaga LED para informar que saiu da rede
    wifiManager.autoConnect();//Função para se autoconectar na rede caso caia    
  } 

  //pega os dados do cliente
  WiFiClient cliente = server.available();

  //Se tiver cliente conectado
  if (cliente) {
    String dados = ""; //Variável para guardar os dados vindos da web 
    while (cliente.connected()) { 
      if (cliente.available()) {  
        char c = cliente.read();
        dados += c;      

        //Se recebeu 1 na url
        if (dados.endsWith("GET /1")) {
          digitalWrite(pino_led,HIGH); //Liga o led
          //Finalizo a comunicação
          cliente.println("HTTP/1.1 200 OK");
          cliente.println("Content-type:text/html");
          cliente.println();
          cliente.stop();
        }

        //Se recebeu 0 na url
        if (dados.endsWith("GET /0")) {
          digitalWrite(pino_led,LOW); //Desliga o led
          cliente.println("HTTP/1.1 200 OK");
          cliente.println("Content-type:text/html");
          cliente.println();
          cliente.stop();
        }
      }
     } 
  }
}
  
