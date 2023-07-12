int bot=5;
bool lerbot;

void setup() {
 
  Serial.begin(115200);
  pinMode(bot, INPUT_PULLUP);

}

void loop() {
 lerbot=!digitalRead(bot);
 Serial.println(lerbot);

  delay(100); // this speeds up the simulation
}
