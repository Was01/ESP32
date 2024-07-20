#define led1 15
#define led2 2

int freq=5000;
int resolucao=8;

void setup() {
    ledcAttach(led1,freq,resolucao);
    ledcAttach(led2,freq,resolucao);

}

void loop() {
  for(int i=0;i<256;i++){
    ledcWrite(led1,i);
    ledcWrite(led2,i);
    delay(50);
  }
  for(int i=256;i>0;i--){
    ledcWrite(led1,i);
    ledcWrite(led2,i);
    delay(50);
  }
}


