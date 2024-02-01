#define led1 15
#define led2 2

#define freq 5000
#define canal 0
#define resolucao 10

void setup()
 {

  ledcSetup (canal,freq,resolucao);
  ledcAttachPin(led1,canal);
  ledcAttachPin(led2,canal);

}

void loop() 
{
  for(int i=0;i<1024;i++)
  {
    ledcWrite(canal,i);
    delay(30);
  }

  for(int i=1023;i>=0;i--)
  {
    ledcWrite(canal,i);
    delay(30);
  }
}
