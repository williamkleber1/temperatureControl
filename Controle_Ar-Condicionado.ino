#define pin1 7
//#define pin2 6


void setup() {
  // put your setup code here, to run once:
  pinMode( pin1, OUTPUT);
//  pinMode( pin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(pin1) == LOW)
  {
      digitalWrite(pin1, LOW);
      delay(1000);
      digitalWrite(pin1, HIGH);
      delay(1000);

  }
  

}
