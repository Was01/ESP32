void setup()
{
  pinMode(led,OUTPUT);
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
      Serial.println("Ligando LED");
      digitalWrite(led,HIGH);
    }
    else if (dados.indexOf("D1") >= 0)
    {
      Serial.println("Desligando LED");
      digitalWrite(led,LOW);
    }
    else if (dados.indexOf("I1") >= 0)
    {
      Serial.println("Invertendo LED");
      digitalWrite(led,!digitalRead(led));
    }
  }
}
