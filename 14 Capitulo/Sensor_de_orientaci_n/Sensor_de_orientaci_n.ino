int SENSOR = 2;   //Se declara la variable del sensor 
int LED = 3;      //Se declara el pin del LED
int ESTADO;     //Se declara la variabale ESTADO


void setup() {
pinMode(SENSOR, INPUT);     //Se declara el sensor como entrada
pinMode(LED, OUTPUT);     //Se declara al led como salida

}

void loop() {
 ESTADO=digitalRead(SENSOR); //Estado es igual a la lectura digital del sensor
 digitalWrite(LED, ESTADO);     //Se escribe digitalemte al led con el valor que sea lea en el estado
 delay(100);    //Con una demora de 100 milisegundos

}
