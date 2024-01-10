#include<Wire.h>  //Incluye la librería de la comunicación I2C
#include <LiquidCrystal_I2C.h>  //Se uncluye la librería de liquidCrystal_I2C
#include<DHT.h>  //librerías del dht
#include<DHT_U.H>
#define SENSOR D3   //Se define el pin de dht}
#define LED D0
DHT dht(SENSOR,DHT11);    //Crea objeto del tipo dht que define el pin y el tipo de dht 
float temp, hum, hi;    //Se crean dos variables del tipo float
LiquidCrystal_I2C lcd(0x27, 16, 2);   //Se crea el objeto lcd, con la direccipon que tiene, su numero de colunmnas y filas
unsigned long tiempoAnterior;
void setup() {
  Serial.begin(9600);
  Wire.begin();   //Se inicializa el I2C
  lcd.init();   //Se incializa el lcd
  lcd.clear();    //Se limpia el lcd
  lcd.setBacklight(HIGH); //enciende el led de fondo
  dht.begin();  //Se inicializa el dht
  lcd.setCursor(4,0);   
  lcd.print("Bienvenido");
  lcd.setCursor(2,1);
  lcd.print("A nodeMCU");
  pinMode(LED, OUTPUT);
tiempoAnterior=millis();
}


void loop() {
if(Serial.available()){
  String cad= Serial.readString();
  digitalWrite(LED,cad.toInt());
}
  if((millis()-tiempoAnterior)>=8000){
    tiempoAnterior=millis();
 lcd.clear();  //Se limpia el lcd
  Serial.println(String(temp));
  hi=dht.computeHeatIndex(temp,hum);
  Serial.println(String(hi));
 temp=dht.readTemperature();  //Se lee la temperatura
 hum=dht.readHumidity();  //Se lee la humedad
 lcd.setCursor(0,0);  //Se coloca el cursor en el 0,0
 lcd.print("Temperat:"+String(temp)); //Se escribe "temperat:" con la temperatura
  lcd.setCursor(0,1); //Se pone el cursor en el 0,1
 lcd.print("Humedad:"+String(hum));   //Se escribe la humedad
}   
  }
