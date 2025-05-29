#define led 15
#define btn 4

bool  lerbot;
int estado_btn;
void setup() {
  Serial.begin(115200);
  pinMode(led,OUTPUT);
   pinMode(btn,INPUT_PULLDOWN);
  digitalWrite(led,LOW);
}

void loop() {
  lerbot=digitalRead(btn);
  if(lerbot){
    estado_btn=1;
  }
  if(lerbot==0 && estado_btn==1){
    estado_btn=0;
    digitalWrite(led,!digitalRead(led));
  }
  Serial.println(lerbot);
  delay(100);
}
