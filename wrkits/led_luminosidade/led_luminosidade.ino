
# define led 5

int frequencia= 5000;
int canal= 0;
int resolucao=8;


void setup() {
  Serial.begin(115200);
  //Configuração para o funcionamento do PWM no LED
  ledcSetup(canal,frequencia,resolucao);
  
  //Associando a GPIO ao canal escolhido PWM
  ledcAttachPin(led,canal);
}

void loop() {

  for(int i=0;i<=255;i++){
    Serial.println(i);
    ledcWrite(canal,i);
    delay(30);
  }
   for(int i=255;i>=0;i--){
     Serial.println(i);
    ledcWrite(canal,i);
    delay(30);
  }

}
