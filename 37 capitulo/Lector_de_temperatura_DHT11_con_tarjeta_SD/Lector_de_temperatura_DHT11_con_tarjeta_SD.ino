#include <SPI.h>    //Se incluye la librería de la comunicación SPI
#include <SD.h>   //Se incluye la librería de la tarjeta SD
#include <DHT.h>    //Se incluye la librería de DHT del sensor
#include<DHT_U.h>   //Se incluye la librería DHT_U
#define SENSOR 2    //Se define al sensor como una constante llamada "SENSOR" EN EL PIN2
int TEMPERATURA;    //Se declara una variable llamada TEMPERATURA
int HUMEDAD;    //Se crea una variable llamada HUMEDAD

#define SSpin 10    //Se define al SSpin en el pin de 10 para el selector de esclavo de la comunciación SPI de la tarjeta SD

File archivo;   //Se crea un bojeto del tipo file llamado "archivo"
DHT dht(SENSOR, DHT11);   //Se crea un objeto del tipi DHT llamado "dht" con los parametros de pin y el tipo de dht que es
void setup() {
Serial.begin(9600);   //Se inicia la comunicación serie 
dht.begin();    //Se inicia el sensor dht

Serial.println("Inicializando tarjeta...");   //Se escribe en el monitor serie "Inicializando tarjeta..."
if(!SD.begin(SSpin)){ //Si la inicialización del SD es correcta, o en su defecto, incorrecta 
  Serial.println("fallo en inicialización");  //Si es incorrecta,el monitor serie escribirá "fallo en inicialización" 
  return;   //Y se queda estancado 
}
Serial.println("inicialización correcta");  //Si es correcta, el monitor serie escribirá "inicialización correcta"
archivo= SD.open("TH.txt", FILE_WRITE); //El archivo, abrirá y creará un documento llamado "TH.txt", y con la función "FILE_WRITE"

if (archivo) {    //Entramos a un condicional if del archivo si es correcto.... Si es incorrecto...
  for(int i=1; i < 31; i++){    //Y se crea un bucle for con un limite de 31 datos distinctos que dichos, se escibirán en el archivo TH.txt
    TEMPERATURA =dht.readTemperature();   //TEMPERATURA= a la lectura de la temperatura
    HUMEDAD = dht.readHumidity();  //HUMEDAD es igual, a la lectura de humedad 
    //ARCHIVO
    archivo.print(i); //En el acrhivo se escribira el numero de veces
    archivo.print(","); //Se escribiran comas para diferenciarlo
    archivo.print(TEMPERATURA); //Se escribe el valor de la TEMPERATURA
    archivo.print(","); //Se escribe una coma para diferenciarlo
    archivo.println(HUMEDAD); //Se escribe el valor leído en HUMEDAD
    //Monitor serie
    Serial.print(i);    //En el monitor serie, se escribe el valor de vez
    Serial.print(",");    //Se escribe una coma
    Serial.print(TEMPERATURA);    //Se escribe el valor leído en TEMPERATURA
    Serial.print(",");  //Se escribe una coma
    Serial.println(HUMEDAD);    //Se ecribe el valor leído en HUMEDAD
   delay(1000); //Las veces que lo haga será en cada segundo
    
  }
  archivo.close();  //El archivo se cierra
  Serial.println("escritura correcta"); //Si es correcto, se escribe "escritura correcta"
      }else{//Si no es correcto
        Serial.println("error en apertura de datos.txt");     //Se escribe "error en apertura de datos.txt"
      }
}
void loop() {
//nada por aquí

}
