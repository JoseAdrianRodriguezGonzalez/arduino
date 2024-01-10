#include <Adafruit_NeoPixel.h>    //Se incluye la librería NeoPixel

Adafruit_NeoPixel tira = Adafruit_NeoPixel(8, 2, NEO_RGB + NEO_KHZ800);   //Se crea un objeto del tipo Adafruit_NeoPixel,llamado"tira" y con los siguientes parametros
// Primer paramaetro=cantidad de la pixeles en la tira
//Segundo parametro= pin de conexión a arduino
//Tercer parametro
// NEO_KHZ800  800 KHz velocidad de datos(WS2812 y nuevos)
// NEO_KHZ400  400KHz velocidad de datos(WS2811 y nuevos)
//NEO_GRB flujo de datos en orden GRB (WS2812 y nuevos)
//NEO_RGB flujo de datos en orden RGB (versiones más antiguas)
void setup() {
  tira.begin();   //Se inicializa la tira
  tira.show();    //Se muestra lo que hay 
}

void loop() {
  tira.setBrightness(20);   //Se establece un valor de brillo
  for(int i = 0; i < 8; i++){   //Bucle for que hará que enciendan todos los leds cada uno 
    tira.setPixelColor(i,0,0,255);    //La función setPixelColor requiere de 4 parametros, el  primero es la posición, los otros valores que tomarán serán el orden de los colores, ya sea RGB o GRB
   tira.show();//Se muestra lo que hay dentro del programa
    delay(500);   //Demora de medio segundo
    tira.setPixelColor(i,0, 0, 0 );   //Se apaga de uno en uno cada pixel
    tira.show;    //Show es la función que mostrará todo lo que hay en el programa
  }
  tira.setBrightness(20);     //Se ajusta el brillo
  for(int i = 7; i >=0; i--){ //Se disminuyen  de 7 hasta 0, es decir, empieza desde el ultimo led hasta el primero y se va decrementando
    tira.setPixelColor(i,255,0,0);  //Se enciende el rojo
    tir.show();   //Se muestra lo que está en el programa
    delay(500);   //Con una demora de medio segundo
    tira.setPixelColor(i,0, 0, 0 );   //Se apaga el pixel
    tira.show;    //Se muestra lo que hay en escrito dentro del programa
  }
}
