
#define out1 2

void setup() {

  pinMode(out1,OUTPUT);
 


}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(out1,!digitalRead(out1));
 delay(300);

}
