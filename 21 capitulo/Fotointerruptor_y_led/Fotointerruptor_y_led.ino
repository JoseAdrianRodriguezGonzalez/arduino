
volatile int CONTADOR = 1000;   //Se usa la variable global y se define con un valor de 1000
void setup() {
  pinMode(13,OUTPUT);   //Se declara el pin del LED y se declara como salida
  attachInterrupt(digitalPinToInterrupt(2), sensor, RISING);//Se inicializa la interrucpión, se usa el indice del pin,se crea el objeto del tipo ISR llamado "sensor" y se coloca el modo en el que se va a leer la interrupción
  
  

}

void loop() {
  digitalWrite(13, HIGH);     //    Se enciende el led
  delay(CONTADOR);    //Aplica una demora de la variable del contador
  digitalWrite( 13, LOW);   //Se apaga el led
  delay(CONTADOR);    //Se demora con la variable del contador
  if(CONTADOR < 100){//Se irá reduciendo la variable y cuando llegue a un valor menor que 100
    CONTADOR = 1000;//Se regresará a un valor de 1000
  }

}
void sensor (){
  CONTADOR =CONTADOR-100;   //Contador disminiyue con cada interrupción a 100
}
