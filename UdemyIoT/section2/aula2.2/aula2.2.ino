//Para funcionar o WiFi
#include <WiFi.h>
 
const char* SSID = "***"; //Nome da rede WI-FI que deseja se conectar
const char* PASSWORD = "****"; //Senha da rede WI-FI que deseja se conectar
 
//Configuração da rede
IPAddress ip(192,168,0,199);
IPAddress gateway(192,168,0,1);
IPAddress subnet(255,255,255,0);
 
//Defino o pino que funciona o LED que vem na placa
int led = 15;

void setup() {
  //Definindo que o sinal irá sair para ligar o led da placa
  pinMode(led, OUTPUT);

  //Especifico a comunicação com o monitor
  Serial.begin(115200);

  //Passo as configurações
  WiFi.begin(SSID, PASSWORD);
  WiFi.config(ip, gateway, subnet);
 
  //Conectando
  while (WiFi.status() != WL_CONNECTED) { //ENQUANTO STATUS FOR DIFERENTE DE CONECTADO
    delay(500); //INTERVALO DE 500 MILISEGUNDOS
    Serial.print("."); //ESCREVE O CARACTER NA SERIAL
  }

  //Mostrando os dados da conexão
  Serial.println(""); //PULA UMA LINHA NA JANELA SERIAL
  Serial.print("Conectado a rede sem fio "); //ESCREVE O TEXTO NA SERIAL
  Serial.println(SSID); //ESCREVE O NOME DA REDE NA SERIAL
  Serial.println(WiFi.localIP()); //ESCREVE NA SERIAL O IP RECEBIDO DENTRO DA REDE SEM FIO
}

void loop() {
  //Se estiver conectado no wifi acende o led
  if(WiFi.status()== WL_CONNECTED){     
    digitalWrite(led,HIGH); //Acende LED              
  }else{ //se desconectar
    digitalWrite(led,LOW); //Apaga LED    
  } 
}
