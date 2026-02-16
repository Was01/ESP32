

#define SENSOR_PIN 35

void setup() {
  // Aumentamos a estabilidade iniciando o Serial com um pequeno delay
  Serial.begin(115200);
  delay(500); 
  Serial.println("Lendo sensor...");
}

void loop() {
  int leitura = analogRead(SENSOR_PIN);
  
  // Conversão para Voltagem (Considerando 12 bits e 3.3V)
  float voltagem = (leitura / 4095.0) * 3.3;

  Serial.print("Valor ADC: ");
  Serial.print(leitura);
  Serial.print(" | Voltagem: ");
  Serial.print(voltagem);
  Serial.println("V");

  delay(500);
}
