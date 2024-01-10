int SENSOR = 2;   //Se declara el sensor 
int LED = 3;      //Se declara el LED
int ESTADO;     //Se declara la variable "estado"
void setup(){
  pinMode(SENSOR, INPUT);   //Se declara al sensor como entrada
  pinMode(LED, OUTPUT);     //Se declara al LED como salida
}


void loop() {
  ESTADO= digitalRead(SENSOR);      //Se lee el sensor
  digitalWrite(LED, !SENSOR);     //Se escribe lo contrario a lo que el estado este, ergo, si es el sensor esta apagado se encendera

}
