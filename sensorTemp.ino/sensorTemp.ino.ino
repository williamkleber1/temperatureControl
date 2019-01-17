#include <math.h> 
const int PinoSensor = 0;
float pad = 548; 
int ValorSensor = 0;
void setup(){
Serial.begin(9600);
}

float Thermistor(int N){
  long resistance;
  float temp;
  resistance =( (1024 * pad / N) - pad);
  temp = log(resistance);
  temp = 1 / (0.001129148 + (0.000234125 * temp) + (0.0000000876741 * temp * temp * temp));
  
  return temp -273.15;
}
void loop(){
ValorSensor = analogRead(PinoSensor);
Serial.print("Valor do Sensor = ");
Serial.println(ValorSensor);
delay(500);
}
