

#define led 15
#define btn 4

bool  lerbot;

void setup() {
  Serial.begin(115200);
  pinMode(led,OUTPUT);
  pinMode(btn,INPUT_PULLDOWN);
  digitalWrite(led,LOW);
}

void loop() {
  lerbot=digitalRead(btn);
  if(lerbot){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
}
