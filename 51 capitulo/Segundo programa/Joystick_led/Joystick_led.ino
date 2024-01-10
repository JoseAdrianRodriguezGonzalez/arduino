#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>
#define led 12
RF24 radio(7,8);
const byte direcciones[][6]={"00001","00002"};
boolean Estadoboton= 0;
void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  radio.begin();
  radio.openWritingPipe(direcciones[1]);
  radio.openReadingPipe(1,direcciones[0]);
  radio.setPALevel(RF24_PA_MIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(5);
  radio.stopListening();
  int pot=analogRead(A0);
  int angulo= map(pot,0,1023,0,180);
  radio.write(&angulo,sizeof(angulo));
  delay(5);
  radio.startListening();
  while(!radio.available());
  radio.read(&Estadoboton,sizeof(Estadoboton));
  if(Estadoboton==HIGH){
    digitalWrite(led,HIGH);
  }else{
    digitalWrite(led,LOW);
  }
}
