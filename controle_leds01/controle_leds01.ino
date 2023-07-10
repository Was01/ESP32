
#define out1 15
#define out2 4
#define out3 5

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
  digitalWrite(out1,!digitalRead(out1));
  digitalWrite(out2,!digitalRead(out2));
  digitalWrite(out3,!digitalRead(out3));
  delay(300);
}
