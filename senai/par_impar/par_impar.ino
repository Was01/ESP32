#define led_vermelho 4
#define led_verde 5

void setup()
{
 pinMode(led_vermelho,OUTPUT);
  pinMode(led_verde,OUTPUT);
  Serial.begin(115200);

  digitalWrite(led_vermelho,LOW);
  digitalWrite(led_verde,LOW);
}


void loop()
{
  if (Serial.available() > 0)
  {
    String numero = "";
    char num;
    int n;
    
    while (Serial.available() > 0)
    {
      num = Serial.read();
      if (num != '\r' && num != '\n' && isAscii(num))
      {
        numero.concat(num);
      }
      delay(2);
    }
    Serial.print("\nNumero: ");
    Serial.println(numero);
    Serial.flush();
    n=numero.toInt();
    if(n%2==0){
      Serial.println("Par");
      digitalWrite(led_vermelho,LOW);
       digitalWrite(led_verde,HIGH);
     }
     else{
        Serial.println("Impar");
        
      digitalWrite(led_vermelho,HIGH);
       digitalWrite(led_verde,LOW);
      }
  }
}
