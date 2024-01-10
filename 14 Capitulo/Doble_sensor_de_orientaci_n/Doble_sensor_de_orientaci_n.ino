int SENSOR_DERECHO =2;      //Se declara el sensor derecho
int LED_DERECHO =3;   //Se declara el led derecho

int SENSOR_IZQUIERDO =4;    //Se declara el sensor izquierdo
int LED_IZQUIERDO =5;       //Se delclara el led izquierdo
int ESTADO_DERECHO;     //Se declara la variable "ESTADO_DERECHO"
int ESTADO_IZQUIERDO;   //Se declara una variable llamada "ESTADO_IZQUIERDO"


void setup() {
  pinMode(SENSOR_DERECHO,INPUT);    //Se declaran los sensores como entrada
  pinMode(LED_DERECHO, OUTPUT);     //Se declaran los leds como salidas
  pinMode(SENSOR_IZQUIERDO,INPUT);
  pinMode(LED_IZQUIERDO, OUTPUT);
}

void loop() {
  ESTADO_DERECHO=digitalRead(SENSOR_DERECHO);     //El Estado derecho es igual a la lectura del  sensor derecho
  digitalWrite(LED_DERECHO,ESTADO_DERECHO);     //Se escribe en el led derecho el valor leído en el estado derecho
  delay(100);   //Demora de 100 milisegundos
  ESTADO_IZQUIERDO=digitalRead(SENSOR_IZQUIERDO);//El Estado izquierdo  es igual a la lectura del  sensor izquierdo
  digitalWrite(LED_IZQUIERDO,ESTADO_IZQUIERDO);   //Se escribe en el led izquierdo el valor leído en el estado izquierdo
  delay(100);    //demora de 100 milisegundos

}
