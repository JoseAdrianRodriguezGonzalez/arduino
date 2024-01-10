#include <IRremote.h>   //Incluye la librería del sensor

int SENSOR =7;    //Se crea una variable entera denominada "sensor" conectado en el pin 7

void setup(){
  Serial.begin(9600);   //Se inicializa el monitor serie
  IrReceiver.begin(SENSOR);   //Se inicializa la recpeción de datos del modulo
}

void loop(){
  while(IrReceiver.decode()==0){
    
  }
  Serial.println(IrReceiver.decodedIRData.command);
    delay(500);
    IrReceiver.resume();
}
