 int LEDROJO = 9;   //Se declara el pin en donde esta el LEDROJO
 int LEDVERDE = 10; //Se declara el pin en donde esta el LEDVERDE
 int LEDAZUL = 11; //Se declara el pin en donde esta el LEDAZUL


 void setup(){
  pinMode(LEDROJO, OUTPUT);   //Se declaran como salida todos los leds
  pinMode(LEDVERDE, OUTPUT);
  pinMode(LEDAZUL, OUTPUT);
 }
void setup(){   //Se escriben de manera analogica los valores de los colores que se quieren ver
//Led Rojo   
   analogWrite(LEDROJO, 255);
   analogWrite(LEDVERDE, 0);
   analogWrite(LEDAZUL, 0);
   delay(2000);
   //Led verde
   analogWrite(LEDROJO, 0);
   analogWrite(LEDVERDE, 255);
   analogWrite(LEDAZUL, 0);
   delay(2000);

   //Led azul
   analogWrite(LEDROJO, 255);
   analogWrite(LEDVERDE, 0);
   analogWrite(LEDAZUL, 0);
   delay(2000);
}
