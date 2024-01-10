#define Button D1     //Se declara el botón
#define LED D2    //Se declara el LED
#define LED1 D5   
int ESTADO=0;   //Se crea una variable Estado que empieza en 0
//Se crean dos variablees, new button y old button, donde anidarán los valores leídos de los botones
int Newbutton =0;  
int oldbutton=0;
void setup() {
Serial.begin(9600);   //Se incializa el monitor serie  
pinMode(Button, INPUT);   //Se declara el botón como salida
//Se declara los leds como salida
pinMode(LED, OUTPUT);   
pinMode(LED1,OUTPUT);
enciendeleds();   //Se incializa la función de "enciendeled()"
}

void loop() {
 Boton();   //Se activa la función "botón()"
 
}
void enciendeleds(){
  switch(ESTADO){   //Se crea un switch del estado
    case 0:   /*Si está en 0
    Se mantienen apagado los leds*/
    digitalWrite(LED, 0);
    digitalWrite(LED1, 0);
    break;
       case 1:  //Si está en 1
       /*Se enciende el LED
        */
    digitalWrite(LED, 1);
    digitalWrite(LED1, 0);
    break;
       case 2:    //Si está en 2
       //El LED1 se enciende
    digitalWrite(LED, 0);
    digitalWrite(LED1, 1);
    break;
       case 3:    //Si está en 3
         //Se encienden ambos leds
    digitalWrite(LED, 1);
    digitalWrite(LED1, 1);
    break;
  }
}
void Boton(){
   Newbutton=digitalRead(Button);   //Se lee el botón y se anida en "QNewbutton
  if(Newbutton!=oldbutton){   //Si Newbutton no es igual a oldbutton
oldbutton=Newbutton;    //Se igualan
if(Newbutton==LOW){     //Si el newbutton se activa
  ESTADO++;   //El estado se incrementa
  if(ESTADO>3)    //Si es mayor que 3
  ESTADO=0;   //Se torna el estado a 0
  enciendeleds();       //Se activa la función "enciendeleds()"
}
}

}
