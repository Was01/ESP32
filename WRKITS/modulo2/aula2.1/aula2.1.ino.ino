#define OUT1 15
#define OUT2 4
#define OUT3 5

#define OUT1_INTERVAL 300
#define OUT2_INTERVAL 200
#define OUT3_INTERVAL 400

unsigned long lastTime1 = 0;
unsigned long lastTime2 = 0;
unsigned long lastTime3 = 0;

void setup() {
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  pinMode(OUT3, OUTPUT);
}

void loop() {
  unsigned long now = millis();

  if (now - lastTime1 >= OUT1_INTERVAL) {
    digitalWrite(OUT1, !digitalRead(OUT1));
    lastTime1 = now;
  }

  if (now - lastTime2 >= OUT2_INTERVAL) {
    digitalWrite(OUT2, !digitalRead(OUT2));
    lastTime2 = now;
  }

  if (now - lastTime3 >= OUT3_INTERVAL) {
    digitalWrite(OUT3, !digitalRead(OUT3));
    lastTime3 = now;
  }
}