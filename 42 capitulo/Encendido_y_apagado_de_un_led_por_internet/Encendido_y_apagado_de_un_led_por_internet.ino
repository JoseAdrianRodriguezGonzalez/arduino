#include<SoftwareSerial.h>    //Se incluye la comunicación del monitor serie
SoftwareSerial D1 (10,11);    //Se crea un objeto del tipo "softwareSerial" denominado "D1" con los pines de Rx y Tx
#define LED 2   //Se define el led en el pin 2
void setup() {
 D1.begin(9600);    //Se crea la comunicación entre el modulo
pinMode(LED,OUTPUT);  //Se establece en el compilador  como salida el LED
    //Se escriben automaticamente los comandos "AT"
D1.println("AT+CWMODE=1");  //Se establece en modo de "cliente"
delay(1000);    //  Se espera un segundo
D1.println("AT+CWJAP=\"Infinitum\",\"V28ZRtdAEh\"");    //Se selecciona la conexión de internet
delay(10000);   //Se esperan 10 segundos
D1.println("AT+CIPMUX=1");    //Se establece como "conexiones multiples"
delay(1000);    //Se espea un segundo
D1.println("AT+CIPSERVER=1,80");    //Activa el servido web con 80 digitos
delay(1000);    //Se espera un segundo 

}

void loop() { 
if(D1.available()){   //Se consulta si hay información disponible en el modulo D1
delay(1000);      //Se espera un segundo
if(D1.find("+IPD,")){//Si D1 busca la cadena de"+IPD"
int conexion=D1.read()-48;    //Se hace la lectura del proximo caracter y el valor se asigna a la variable "conexion" los valores que tomen la lectura restada a 48, esto es debido a que esta codificado en ASCII, y el valor que debe de salir en este caso, es el de "una conexión" ya que el valor sería 0
if(D1.find("led =")){   //Si D1 busca la cadena "led="
int lectura=D1.read()-48;   //Se lee D1 y se guarda su valor en la variable "lectura" y en dicho se resta a el valor 48 o 0

String pagina ="<!doctype html><html><head><body>";   //Se crea la estrucutra tipíca del html,
if(lectura ==1){    //Si el led esta en uno
  digitalWrite(LED,HIGH);   //El led se enciende
  pagina +="<h1>LED=encendido</h1><html><head></head><body>";   //Se crea en el encabezado 1 el titulo "LED=encendido" se cierra el encabezado, se abre el html se abre el encabezado, se cierra el encabezado y se abre el cuerpo
  
}
else if (lectura==0){   //Si el led está en 0
  digitalWrite(LED,LOW);    //El led se apaga
  pagina += "<h1>LED=apagado</h1></body></html>";    //Se escribe en el encabezado h1 "LED=apagado" se cierra el encabezado 1, se abre el cuerpo y se cierra el html
  
}
String enviar="AT+CIPSEND=";    //Se crea una cadena de caracteres  en losa cuales,con el comando "CIPSEND" envía todos los datos
enviar+=conexion;   //Se envía la informacion en la variable "enviar"
enviar+=",";    //Se separa con una coma
enviar+=pagina.length();  //Se escribe la longitud de la pagina
D1.println(enviar);   //D1 escribe la variable de "enviar"
delay(1000);    //Demora un segundo
D1.println(pagina);   //Envía lo que hay en la variable "página"
delay(1000);

String cerrar = "AT+CIPCLOSE=";    //Se crea un String en el que cierra la pagina
cerrar+=conexion;   //Se agrega el número de conexión
D1.println(cerrar);   //Se envía el comando
delay(2000);  //Demora 2 segundos
      }
    }
  }

}
