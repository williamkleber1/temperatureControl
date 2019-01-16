#include <boarddefs.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <IRremote.h>
#include <IRremoteInt.h>



// leds para debug
const int ledPin = 11;
const int ledPin2 = 10;

int khz = 38; // 38kHz frequência do protocolo NEC


IRsend irsend; // Objeto que controla o envio do comando IR


unsigned int irLigar[] = {8336, -4208, 600, -452, 620, -452, 620, -452, 620, -452, 620, -452, 620, -452, 620, -452, 620, -452, 620, -452, 624, -452, 616, -452, 620, -1660, 616, -1660, 620, -452, 620, -452, 620, -452, 620, -1660, 620, -1656, 620, -452, 620, -1680, 596, -452, 620, -476, 596, -452, 620, -456, 620, -452, 620, -472, 596, -456, 620, -472, 596, -1660, 620, -472, 600, -452, 628, -448, 620, -452, 620, -452, 620, -1676, 600, -1656, 620, -452, 620, -452, 620, -452, 620, -452, 620};





void onAr() {
  Serial.println("Ligando...");
  digitalWrite(ledPin2, HIGH);
  irsend.sendNEC(0xE8D008,32);
  Serial.println("Executando a 38 Hz");
  digitalWrite(ledPin2, LOW);
}





void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
}


void loop()
{

 
  
  onAr();
   
  delay(5000);
}
