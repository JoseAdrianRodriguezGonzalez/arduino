void setup() {
 pinMode(2,INPUT);    //Se declara el pulsador como entrada
 pinMode(3,OUTPUT);   //Se declara el led como salida

}

void loop() {
  if(digitalRead(2) ==HIGH){      // Se presiona el pulsador dando alto
    digitalWrite(3, HIGH);      //Se enciende el led
  }
  else{
    digitalWrite(3, LOW);   //Si no se presiona el pulsador, se pagará el led
  }
}
