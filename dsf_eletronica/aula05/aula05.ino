#define led 15

int freq=5000;
int canal=0;
int resolucao=8;

void configuracao();


void setup() {
  configuracao();

}

void loop() {
  for(int i=0;i<256;i++)
  {
    ledcWrite(canal,i);
    delay(15);
  }

   for(int i=255;i>=0;i--)
  {
    ledcWrite(canal,i);
    delay(30);
  }

}

void configuracao()
{
  ledcSetup(canal,freq,resolucao);
  ledcAttachPin(led,canal);
}