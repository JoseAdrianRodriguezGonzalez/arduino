#include <Wire.h> //Incluye librería de I2C
#include<MechaQMC5883.h>  //Incluye librería del magnetometro 
MechaQMC5883  qmc;    //Se crea un objeto llamado qmc

void setup() {
Wire.begin(); //Se inicializa el I2C
Serial.begin(9600); //Se inicializa el monitor serie
qmc.init();   //Se inicializa el qmc
}

void loop() {
int x,y,z;  //Se declaran las variables de los ejes(obligatorio)
float acimut, geografico; //Se declaran las variables de 
float declinacion = +5.4;
qmc.read(&x,&y,&z,&acimut);
geografico= acimut + declinacion;
if(geografico<0)
geografico=geografico+360;

Serial.print("Acimut geografico: ");
Serial.print(geografico,0);
Serial.println(" grados");
delay(500);
}
