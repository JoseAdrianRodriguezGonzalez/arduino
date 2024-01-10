 int SENSOR;    //Se crea una variable llamada "sensor"
 float TEMPERATURA;   //Se crea una variable del tipo "float" llamada "TEMPERATURA"
 float SUMA;    //Se crea una variable llamada "suma" del tipo "float"
 void setup() {
Serial.begin(9600);   //Se inicializa el monitor serie

}

void loop() {
  SUMA =0;    //Se empieza la suma desde cero
  for(int i=0; i<5; i++){   //Se inicia un bucle for de limite 5 
     SENSOR=analogRead(A0);   //Lee lo que hay en el pin analogico "A0"
  TEMPERATURA=((SENSOR*5000.0)/1023)/10; //Temperatura es igual a sensor por 5000 entre 1023 entre 10
  SUMA=TEMPERATURA +SUMA; //Suma es igual a la temperatura más suma, ya que se añade el valor almacenado con anterioridad
  delay (500);    //Demora de medio segundo
  }
 
  Serial.println(SUMA/5.0,1);   //Se imprime el promedio de las 5 temperaturas
 

}
