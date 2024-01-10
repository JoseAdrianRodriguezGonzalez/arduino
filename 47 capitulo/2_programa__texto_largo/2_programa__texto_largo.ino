#include<Wire.h>    //Se incluye la libreria de I2C
#include<Adafruit_GFX.h>  //Se incluye la librería para manipular el texto y graficos
#include<Adafruit_SSD1306.h>  //Se usa para el chip de la pantalla
#define ANCHO 128   //El ancho de la pantalla
#define ALTO 64 //El alto de la pantalla
#define OLED_RESET 4  //Se incluye el valor del reset
Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, OLED_RESET);  //Se crea un objeto llamado oled del tipo Adafruit_SSD1306, debe incluir los siguientes valores, ANCHO, ALTO, el I2C y el valor del reset
void setup() {
 Wire.begin();  //Se incializa el I2C
 oled.begin(SSD1306_SWITCHCAPVCC, 0X3c);  //Se incializa el oled, con el parametro de voltaje y de la dirección I2C
}


void loop() {
  oled.clearDisplay();    //Se limpia la pantalla
  oled.setTextColor(WHITE);   //Se escribe el color de la pantalla
  oled.setCursor(0,0);    //Se escribe la posicion del cursor
  oled.setTextSize(1);    //Se da el tamaño de la fuente
  oled.print("Texto en amarillo ocupa dos lineas, 16 px");   //Se escribe el texto
  oled.setCursor(0,16);  //Se indica la posicion del cursor
  oled.print(" Hola, este texto ya esta en la zona de color cyan y entran 6 líneas en total, mucha información en poco espacio!");    //Se escribe el texto
  oled.display();   //mostrar todos los datos

 }
