# define pled 15


class Led{
  public:
  int pinoled;
  
  Led(int p){
    pinoled=p;
  }

  void trocaled(){
    digitalWrite(pinoled,!digitalRead(pinoled));
    delay(500);
   }
};
  
Led led(pled); 
 
void setup() {
  pinMode(pled,OUTPUT);
  digitalWrite(pled,LOW);

}



void loop() {
  led.trocaled();

}
