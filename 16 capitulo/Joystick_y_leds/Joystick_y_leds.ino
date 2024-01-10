int X;    //Se declara la variable del eje x en un pin analogico
int Y;      //Se declara la vairable del eje y
int LED_IZQUIERDO = 3;  //Se declaran los LEDS
int LED_DERECHO =  5;
int LED_ABAJO = 6;
int LED_ARRIBA = 9;
int PULSADOR = 10;    //Se declara el pulsador del joystick
int LED_SW = 11;    //Se declara el led del pulsador
int SW;    //Se declara la variable del puslador
void setup() {
 pinMode(LED_IZQUIERDO, OUTPUT);    //Se declaran todos los leds como salidas
 pinMode(LED_DERECHO, OUTPUT);
 pinMode(LED_ABAJO, OUTPUT);
 pinMode(LED_ARRIBA, OUTPUT);
 pinMode(LED_SW, OUTPUT);
 pinMode(PULSADOR, INPUT);    //Se declara a el pulsador como entrada
}

void loop() {
  X = analogRead(A0);   //Se declara el pin analogico del eje x
  Y = analogRead(A1);    //Se declara el pin analogico del eje y
  SW = digitalRead(PULSADOR);   //Se declara el pulsador
  if ( X >=0 && X < 480){   //Se consulta si la posición esta en ese rango de datos
    analogWrite(LED_IZQUIERDO, map(X, 0, 480, 255, 0));   //Se convierten los datos del joystick al brillo del led
  }else{
    analogWrite(LED_IZQUIERDO,0);       //Si no comprende en estos rangos,se apaga
  }
  if ( X >520 && X < 1023){  //Se consulta si esta entre el rango 520 a 1023
    analogWrite(LED_DERECHO, map(X, 1023, 520, 255, 0));    //Se crean los parametros
  }else{
    analogWrite(LED_DERECHO,0);//Se apaga si no esta entre estos rangos
  }
  if ( Y >=0 && Y < 480){ //Se consulta si en el eje y esta de 0 a 480
    analogWrite(LED_ABAJO, map(X, 0, 480, 255, 0));   //Se crean los parametros de conversion
  }else{
    analogWrite(LED_ABAJO,0);   //Se apaga si no esta entre este rango
  }
  if ( Y >520 && Y < 1023){   //Se consulta si está entre estos rangos
    analogWrite(LED_ARRIBA, map(Y, 520, 1023, 0,255));    //Se crean los parametros de conversión
  }else{
    analogWrite(LED_ARRIBA,0);    //Se apaga si no esta entre esos rangos
  }
 digitalWrite(LED_SW, !SW); //Se escribe en el led lo contrario de lo que diga en la pulsación, por lo que, siempre esta encendida, si esta apagado, el led se enciende
 
}
