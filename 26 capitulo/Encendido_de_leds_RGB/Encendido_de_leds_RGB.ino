#include <IRremote.h>     //Se incluye la librería de IRremote
#define Boton_1 0x9716BE3F    //Se hace una directvia al compilador, en que cada vez que ocurra el boton_1, se intercambie por el codigo hexadecimal
#define Boton_2 0x3D9AE3F7    //Se define el boton 2
#define Boton_3 0x6182021B    //Se define el boton 3


int LED_ROJO = 2;   //Se definene las variables de los leds como enteros
int LED_VERDE =3;
int LED_AZUL =4;    
int SENSOR =11; //Se define al variable del sensor
IRrecv irrecv(SENSOR);    //Se crea un objeto del tipo IRrecv llamado irrecv con el parametro de "sensor" como receptor
decode_results codigo;    //Crea un objeto del tipo "decode_results" llamado codigo,  que se encarga de decodificar los valores 



void setup(){
   Serial.begin(9600);    //Se inicializa el monitor serie
 irrecv.enableIRIn();   //Se inicializa el receptor
 pinMode( LED_ROJO, OUTPUT);    //Se declaran los leeds como salidas
 pinMode( LED_VERDE, OUTPUT);
 pinMode( LED_AZUL, OUTPUT);
;
}

void loop(){
  if (irrecv.decode(&codigo)){      //Se consulta si hay datos decodificados ya disponibles  
  Serial.println(codigo.value, HEX);    //Se escribe el codigo y el valor en hexadecimal
  if(codigo.value == Boton_1)   //Si codigo  y el valor es igual al boton 1
  digitalWrite(LED_ROJO, !digitalRead(LED_ROJO));   //Se escribe a le led rojo el estado contrario en el que lee al led
   if(codigo.value == Boton_2)     //Si codigo  y el valor es igual al boton 2
  digitalWrite(LED_VERDE, !digitalRead(LED_VERDE));   //Se escribe a le led verde el estado contrario en el que lee al led
   if(codigo.value == Boton_3)     //Si codigo  y el valor es igual al boton 3
  digitalWrite(LED_AZUL, !digitalRead(LED_AZUL));   //Se escribe a le led azul el estado contrario en el que lee al led
  irrecv.resume();    //Permite resumir los codigos o bien, su adquisición
  }
  delay(100);   //Demora 100 milisegundos
}
