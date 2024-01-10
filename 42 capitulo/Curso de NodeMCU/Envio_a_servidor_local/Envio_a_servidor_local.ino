#include"Config.h"
#include<ESP8266HTTPClient.h>

String url=" http://192.168.1.69:7777/Arduino/Nodemcu/primer_paso/Prueba_recibo.php";
String device="tarjeta 1";
int temp=0;
int hum=0;
void setup() {
  // put your setup code here, to run once:
conecta();
}

void loop() {
  // put your main code here, to run repeatedly:
WiFiClient cliente;
HTTPClient http;
http.begin(cliente,url);
http.addHeader("Content-Type","application/x-www-form-urlencoded");
  temp=random(1,60);
  hum=random(10,95);
String postdata ="dispositivo=" + device +"&temperatura="+String(temp)+"&humedad="+String(hum);
int httpCode =http.POST(postdata);

String respuesta =http.getString();
Serial.println(httpCode);
Serial.println(respuesta);
http.end();
delay(5000);
}
