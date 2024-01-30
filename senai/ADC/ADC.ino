

void setup() {
  pinMode(12,INPUT);
  Serial.begin(115200);

}

void loop() {
 int leitura=analogRead(12);
 Serial.print("A leitura ADC eh: ");
 Serial.println(leitura);
 delay(500);

}
