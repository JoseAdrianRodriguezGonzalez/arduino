  volatile int CONTADOR = 0;    //Se almacenará el numero de la interrupción. La variable "volatile" se coloca como "global",porque está dentro de una función y está en el loop
int ANTERIOR = 0;   //Se almacena el número previo a contador 
void setup() {
 Serial.begin(9600);    //Se inicializa el monitor serie
 attachInterrupt(digitalPinToInterrupt(3), sensor, RISING);   //Se inicializa la interrupción ,primero,colocando el indie del pin,luego, se coloca el nombre del "sensor", y depues se coloca el modo

}

void loop() {
  if(ANTERIOR != CONTADOR){   //Evaluará como correcto cuando existe una diferencia de contador
    Serial.println(CONTADOR);   //Se imprime la variable contador en el monitor serie
   ANTERIOR = CONTADOR;   //evaluara falso si es igual
  }
}


void sensor(){
  CONTADOR++;   //EL contador se va incrementado
}
