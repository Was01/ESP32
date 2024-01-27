#define  pino_sensor_temperatura 34


void setup() {
  Serial.begin(115200);
  }

void loop() {
  float leitura=analogRead(pino_sensor_temperatura);
  float voltage=leitura*(6.0/4095.0);
  float temp=voltage*100.0;
  Serial.print("Temperatura: ");
  Serial.print((unsigned)temp);
  Serial.println(" .C");
  delay(741);
  

 
  }
