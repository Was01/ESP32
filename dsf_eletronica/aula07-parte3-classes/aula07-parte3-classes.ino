# define pinobot 4
# define pled 15

class Btn {
  public:
  bool lerbot, estadobot;
  int pino;
  
  Btn (int p){
    pino=p;
    lerbot=0;
    estadobot=0;
  }
  
  bool press(){
    lerbot=digitalRead(pino);
    if(lerbot){
      estadobot=1;
    }
    if(lerbot==0 && estadobot==1){
      estadobot=0;
      return true;
    }
    else 
      return false;
  }
};

class Led{
  public:
  int pinoled;
  
  Led(int p){
    pinoled=p;
  }
  
  void trocaled(){
    digitalWrite(pinoled,!digitalRead(pinoled));
  }
  
};

Btn btn(pinobot);
Led led(pled);

void setup() {
   pinMode(pinobot,INPUT_PULLDOWN);
   pinMode(pled,OUTPUT);
   digitalWrite(pled,LOW);

}

void loop() {
  if(btn.press()){
    led.trocaled();
  }

}
