#include <Ubidots.h>
#include<DHT.h>
#include<Servo.h>
#define DEVICE_LABEL "ejc-main-esp8266"
#define UBIDOTS_TOKEN "BBFF-eWrZtRLNsfS16CCLCbd7Ec9A7C0BcL" 
#define LAB_LED "led"
#define LAB_SER "servo"
#define LAB_TEMP"temp"
#define LAB_HUME "hume"
#define PIN_LED D3
#define PIN_SERVO D1
const char* WIFI_SSID="INFINITUM0952";
const char* WIFI_PASS="4Qa7g5RgCb"; 
float temp;
int hume,servo,led;
Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);
DHT dht(D2,DHT11);
Servo mot;
void setup() {
  // put your setup code here, to run once:
  
  mot.attach(PIN_SERVO);
  Serial.begin(115200);
  dht.begin();
  ubidots.wifiConnect(WIFI_SSID,WIFI_PASS); 
  temp=0;
  hume=0;
  led=0;
  servo=0;
  pinMode(PIN_LED,OUTPUT);
  digitalWrite(PIN_LED,led);
  mot.write(servo);
}

void loop() {
  servo=ubidots.get(DEVICE_LABEL,LAB_SER);
  if(servo!=ERROR_VALUE){
    Serial.println("Valor del servo: " +String(servo));
    mot.write(servo);
  }
  else{
    Serial.println("Error de lectura");
  }
  led=ubidots.get(DEVICE_LABEL,LAB_LED);
  if(led!=ERROR_VALUE){
    Serial.println("Valor del servo: " +String(led));
    digitalWrite(PIN_LED,led);
  }
  else{
    Serial.println("Error de lectura");
  }
  // put your main code here, to run repeatedly:
  /*var_pot=analogRead(A0);
  Serial.println(var_pot);
  */
  temp=dht.readTemperature();
  hume=dht.readHumidity();
  ubidots.add(LAB_TEMP,temp);
  ubidots.add(LAB_HUME,hume);
  ubidots.add(LAB_SER,servo);
  ubidots.add(LAB_LED,led);
  bool buffersent=false;
  buffersent =ubidots.send( DEVICE_LABEL);
  if(buffersent){
    Serial.println("valores enviados correctamente");
  }
  delay(1000);
}
