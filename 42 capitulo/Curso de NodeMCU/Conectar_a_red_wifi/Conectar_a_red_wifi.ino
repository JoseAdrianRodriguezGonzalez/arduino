#include<ESP8266WiFi.h>
#include<Ticker.h>
Ticker tic_WifiLed;

void parpadeoLedWifi(){
  #define LedWifi D4
  byte estado=digitalRead(LedWifi);
  digitalWrite(LedWifi,!estado);
}
String Internet = " INFINITUM0803_2.4";    //Nombre del internet INFINITUM1101
String password = " V28ZRtdAEh";    //Contraseña BG0D14aVzJ
byte cont =0;   //Conteo
byte max_intense =100; //Máxima cantidad de intentos
void setup() {
  //inicia serial
  Serial.begin(115200);
  Serial.println("\n");
  //Conexión wifi
 WiFi.begin(Internet, password);    //Se incializa el wifi con los parametrso de ssid y de contraseña
 while(WiFi.status() != WL_CONNECTED and cont<max_intense){ //Si aún no se conecta y el conteo es menor que la maxima catndiad de intentos
  cont++; //Sigue intentandolo
  delay(500);   //Cada medio segundo
  Serial.println(".");  ///Pone un punto por cada intento
 }
Serial.println(""); //Salto de línea
//Si es menor el conteo
if(cont<max_intense){
  //Se escriben los siguientes datos
  Serial.println("*******************************************************");
  Serial.print("Conectado a la red WiFi: ");
  Serial.println(WiFi.SSID());
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("macAdress: ");
  Serial.println(WiFi.macAddress());
  Serial.println("*******************************************************");
  
}
else{   //Si no
  //No se conecta
  Serial.println("--------------------------------------------------------");
  Serial.println("Error de conexión");
  Serial.println("--------------------------------------------------------");
}
}
void loop(){
parpadeoLedWifi();
}
