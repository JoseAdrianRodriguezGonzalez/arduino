#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include<Servo.h>
Servo servo1;


RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  servo1.attach(2);
}

void loop() {
  if (radio.available()) {
    int angulo;
    radio.read(&angulo, sizeof(angulo));
    servo1.write(angulo);
    Serial.println(angulo);
  }
}
