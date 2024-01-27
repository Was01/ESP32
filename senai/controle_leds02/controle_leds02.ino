#define out1 15
#define out2 4
#define out3 5

#define out1_time 400
#define out2_time 800
#define out3_time 400

int out1_time_save=0,
    out2_time_save=0,
    out3_time_save=0;

void setup() {
  pinMode(out1,OUTPUT);
  pinMode(out2,OUTPUT);
  pinMode(out3,OUTPUT);

  digitalWrite(out1,LOW);
  digitalWrite(out2,LOW);
  digitalWrite(out3,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
if((millis()-out1_time_save)>=out1_time){
    digitalWrite(out1,!digitalRead(out1));
    out1_time_save=millis();
  }
  
if((millis()-out2_time_save)>=out2_time){
    digitalWrite(out2,!digitalRead(out2));
    out2_time_save=millis();
  }

if((millis()-out3_time_save)>=out3_time){
    digitalWrite(out3,!digitalRead(out3));
    out3_time_save=millis();
  }
  
  
}
