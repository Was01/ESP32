#define led 5

char acionaLed=0;

void setup() {
  Serial.begin(115200);
  pinMode(led,OUTPUT);

}

void loop() {
if(Serial.available()>0){
  acionaLed=Serial.read();
}

  if(acionaLed=='l'){
    digitalWrite(led,HIGH);
    Serial.print(acionaLed);
    Serial.println(" - Led ligado");
  }

  if(acionaLed=='d'){
    digitalWrite(led,LOW);
    Serial.print(acionaLed);
    Serial.println(" - Led desligado");
  }

}
