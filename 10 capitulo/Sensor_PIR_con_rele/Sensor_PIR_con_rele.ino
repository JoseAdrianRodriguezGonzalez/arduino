int PIR=2;    //Se declara el sensor PIR
int RELE =3;      //Se declara el rele
int ESTADO =0;    //Se declara un estado en el que se entiende que no hay ningun estado leído al principio

void setup() {
  pinMode(PIR, INPUT);    //Se declara el PIR como entrada
  pinMode(RELE,OUTPUT);     //Se declara eql rele como salida
  delay(20000);     //Se estabiliza el sensor PIR con 20 segundos

}

void loop() {
  ESTADO = digitalRead(PIR);//El estado es igual a la lectura digital PIR
  if(ESTADO == HIGH){   //Si el estado es alto,entonces
    digitalWrite(RELE,LOW);   //Se activa el rele
  delay(4000);    //Con una demora de 4 segundos
  }else{
    digitalWrite(RELE,HIGH);      //Se apaga el rele
  }

}
