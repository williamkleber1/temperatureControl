#define pin1 7
#define LIGADO 1
#define DESLIGADO 0

//status do arcondicionado
int status = DESLIGADO;

const int LM35 = A0; // Define o pino que lera a saída do LM35

float temperatura; // Variável que armazenará a temperatura medida

void setup() {
  
  pinMode( pin1, OUTPUT);
  Serial.begin(9600); // inicializa a comunicação serial

}

void loop() {
  temperatura = (float(analogRead(LM35))*5/(1023))/0.01;
  Serial.print("Temperatura: ");

  Serial.println(temperatura);

  if(temperatura >= 30 && status == DESLIGADO)
  {
      digitalWrite(pin1, LOW);
      delay(1000);
      digitalWrite(pin1, HIGH);
      delay(1000);
      status = LIGADO;

  }

  if(temperatura <= 23 && status == LIGADO)
  {
      digitalWrite(pin1, LOW);
      delay(1000);
      digitalWrite(pin1, HIGH);
      delay(1000);
      status = DESLIGADO;

  }
  

}
