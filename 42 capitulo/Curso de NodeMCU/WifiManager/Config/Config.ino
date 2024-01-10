
#include"Config.h"

  #define LedWifi D0
WiFiServer server(80);  //Puerto en el que deebe de estar
int estado=0;
void setup() {
  conecta();
  pinMode(LedWifi,OUTPUT);
  //Conexión wifi
 Serial.println(""); //Salto de línea
//Si es menor el conteo  //Se escriben los siguientes datos
  Serial.println("*******************************************************");
  Serial.print("Conectado a la red WiFi: ");
  Serial.println(WiFi.SSID());
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("macAdress: ");
  Serial.println(WiFi.macAddress());
  Serial.println("*******************************************************");

server.begin();
digitalWrite(LedWifi,LOW);
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

}//HLGPDF
