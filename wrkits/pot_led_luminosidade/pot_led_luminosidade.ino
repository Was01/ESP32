# define led 5
# define pino_sensor 36

int frequencia= 5000;
int canal= 0;
int resolucao=8;


void setup() {
  Serial.begin(115200);
  pinMode(pino_sensor,INPUT);
  
  //Configuração para o funcionamento do PWM no LED
  ledcSetup(canal,frequencia,resolucao);
  
  //Associando a GPIO ao canal escolhido PWM
  ledcAttachPin(led,canal);
}

void loop() {

 int leitura=analogRead(pino_sensor);
 Serial.println(leitura);
 ledcWrite(canal,leitura);
 delay(500);

}
