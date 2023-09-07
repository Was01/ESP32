#define  pino_sensor 32
#define rele 4

void setup() {
  Serial.begin(115200);
  pinMode(pino_sensor,INPUT);
  pinMode(rele,OUTPUT);


}

void loop() {
  int leitura=analogRead(pino_sensor);
 float tensao=leitura*(3.3/4095.0);
  Serial.println(tensao);
  
  if(tensao>1.5){
    digitalWrite(rele,HIGH);
  }
  else{
    digitalWrite(rele,LOW);
  }
  delay(500);
 }
