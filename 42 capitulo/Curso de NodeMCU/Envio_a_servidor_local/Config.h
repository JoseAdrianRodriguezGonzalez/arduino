#include<ESP8266WiFi.h>   //Trabajar coon la placa

//Para trabajar con wifimANger
#include <strings_en.h>
#include <WiFiManager.h>    
#include<DNSServer.h>   //Crea un servidor
#include<ESP8266WebServer.h>
#include<Ticker.h>
#define pinLed D4
void conecta(){
  Serial.begin(115200);
//creamos una instancia en la clase WiFiManager
WiFiManager wifiManager;

//Descomenter para resetear configuracion 
 // wifiManager.resetSettings();
 
 //Creamos AP y portal cautivo
 //Pregunta si está conectado
 wifiManager.autoConnect("ESP8266");
 Serial.println("Estás conectado");
}
