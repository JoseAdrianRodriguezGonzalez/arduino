#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>
#include<Servo.h>

#define boton 4
RF24 radio(7,8);
const byte direccion[][6]={"00001","00002"};
Servo servo1;
boolean botonestado=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(boton,INPUT);
  servo1.attach(5);
  radio.begin();
  radio.openWritingPipe(direccion[0]);
  radio.openReadingPipe(1,direccion[1]);
  radio.setPALevel(RF24_PA_MIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(5);
  radio.startListening();
  if(radio.available()){
    while(radio.available()){
      int angulo=0;
      radio.read(&angulo,sizeof(angulo));
      servo1.write(angulo);
    }
    delay(5);
    radio.stopListening();
    botonestado=digitalRead(boton);
    radio.write(&botonestado,sizeof(botonestado));
  }

}
