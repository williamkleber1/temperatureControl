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


unsigned int irLigar[] = {4450,-4400,550,-1650,550,-500,550,-1650,550,-1600,550,-550,550,-550,550,-1600,550,-550,550,-550,550,-1600,550,-550,550,-550,550,-1600,550,-1650,550,-500,550,-1650,550,-500,550,-1650,550,-550,550,-1600,550,-1600,550,-1650,550,-1600,550,-1650,550,-1600,550,-550,550,-1600,550,-550,550,-550,550,-550,550,-550,550,-500,550,-550,550,-1600,550,-1650,550,-1600,550,-550,550,-550,550,-550,550,-500,550,-1650,550,-500,550,-550,550,-550,550,-1600,550,-1650,550,-1600,550,-1650,550};





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
