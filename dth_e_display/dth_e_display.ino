#include <LiquidCrystal.h> // declara a utilização da biblioteca LiquidCrystal

#include "DHT.h"

#define Luz_Fundo  7
#define pin1 1 //pino do rele
#define DHTPIN A1 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11
 
// Conecte pino 1 do sensor (esquerda) ao +5V
// Conecte pino 2 do sensor ao pino de dados definido em seu Arduino
// Conecte pino 4 do sensor ao GND

DHT dht(DHTPIN, DHTTYPE);
 
 
//cria um objeto tipo LiquidCrystal que chamei de "lcd" nos pinos citados:
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int faltou_energia = true;
int ligado = false;

void comando_rele(){
    digitalWrite (pin1, LOW);
    delay(2000);
    digitalWrite (pin1, HIGH);

    ligado = !ligado;
}


void setup()
{
  lcd.begin(16, 2); // Iniciando o objeto "lcd" de 2 linhas e 16 colunas
  pinMode(Luz_Fundo,OUTPUT); //define o pino como saída
  digitalWrite(Luz_Fundo,HIGH); // Liga a luz do display.
  pinMode(pin1,OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  if(faltou_energia){
    comando_rele();
    faltou_energia = false;
  }
   // O atraso do sensor pode chegar a 2 segundos.
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // testa se retorno é valido, caso contrário algo está errado.
  if (isnan(t) || isnan(h))
  {
    Serial.println("Failed to read from DHT");
    lcd.setCursor(0,0); // seta o cursor para: (coluna = 0, linha = 0)
    lcd.print(" ERRO SENSOR");
  }
  else
  {
    if (t >= 30 && !ligado){
      comando_rele();
      delay(10000);
    }
    if (t <= 25 && ligado){
      comando_rele();
      delay(10000);
    }
    lcd.setCursor(0,0); // seta o cursor para: (coluna = 0, linha = 0)
    lcd.print("TEMP: ");
    lcd.print(t);
    lcd.setCursor(0,1); // seta para linha 1, ou seja, a linha de baixo
    lcd.print("");
    lcd.print("HUM: ");
    lcd.print(h);
    lcd.print(" ");
    if (ligado)
      lcd.print("on");
    else lcd.print("off");
  }

  
  
  
}
