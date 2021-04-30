#include <LiquidCrystal.h> // declara a utilização da biblioteca LiquidCrystal

#include "DHT.h"

#define Luz_Fundo  7
#define DHTPIN A1 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11
 
// Conecte pino 1 do sensor (esquerda) ao +5V
// Conecte pino 2 do sensor ao pino de dados definido em seu Arduino
// Conecte pino 4 do sensor ao GND

DHT dht(DHTPIN, DHTTYPE);
 
 
//cria um objeto tipo LiquidCrystal que chamei de "lcd" nos pinos citados:
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char horas[4] = "tem";
char minu[4];
char temp[7]="00h00m";

char* tempo(int segundos){
  int h = 0;
  int m = 0;
  while(segundos >= 3600){
    h =+ 1;
    segundos -= 3600;
  }

  while(segundos >= 60){
    m =+ 1;
    segundos -= 60;
  }

  sprintf(minu, "%d", m);
  sprintf(horas, "%d", h);

  temp[0] = horas[0];
  temp[1] = horas[1];
  temp[3] = minu[0];
  temp[4] = minu[1];
  Serial.println(temp);
  return temp;
}
void setup()
{
  lcd.begin(16, 2); // Iniciando o objeto "lcd" de 2 linhas e 16 colunas
  pinMode(Luz_Fundo,OUTPUT); //define o pino como saída
  digitalWrite(Luz_Fundo,HIGH); // Liga a luz do display.
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  
  dht.begin();
}

void loop()
{

   // O atraso do sensor pode chegar a 2 segundos.
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // testa se retorno é valido, caso contrário algo está errado.
  if (isnan(t) || isnan(h))
  {
    Serial.println("Failed to read from DHT");
  }
  else
  {
    Serial.print("Umidade: ");
    Serial.print(h);
    Serial.print(" %t");
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.println(" *C");
  }

  
  lcd.setCursor(0,0); // seta o cursor para: (coluna = 0, linha = 0)
  lcd.print(" teste lcd");
  lcd.setCursor(0,1); // seta para linha 1, ou seja, a linha de baixo
  lcd.print("");
  lcd.print(tempo(millis()/1000)); // escreve os segundos passados.
  
}
