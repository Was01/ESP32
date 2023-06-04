int bot=5;
int led=4;
bool lerbot;
bool lerantbot=0;
int estado=0;

void setup() {
 
  Serial.begin(115200);
  pinMode(bot, INPUT_PULLUP);
  pinMode(led,OUTPUT);

}

void loop() {
 lerbot=!digitalRead(bot);
 Serial.println(lerbot);
 if((lerbot==1)&&(lerantbot==0)){
   estado=estado+1;
   if(estado>1){
     estado=0;
   }
 }
 if(estado==0){
   digitalWrite(led,HIGH);
 }
 else if(estado==1){
   digitalWrite(led,LOW);
 }
 lerantbot=lerbot;
 delay(50);

 }
