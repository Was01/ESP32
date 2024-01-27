#define  pino_sensor 32
#define rele 4

void setup() {
  Serial.begin(115200);
  pinMode(pino_sensor,INPUT);


}

void loop() {
  int leitura=analogRead(pino_sensor);
 float tensao=leitura*(3.3/4095.0);
  Serial.println(tensao);
  delay(500);

  }
