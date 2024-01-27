#define motor_dc 5

void setup() {
  pinMode(motor_dc,OUTPUT);
  int canal=6;
  int freq=1000;
  int resolucao=16;
  ledcAttachPin(motor_dc,6);
  ledcSetup(canal,freq,resolucao);
}
void loop() {
  ledcWrite(6,65535);

}
