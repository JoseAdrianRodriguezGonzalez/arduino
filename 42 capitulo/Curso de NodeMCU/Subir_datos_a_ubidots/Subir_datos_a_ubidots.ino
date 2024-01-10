#include <Ubidots.h>//Librería de ubidots
/*Código unico de ubidotss y el nombre del internet y contraseña*/
const char* UBIDOTS_TOKEN ="BBFF-eWrZtRLNsfS16CCLCbd7Ec9A7C0BcL";
const char* WIFI_SSID="INFINITUM0952";
const char* WIFI_PASS="4Qa7g5RgCb"; 
/*Se creea obejto para poner el codigo unico y lel tipo de protocolo que maneja*/
Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);
int var_pot;//Potenciometro
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);//Monitor serie
  ubidots.wifiConnect(WIFI_SSID,WIFI_PASS);//Se conecta a la red internet 
  var_pot=0;//Empieza e potencimeto con un0 
}

void loop() {
  // put your main code here, to run repeatedly:
  /*Lectura del potenciometro*/
  var_pot=analogRead(A0);
  Serial.println(var_pot);
  /*Manda ls datos*/
  ubidots.add("var_pot",var_pot);
  bool buffersent=false;
  buffersent =ubidots.send();
  if(buffersent){
    Serial.println("valores enviados correctamente");
  }
  delay(1000);
}
