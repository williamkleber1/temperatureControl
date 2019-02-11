#define pin1 7
#define DESLIGADO 0
#define LIGADO 1
#define RESETADO -1

//variavel para saber o status do arcondicionado
int arcondicionado = RESETADO;

//variavel para saber o status do rele
int rele = DESLIGADO;

const int LM35 = A0; // Define o pino que lera a saída do LM35
float temperatura;
void setup() {
  pinMode(pin1,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //recebe a temperatuda, pelo sensor lm35
  temperatura = (float(analogRead(LM35))*5/(1023))/0.01;
  Serial.print("Temperatura: ");
  Serial.println(temperatura);

  /*caso tenha faltado energia, quando voltar o ar vai ligar
  independente da temperatura atual*/
  if(arcondicionado == RESETADO){
    digitalWrite (pin1, LOW);
    delay(2000);
    arcondicionado = LIGADO;
    rele = LIGADO;
  }
  /*agora vamos analisar as temperaturas*/

 /*caso a sala esteja com temperatura acima de 29 graus, e o ar esteja desligado,ligaremos ele*/
  else if((temperatura >= 30) && (arcondicionado == DESLIGADO)){
    digitalWrite (pin1, LOW);
    delay (2000);
    arcondicionado = LIGADO;
    rele = LIGADO;
  }

  /*se a temperatura estiver abaixo de 23, e o ar estiver ligado, desligamos ele*/
  else if((temperatura < 23) && (arcondicionado == LIGADO)){
    digitalWrite (pin1, LOW);
    delay (2000);
    arcondicionado = DESLIGADO;
    rele = LIGADO;
  }

  /*se tivermos acionado o rele, para manipular o ar, desligamos ele*/
  if(rele == LIGADO){
    digitalWrite (pin1, HIGH);
    rele = DESLIGADO;
  }

}