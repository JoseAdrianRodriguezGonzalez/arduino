 int SENSOR;    //Se crea una variable llamada "sensor del tipo entero
 float TEMPERATURA;   //Se crea una variable llamada "temperatura" del tipo "float"
 
 void setup() {
Serial.begin(9600);   //Se inicializa el monitor serie

}

void loop() {
  SENSOR=analogRead(A0);   // EL sensor leerá lo que está en el pin analogico "A0"
  TEMPERATURA=((SENSOR*5000.0)/1023)/10;    //Se hace un calcúlo de regla de tres del que la temperatura es igual a la lectura del sensor por 5 volts(en milivolts) entre 1023(rango de medida analogico)todo divido a entre 10 para tener grados centigrados
  Serial.println(TEMPERATURA,1);    //Se escribe la temperatura en el monitor serie con un parametro que indicará que solo se agrega un punto decimal
  delay(1000);    //Con una demora de 1 segundo

}
