#define Button D1   //Se declara el boton
#define LED D2    //Se declara el led
int ESTADO=1;     //Se declara una variable llamada estado que inicia apagado
int Newbutton =0;   //Se anidará el valor del botón según lo que lea el boton
int oldbutton=0;    //Se anidará el valor anterior del boton
void setup() {
Serial.begin(9600);   //Se inicializa el monitor serie
pinMode(Button, INPUT);   //Se declara el botón como entrada
pinMode(LED, OUTPUT);   //Se declara el led como salida
digitalWrite(LED, ESTADO);    //Se incializa el led apagado
}

void loop() {
  Newbutton=digitalRead(Button);    //Se anida la lectura del nuevo botón
  if(Newbutton!=oldbutton){   //Si el valor del nuevo botón no es igual al viejo
oldbutton=Newbutton;    //Se igualan
if(Newbutton==LOW){   //Si el bóton nuevo está encendido
 ESTADO=!ESTADO;    //EL estado cambia
 digitalWrite(LED, ESTADO);     //Se escribe en el led lo que hay en el estado
}
}

}
