#define  pino_sensor 36

void setup() {
  Serial.begin(115200);
  pinMode(pino_sensor,INPUT);

}

void loop() {
  int leitura=analogRead(pino_sensor);
  Serial.println(leitura);
  delay(500);

}
