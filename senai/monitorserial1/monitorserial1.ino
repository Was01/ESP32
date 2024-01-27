int led1=5;
int led2=4;

void setup()
{
  pinMode(led1,OUTPUT);
   pinMode(led2,OUTPUT);
  Serial.begin(115200);
  Serial.println("ESP32");
}

void loop()
{
  if (Serial.available() > 0)
  {
    String dados = "";
    char c;
    while (Serial.available() > 0)
    {
      c = Serial.read();
      if (c != '\r' && c != '\n' && isAscii(c))
      {
        dados.concat(c);
      }
      delay(2);
    }
    Serial.print("Serial: ");
    Serial.println(dados);
    Serial.flush();
    
    if (dados.indexOf("L1") >= 0)
    {
      Serial.println("Ligando LED1");
      digitalWrite(led1,HIGH);
    }
    else if (dados.indexOf("D1") >= 0)
    {
      Serial.println("Desligando LED1");
      digitalWrite(led1,LOW);
    }
    else if (dados.indexOf("I1") >= 0)
    {
      Serial.println("Invertendo LED");
      digitalWrite(led1,!digitalRead(led1));
    }

   if (dados.indexOf("L2") >= 0)
    {
      Serial.println("Ligando LED2");
      digitalWrite(led2,HIGH);
    }
    else if (dados.indexOf("D2") >= 0)
    {
      Serial.println("Desligando LED1");
      digitalWrite(led2,LOW);
    }
    else if (dados.indexOf("I2") >= 0)
    {
      Serial.println("Invertendo LED2");
      digitalWrite(led2,!digitalRead(led2));
    }


  }
}
