#include <SPI.h>    //Se incluye la librería de la comunicación SPI
#include <SD.h>   //Se incluye la librería SD, para las funciones asociadas a dicha librería

#define SSpin 10    //Se define una constante llamada ""slave select" en el que estará conectado en el pin 10

File archivo;   //Se crea un objeto del tipo "File" llamado "archivo"

void setup() {
Serial.begin(9600);   //Se inicializa la comunicación serie 
Serial.println("Inicializando tarjeta...");   //Se escribe "Inicializando tarjeta..."
if(!SD.begin(SSpin)){   //Si la inicialización del SD, es incorrecta(se pone como parametro el SSpin)
  Serial.println("fallo en inicialización");    //Se escribe "fallo en inicialización"
  return;   //Deja estancado el programa si en dado caso, de que no se inicializa con exito la tarjeta
}
Serial.println("inicialización correcta");    //Se escribe en el monitor serie "Inicialización correcta"
archivo= SD.open("prueba.txt", FILE_WRITE);   //Archivo será igual al función "SD.open"  que abrirá un archivo(en este caso) del tipo txt, que lo creará automaticamente con la función "FILE_WRITE" del cual, lo abrirá en modo escritura y lectura 

if (archivo) {//Si el archivo es verdadero, entonces...
  archivo.println("probando 1,2,3 ");   //Archivo escribirá en el documento "probando 1,2,3"
  Serial.println("Escribiendo en archivo prueba.txt..."); //El monitor serie escribirá "Escribiendo en archivo prueba.txt..."
  archivo.close();    //Archivo se cierra
  Serial.println("Escritura correcta");   //Se imprime en el monitor serie "Escritura correcta"
} else{   //Si es falos
  Serial.println("error en apertura de prueba.txt...");   //El monitor serie escribe "error en apertura de prueba.txt..."
}
archivo = SD.open("prueba.txt");//Archivo abrirá el documento "prueba.txt"
if(archivo){  //Con esta condicional, vereficamos que el proceso de apertura fue exitoso
  Serial.println("Contenido de prueba.txt:");   //Si es verdadero, el monitor serie escribe "Contenido de prueba.txt:" 
  while(archivo.available()){   //Se coloca un bucle while, para leer la totalida del archivo
    Serial.write(archivo.read());// En el monitor serie escribe lo que se lee en el archivo
  }
  archivo.close();    //El archivo se cierra
} else{   //Si torna falso
  Serial.println("error en la apertura de prueba.txt");   //Se escribe en el monitor "error en la apertura de prueba.txt" 
      }
}
void loop() {
//nada por aquí

}
