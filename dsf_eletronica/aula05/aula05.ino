#define led 15

int freq=5000;
int resolucao=8;




void setup() {
  ledcAttach(led,freq,resolucao);
}
  



void loop() {
  for (int i=0;i<256;i++)
  {
    ledcWrite(led,i);
    delay(30);
  }
  for(int i=256;i>0;i--)
  {
    ledcWrite(led,i);
    delay(30);
  }
}

