#define btn 15
#define led 2

int estado_botao=0;

void setup() {
  pinMode(led,OUTPUT);
  pinMode(btn,INPUT);

  digitalWrite(led,LOW);

}

void loop() 
{
  if(digitalRead(btn))
    estado_botao=1;
  if((!digitalRead(btn))&& estado_botao)
  {
    estado_botao=0;
    digitalWrite(led,!digitalRead(led));

  }
  
}
