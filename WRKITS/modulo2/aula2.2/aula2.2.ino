#define pino_led1 8
#define pino_btn1 12

#define pino_led2 9
#define pino_btn2 2

static bool flag1=false;
static bool flag2=false;
 
// Protótipo da função (ajustado para void)
void trocaEstadoLed(int, int,bool &);

void setup() {
  Serial.begin(9600);
  pinMode(pino_btn1, INPUT_PULLUP); // Resistor interno: HIGH = solto, LOW = pressionado
  pinMode(pino_led1, OUTPUT);
  
  pinMode(pino_btn2, INPUT_PULLUP); // Resistor interno: HIGH = solto, LOW = pressionado
  pinMode(pino_led2, OUTPUT);
}

void loop() {	
  // Passamos os dois pinos como argumentos
  trocaEstadoLed(pino_led1, pino_btn1,flag1);
  trocaEstadoLed(pino_led2,pino_btn2,flag2);
}

void trocaEstadoLed(int led, int btn,bool &flag) {
 
  // Como usamos INPUT_PULLUP: LOW significa pressionado
  bool pressionado = (digitalRead(btn) == LOW);

  // Se o botão for pressionado, levantamos a bandeira (flag)
  if (pressionado) {
    flag = true;
  } 
  
  // Se o botão for solto (pressionado == false) E a flag estiver ativa
  if (!pressionado && flag == true) {
    digitalWrite(led, !digitalRead(led)); // Inverte o estado atual do LED
    flag = false; // Reseta a flag para o próximo clique
  }
}
