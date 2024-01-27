# define led 5

int frequencia= 5;
int canal= 0;
int resolucao=16;


void setup() {
  Serial.begin(115200);
  pinMode(led,OUTPUT);
  //Configuração para o funcionamento do PWM no LED
  ledcSetup(canal,frequencia,resolucao);
  
  //Associando a GPIO ao canal escolhido PWM
  ledcAttachPin(led,canal);
}

void loop() {

 
    ledcWrite(canal,30000);
      }
