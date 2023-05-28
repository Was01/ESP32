//semáfaro carro

int led1=18;
int led2=5;
int led3=4;

// semáfaro pedestre
int led4=12;
int led5=13;


void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);

}

void loop() {
  digitalWrite(led1,HIGH);
  digitalWrite(led4,HIGH);
  delay(10000);

  digitalWrite(led1,LOW);
  digitalWrite(led4,LOW);
 
  digitalWrite(led3,HIGH);
  digitalWrite(led5,HIGH);
  
  delay(5000);

  
  digitalWrite(led5,HIGH);
  digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
  delay(2000);

  digitalWrite(led5,LOW);
  digitalWrite(led2,LOW);
  
}
