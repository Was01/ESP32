#include "BluetoothSerial.h"

// Verifica se o Bluetooth está habilitado no core
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled!
#endif

BluetoothSerial SerialBT;
String device_name = "ESP32-BT-Slave";

#define led 5

char acionaLed = 0;

void setup() {
  Serial.begin(115200);
  SerialBT.begin(device_name);

  Serial.println("O dispositivo ja pode ser pareado!");

  pinMode(led, OUTPUT);
}

void loop() {
  // Se houver dados chegando via Bluetooth
  if (SerialBT.available()) {
    acionaLed = SerialBT.read();

    // FILTRO: Só imprime caracteres "imprimíveis" (letras, números, símbolos)
    // O valor 32 é o 'Espaço' e 126 é o '~' na tabela ASCII
    if (acionaLed >= 32 && acionaLed <= 126) {
      Serial.write(acionaLed);
    }
    // Se for um "Enter" (Quebra de linha), pula a linha no monitor
    else if (acionaLed == '\n' || acionaLed == '\r') {
      Serial.println();
    }
  }
  delay(10);  // Pequeno delay para estabilidade
  if (acionaLed == 'l') {
    digitalWrite(led, HIGH);
    Serial.println(" - Led ligado");
  }

  if (acionaLed == 'd') {
    digitalWrite(led, LOW);
    Serial.println(" - Led desligado");
  }
}