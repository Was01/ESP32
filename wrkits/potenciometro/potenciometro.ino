#define  pino_sensor 4
#define rele 32

void setup() {
  Serial.begin(115200);
  pinMode(pino_sensor,INPUT);
  pinMode(rele,OUTPUT);

}

void loop() {
  int leitura=analogRead(pino_sensor);
 float tensao=leitura*(3.3/4095.0);
  Serial.println(tensao);
  delay(500);
  if(tensao>1.0){
    digitalWrite(rele,HIGH);
  }
  else{
    digitalWrite(rele,LOW);
   }
  }
