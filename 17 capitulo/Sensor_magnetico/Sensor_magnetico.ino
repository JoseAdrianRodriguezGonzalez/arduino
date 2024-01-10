int SENSOR;   //Se declara el sensor 

void setup(){
Serial.begin(9600);   //Se inicializa el monitor serie

}

void loop() {
  SENSOR = analogRead(A0);    //Se declara el pin analogico en el que esta el sensor
  if (SENSOR< 500 || SENSOR >600){    //Si sensor es menor a 500 o mayor a 600
    Serial.print("Campo detectado: ");  //Se escribe que esta un campo detectado
  }
  Serial.println(SENSOR);   //Escribirá en el monitor lo que mide en el sensor
  delay(500);   //Tomará una demora medio segundo

}
