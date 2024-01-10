#include<ESP8266WiFi.h>
#include<Ticker.h>

  #define LedWifi D0
Ticker tic_WifiLed;

void parpadeoLedWifi(){
  byte estado=digitalRead(LedWifi);
  digitalWrite(LedWifi,!estado);
}
String Internet = "INFINITUMFC9B_2.4";    //Nombre del internet INFINITUM1101
String password = "P4YugE8pYK";    //Contraseña BG0D14aVzJ
byte cont =0;   //Conteo
byte max_intense =50; //Máxima cantidad de intentos
void setup() {
tic_WifiLed.attach(0.5,parpadeoLedWifi);
  //inicia serial
  pinMode(LedWifi, OUTPUT);
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
   tic_WifiLed.detach();
  digitalWrite(LedWifi,HIGH);
}
else{   //Si no
  //No se conecta
  Serial.println("--------------------------------------------------------");
  Serial.println("Error de conexión");
  Serial.println("--------------------------------------------------------");
}
}
void loop(){
//HLGPDF
}
