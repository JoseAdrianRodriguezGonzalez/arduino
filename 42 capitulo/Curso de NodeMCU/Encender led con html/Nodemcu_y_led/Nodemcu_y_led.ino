#include<ESP8266WiFi.h>
#include<WiFiClient.h>
  #define LedWifi D1

String Internet = " INFINITUMFC9B_2.4";    //Nombre del internet INFINITUM1101
String password = "P4YugE8pYK";    //Contraseña BG0D14aVzJ
int estado=0;   //Estado del led
WiFiServer server(80);  //Puerto en el que deebe de estar
void setup() {
  //inicia serial
  pinMode(LedWifi, OUTPUT);   //Se declara el led como salida
  Serial.begin(115200);   //115200 baudios de velocidad
  Serial.println("\n"); //Salto de línea
  //Conexión wifi
 WiFi.begin(Internet, password);    //Se incializa el wifi con los parametrso de ssid y de contraseña
 while(WiFi.status() != WL_CONNECTED){ //Si aún no se conecta y el conteo es menor que la maxima catndiad de intentos
  delay(500);   //Cada medio segundo
  Serial.println(".");  ///Pone un punto por cada intento
 }
Serial.println(""); //Salto de línea
//Si es menor el conteo
  //Se escriben los siguientes datos
  Serial.println("*******************************************************");//Escribe asteriscos
  Serial.print("Conectado a la red WiFi: ");    //Se escribe el texto
  Serial.println(WiFi.SSID());    //Se escribe el ssid
  Serial.print("IP: "); //Se escribe "ip"
  Serial.println(WiFi.localIP());   //Se escribe la IP
  Serial.print("macAdress: ");    //Se escribe el macadress
  Serial.println(WiFi.macAddress());    //Se escribe los datos
  Serial.println("*******************************************************");
server.begin();
digitalWrite(LedWifi, 0);   //Inicia en 0 el led
}

void loop(){
WiFiClient client= server.available();    //El wifi espera a que el servidor este disponible
if(!client){    //Si no hay cliente
  return;   //regresa
}
Serial.println("Nuevo Cliente..."); //Se escribe nuevo cliente
while(client.connected()&&!client.available()){   //Si el cliente está conectado y esta disponible
  delay(1);   //Manda cada 1 milisegundo
}
String peticion = client.readStringUntil ('\r');  //Se crea un string de petición que leerá la cadena de caracteres
Serial.println(peticion);   //Se imprime la petición
client.flush();   //Se vacia el cliente
if(peticion.indexOf('LED-ON') != -1)//Si petición esta led on
estado=1;   //Se enciende
if(peticion.indexOf('LED-OFF') !=-1)  //Si la petición esta apagado
estado=0;//lo apaga
digitalWrite(LedWifi, estado);//Escribe el estado en el led
client.println("HTTP/1.1 200 OK");    //Se escribe el tipo de documento
//Se crea un html
client.println("Content-Type: text/html");
client.println("");
client.println("");
client.println("");
client.println("");
//Inicia el html
client.println("<!DOCTYPE html> <html lang='en'> <head> <meta charset='UTF-8'> <meta http-equiv='X-UA-Compatible' content='IE=edge'> <meta name='viewport' content='width=device-width, initial-scale=1.0'>");
client.println( "<title>Encender led</title><style>.Cuerpo{ background-color: indigo;}.Juan{align-items: center;margin: 100;margin-left: 500px; margin-top: 75px; padding: 20px;border: 10px;");
client.println("border-radius: 30px;display: inline-block;box-shadow: 0px 10px 0px; background-color: khaki;.Pepe{font-size: 30px; font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif; text-align: center; }");
client.println(".jaime{margin-top: 30px;}");
 client.println("</style></head><body class='Cuerpo'> <div class='Juan'> <h1 class='Pepe'>Encendido de Leds</h1><div class='jaime'><button style='background-color:green;padding: 20px;border:30px;border-radius: 20px;margin-left: 20px; box-shadow: 20px;font-weight: 600;   font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana,' onclick=location.href='/LED-ON'> Encender</button>");
 client.println("<button style='margin-left: 50px; background-color: red;padding: 20px;border:30px; border-radius: 20px;box-shadow: 20px;font-weight: 700;font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana,' onclick=location.href='/LED-OFF'>apagar</button></div></div></body></html>");
delay(10);
//Se cierra la pagina
Serial.println("petición finalizada");
Serial.println("");

}
