void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(35, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 int leitura=analogRead(35);
 Serial.print("\nA leitura ADC eh: ");
 Serial.println((leitura*3.3)/4095);
 delay(1000);
}