#define led 4

char acionaLed=0;

void setup() {

  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(led, OUTPUT);
}

void loop() {
  if(Serial.available()>0){
    acionaLed=Serial.read();
  }
    if(acionaLed=='l'){
      digitalWrite(led,OUTPUT);
      Serial.print(acionaLed);
      Serial.println(" - Led´s on ....");
    }
    if(acionaLed=='d'){
        digitalWrite(led,LOW);
        Serial.print(acionaLed);
        Serial.println(" - Led´s off ....");
    }
}
