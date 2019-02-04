#define pin1 7
int status = 0;
const int LM35 = A0; // Define o pino que lera a saída do LM35
float temperatura;
void setup() {
  pinMode(pin1,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  temperatura = (float(analogRead(LM35))*5/(1023))/0.01;
  Serial.print("Temperatura: ");
  Serial.println(temperatura);

  if((temperatura >= 30) && (status == 0)){
    digitalWrite (pin1, LOW);
    delay (2000);
    //digitalWrite (pin1, HIGH);
    //delay (2000);
    status = 1;
  }
  else if((temperatura < 23) && (status == 1)){
    digitalWrite (pin1, LOW);
    delay (2000);
    //digitalWrite (pin1, HIGH);
    //delay (2000);
    status = 0;
  }
   digitalWrite (pin1, HIGH);

}
