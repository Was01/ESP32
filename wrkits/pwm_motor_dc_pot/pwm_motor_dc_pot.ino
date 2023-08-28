#define pot 4
#define motor_dc 5

void setup() {
  Serial.begin(115200);
  pinMode(pot,INPUT);
  pinMode(motor_dc,OUTPUT);
  int canal=6;
  int freq=1000;
  int resolucao=16;
  ledcAttachPin(motor_dc,6);
  ledcSetup(canal,freq,resolucao);
  
}
void loop() {
  int leitura=map(analogRead(pot),0,4095,0,65535);
  Serial.println(leitura);
  ledcWrite(6,leitura);
  delay(500);

}
