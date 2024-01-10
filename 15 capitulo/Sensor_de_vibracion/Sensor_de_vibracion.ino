int SENSOR = 2;   //Se declara el sensor 
int LED = 3;      //Se declara el LED
int ESTADO;     //Se declara la variable "estado"
void setup(){
  pinMode(SENSOR, INPUT);   //Se declara al sensor como entrada
  pinMode(LED, OUTPUT);     //Se declara al LED como salida
}
void loop(){
  ESTADO = digitalRead(SENSOR);   //Estado es igual a la lectura digital del sensor
  if(ESTADO == LOW){      //Si es estado es bajo
  digitalWrite(LED, HIGH);    //El led se encenderá
  delay (500);    //demora medio segundo
  }
  digitalWrite(LED, LOW);   //Se apaga
}
