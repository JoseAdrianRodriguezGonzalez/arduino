 int LEDROJO = 9;   //Se declaran los pines de los leds
 int LEDVERDE = 10;
 int LEDAZUL = 11;

 void setup(){      //Se declara los leds como salidas
  pinMode(LEDROJO, OUTPUT);
  pinMode(LEDVERDE, OUTPUT);
  pinMode(LEDAZUL, OUTPUT);
 }
void loop(){    //Para escribir menos, se crea una función llamada Micolor 
 //amarillo
  miColor(255, 255,128 );//Valores de un color en el orden que viene en el void
   delay(2000);
   miColor(0, 255,255);   //celeste
   delay(2000);
   miColor(255,0,255);    //rosado
   delay(2000);
}void miColor(int rojo, int verde, int azul){     //La función Micolor tiene el orden de int rojo,int verdad e int azul
   analogWrite(LEDROJO, rojo);    //Se escriben los colores de cada una con su función asociada al color entero
    analogWrite(LEDVERDE, verde);
     analogWrite(LEDAZUL, azul);
}
  
