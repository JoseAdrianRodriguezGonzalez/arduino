#include <SPI.h>
 #include <SD.h>

 File myFile;

 void setup() {
   // Abrir las comunicaciones serie y esperar a que se abra el puerto:
   Serial.begin(9600);
   while (!Serial) {
     ; // espera a que el puerto serie se conecte. Necesario para el puerto USB nativo solamente
   }

   Serial.print("Inicializando la tarjeta SD...");

   if (!SD.begin(4)) {
     Serial.println("Fallo de inicializacion!");
     return;
   }
   Serial.println("Inicializacion terminada.");

  // Abre el archivo. Tenga en cuenta que sólo un archivo puede ser abierto a la vez,
  // Así que hay que cerrar éste antes de abrir otro.
   myFile = SD.open("test.txt", FILE_WRITE);

   // si el archivo se abrió bien, escribir en él:
   if (myFile) {
     Serial.print("Escribiendo en test.txt...");
     myFile.println("testing 1, 2, 3.");
     // close the file:
     myFile.close();
     Serial.println("Terminado.");
   } else {
     // Si el archivo no se abre, imprimir un error:
     Serial.println("Error abriendo test.txt");
   }

   // volver a abrir el archivo para lectura:
   myFile = SD.open("test.txt");
   if (myFile) {
     Serial.println("test.txt:");

     // leer desde el archivo hasta que no haya nada más en el:
     while (myFile.available()) {
       Serial.write(myFile.read());
     }
     // cerrar el archivo:
     myFile.close();
   } else {
     // Si el archivo no se abre, imprimir un error:
     Serial.println("Error abiendo test.txt");
   }
 }

 void loop() {
   // no pasa nada después de la instalación
 }
