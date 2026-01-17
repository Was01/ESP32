

# define touchPin 4
# define ledPin 5
# define limite 400

int touchValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
  pinMode(ledPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<100;i++){
    touchValue+=touchRead(touchPin);
  }
  touchValue=touchValue/100;
  Serial.print(touchValue);
  if (touchValue<limite){
    digitalWrite(ledPin,HIGH);
    Serial.println("- Led Aceso");
  }
  else{
     digitalWrite(ledPin,LOW);
    Serial.println("- Led Apagado");
  }
  delay(500);
}
