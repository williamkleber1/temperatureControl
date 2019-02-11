#define pin1 7

const unsigned long SEGUNDOS = 1000;
const unsigned long HORA = 3600*SEGUNDOS;

int faltou_energia = 1;

void comando_rele(){
    digitalWrite (pin1, LOW);
    delay(2000);
    digitalWrite (pin1, HIGH);
}

void setup() {
  pinMode(pin1,OUTPUT);
  Serial.begin(9600);
}


void loop() {
  if(faltou_energia){
    
    comando_rele();
    faltou_energia = 0;
    delay(4*HORA);
  }

  else{
    comando_rele();
    delay(HORA);
    comando_rele();
    delay(4*HORA);
  }
  
  
}
