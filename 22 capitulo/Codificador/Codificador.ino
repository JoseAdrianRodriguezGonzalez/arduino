int A =2;   //DT 
int B = 4;    //CLK
int ANTERIOR = 50;    //Guarda el ultimo numero de la variable posición
volatile int POSICION =50;    //La variable que se usará para determinar la posición


void setup() {
 pinMode(A, INPUT);   //Se declara a como b como entradas
 pinMode( B, INPUT);    

 Serial.begin(9600);    //Se inicializa el monitor serie

  attachInterrupt(digitalPinToInterrupt(A), encoder, LOW);//Se inicializa las interrupciones haciendo que  se inicie la interrupciones con el pin a, llamadno a al ISR como encoder y teniendo en un estado bajo 
  Serial.println("Listo");    //Se imprime en la pantalla la palabra "listo cunado inicie

}

void loop() {
if (POSICION != ANTERIOR){    //Evaluará si anterior es diferente a posición, tornandolo en algo verdadero
  Serial.println(POSICION);   //Se escribirá el valor de posición en el monitor
  ANTERIOR = POSICION;    //Y actualizamos el valor de anterior
}

}

void encoder(){
  //Efectua una rutina anti rebote
  static unsigned long ultimaInterrupcion = 0;    //Se crea una interrupción llamada"ultima", en la que deifne la ultima interrupción que se haga tiene que ser estatico para que cuando el codigo salga de la función, no se destruya el valor
unsigned long tiempoInterrupcion = millis();    //Se define un tiempo de interrupción en milis    Usa un longitud de 32 bits el unsigned long o variable sin signo 
  if(tiempoInterrupcion-ultimaInterrupcion > 5){    //Crea un efecto antirebote de 5 milisegundos
   if (digitalRead(B) ==HIGH){    //Si se lee que el b(o CLK) está en alto o sea, horario
    POSICION++;   //La posición aumenta
   }
   else{
POSICION--;//Si es antihorario,  se disminuyendo
   }
POSICION=min(100,max(0,POSICION));    //Es esto es la posición base y la miníma
   
   ultimaInterrupcion = tiempoInterrupcion;   //Actualiza la ultima interrupión con el valor de tiempo interrupción 
}
}
