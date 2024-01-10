int RELE = 2;   //Se declara el pin del relé
void setup(){
  pinMode(RELE, OUTPUT);    //Se inicializa al rele como salida
}
void loop (){
  digitalWrite(RELE, LOW);      //Se enciende el rele porque el normalmente abierto esta abierto
  delay(5000);      //Demora 5 segundos
  digitalWrite(RELE, HIGH);     //Se apaga el rele
  delay (5000);     //Se de demora el relé 5 segundos
}
