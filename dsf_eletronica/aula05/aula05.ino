

#define led 15

int freq=5000;
int canal=0;
int resolucao=8;


void setup() {
  // put your setup code here, to run once:
  ledcAttachChannel(led,freq,resolucao,canal);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<256;i++){
   ledcWrite(led,i);
   delay(30);
  }

  for(int i=256;i>0;i--){
    ledcWrite(led,i);
    delay(30);
  }

}
