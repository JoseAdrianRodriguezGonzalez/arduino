int SENSOR; //Se declara el sensor en una entrada analogica

void setup() {
  Serial.begin(9600); //Se inicializa el monitor serie

}

void loop() {
 SENSOR =analogRead(A0);  //Se declara la entrada analogica
Serial.println(SENSOR);   //Se imprime lo que se lee en el sensor
delay(500);      //Con una demora de medio segundo
}
