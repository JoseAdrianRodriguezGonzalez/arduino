//Se incluyen las librerías del DHT
#include<DHT.h>
#include<DHT_U.h>
#include <LiquidCrystal_I2C.h>
/*D1=SCL
 * D2=SDA
 */
#include<Wire.h>
#include<ESP8266WiFi.h>

String Internet = "INFINITUMFC9B_2.4";    //Nombre del internet
String password = "P4YugE8pYK";    //Contraseña
int estado=0;   //Estado del led
WiFiServer server(80);  //Puerto en el que deebe de estar

LiquidCrystal_I2C lcd (0x27, 16, 2);  //Se crea un objeto del tipo "LiquidCrystal_I2C" llamado "lcd", con los siguientes parametros; dirección hexadecimal y cantidad de columnas y filas

#define SENSOR D4
float TEMPERATURA;
int HUMEDAD;
int hi; //Se crea una varaible de sensación termica
unsigned long start_time;
int pause=2000;
String Ip;
DHT dht(SENSOR, DHT11);   //Se crea un objeto del tipo DHT llamado dht
String IpAddress2String(const IPAddress& ipAddress){
return String(ipAddress[0]) + String(".") +\
String(ipAddress[1])+String(".") +\
String(ipAddress[2])+String(".") +\
String(ipAddress[3]);
}
boolean estado_impr=1;

void imprimir(){
  if(estado_impr){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(Internet);
  lcd.setCursor(0,1);
   lcd.print(Ip);
   }
   
  else{
    //Se escribe en el monitor serie la temperatura
  lcd.setCursor(0,0);
  lcd.print("Temp: ");  
  lcd.println(TEMPERATURA);
  //Se escribe la humedad 
  lcd.setCursor(0,1);
  lcd.print("Humedad: ");
  lcd.println(HUMEDAD);
    //Se escribe la sensación termica
  lcd.setCursor(8,0);
  lcd.print("Sensterm: ");
  lcd.setCursor(12,1);
  lcd.println(hi);

    
  }
  estado_impr= !estado_impr;
}
void leer (){
  TEMPERATURA=dht.readTemperature();    //Se lee la temperatura y se anida en la varialbe TEMPERATURA
  HUMEDAD=dht.readHumidity(); //Se la humedad y se anidad en la variable HUMEDAD
  hi=dht.computeHeatIndex(TEMPERATURA, HUMEDAD);  //Se opera la sensación termica con loss valores de TEMPERATURA y HUMEDAD
  imprimir();
  


    
}
void setup() {
Serial.begin(115200);
  lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Conectadno...");
 lcd.setCursor(0,1);
 lcd.print("Intento: ");
 int i=1;
   WiFi.begin(Internet, password);    //Se incializa el wifi con los parametrso de ssid y de contraseña
 while(WiFi.status() != WL_CONNECTED){ //Si aún no se conecta y el conteo es menor que la maxima catndiad de intentos
  delay(500);   //Cada medio segundo
  Serial.println(".");  ///Pone un punto por cada intento
 lcd.setCursor(10,1);
 lcd.print("       ");
 lcd.setCursor(10,2);
 lcd.print(String(i));
 i++;
 
 }
  
Ip= IpAddress2String(WiFi.localIP() );   //Se escribe la IP
imprimir();
  server.begin();
    Wire.begin();   //Se inicializa la conexión I2C
  lcd.init();
    lcd.clear();  //Se limpia la pantalla de cualquier texto
  lcd.setBacklight(HIGH); //Se enciende el foco trasero de la pantalla
  dht.begin();    //Se incializa el dht
start_time=millis();
Serial.println(WiFi.localIP());
}


void loop() {
  if(millis() -start_time >= pause){    //Demora
    start_time=millis();
    leer();
    
  }
 WiFiClient client= server.available();    //El wifi espera a que el servidor este disponible
if(!client){    //Si no hay cliente
  return;   //regresa
}
lcd.clear();
lcd.setCursor(0,0);
lcd.println("Nuevo Cliente..."); //Se escribe nuevo cliente

while(client.connected()&&!client.available()){   //Si el cliente está conectado y esta disponible
  delay(1);   //Manda cada 1 milisegundo
}
String peticion = client.readStringUntil ('\r');  //Se crea un string de petición que leerá la cadena de caracteres
//Serial.println(peticion);   //Se imprime la petición
client.flush();   //Se vacia el cliente
client.println("HTTP/1.1 200 OK");    //Se escribe el tipo de documento
//Se crea un html
client.println("Content-Type: text/html");
client.println("");
client.println("");
client.println("");
client.println("");
//Inicia el html
client.print("<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1.0'><title>Encender led</title>");
client.print("<style>.Cuerpo{background-color: indigo; }.Juan{font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif;     position: absolute;margin: 100;left: 50%;top: 50%;");
client.print("padding: 20px;border: 10px;width: 300px;border-radius: 30px;align-items: center;transform: translate(-50%,-50%); box-shadow: 0px 10px 0px;background-color: khaki; min-width: 300px;}</style></head><body class='Cuerpo'>");
client.print("<div class='Juan'><h2>Temperatura= "+String(TEMPERATURA)+"c</h2><h2>Humedad="+String(HUMEDAD)+"%</h2><h2>Sensación termica="+String(hi)+"c</h2></div></div><script>setInterval(function(){location.href = location.href;},1000*3);</script></body></html>");
//finaliza pagina
delay(10);

lcd.clear();
lcd.setCursor(0,0);
lcd.println("petición finalizada"); //Se escribe nuevo cliente 
//Serial.println("");

}
