#include<SoftwareSerial.h>    //Se incluye la librería del SoftwareSerial
#include<DHT.h> //Se incluyen las librerías del DHT
#include<DHT_U.h>

SoftwareSerial D1(10,11);   //Se crea un objeto del tipo  "SoftwareSerial" llamado D1 en los pines Rx y Tx 
#define SENSOR 2  //Se define el pin del sensor
DHT dht(SENSOR,DHT11);    //Se crea un objeto del tipo DHT llamado dht poniendose el pin en el que esta y el modelo que es

void setup() {
  D1.begin(9600);   //Se incializa la comunicación del D1 a 9600 baudios
  D1.println("AT+RST");   //Se resetea el modulo
  delay(2000);    //Se demora 2 segundos
  D1.println("AT+CWMODE=1");   //Se escribe el comando a modo cliente
  delay(1000);    //Se demora 1 segundo
  D1.println("AT+CWJAP\"INIFINTUM\",\"V28ZRtdAEh\"");   //Se escoge la fuente de internet y el codigo
  delay(10000);   //Se demora 10 segundos
  D1.println("AT+CIPMUX=1");    //Se establece como multiples conexiones
  delay(1000);   //Se demora 1 segundo
  D1.println("AT+CIPSERVER=1,80");    //Activa  el servidor web a 80 digitos
  delay(1000);
}

void loop() {
 if(D1.available()){    //Si hay datos disponibles en el D1
  delay(1000);//Se demora 1 segundo
  if(D1.find("+IPD,")){       //Si D1 busca la cadena de "+IPD"
  int conexion=D1.read()-48; //Se hace la lectura del proximo caracter y el valor se asigna a la variable "conexion" los valores que tomen la lectura restada a 48, esto es debido a que esta codificado en ASCII, y el valor que debe de salir en este caso, es el de "una conexión" ya que el valor sería 0
  String pagina="<!doctype html><html><head><meta http-equiv=\"refresh\" content=\"15\"></head><body>";//Se hace una actualización de la página cada 15 segundos
  pagina+="<hl>Temperatura:";   //Se escribe un encabezado diciendo "temperatura"
  int TEMPERATURA= dht.readTemperature();   //Se crea una variable del tipo entera llamada "TEMPERATURA" que es igual a la lectura de la temperatura
  pagina +=String (TEMPERATURA);    //Se agrega a la página el valor de caracteres de la variable "TEMPERATURA"
  pagina+="<br>";   //Se hace un salto de línea
  pagina+="Humedad:"; //Se escribe despues del salto de línea "Humedad"
  int HUMEDAD =dht.readHumidity();    //Se crea una variable llamada "HUMEDAD" y lee la humedad
  pagina+=String(HUMEDAD);    //Se escribe en la página, la cadena de caracteres del valor entero de "HUMEDAD"
  pagina+="</hl></body></html>";    //Se cierra el primer encabezadp, el cuerpo, y el html

  String enviar="AT+CIPSEND=";      //Se crea una cadena de caracteres que se envía con el comando at
  enviar+=conexion;   //Se envía la variable conexion
  enviar+=",";  //Se envía una coma
  enviar+=pagina.length();    //Se envía el tamaño de la pagina
  D1.println(enviar); //Se envía toda la cadena de caracteres a la pagina
  delay(1000);  //Se hace una demora de 1 segundo
  D1.println(pagina);   //Se envía al servidor todo lo escrito en el string "pagina"
  delay(1000);    //Una demora de 1 segundo

   String cerrar="AT+CIPCLOSE=";    //Se cierra la cadena de carateres con el comando at
   cerrar+=conexion;    //Se almacena la "conexion"
   D1.println(cerrar);  //Se envía el string al servidor
   delay(2000); //Se demora 2 segundos
  }
 }
}
