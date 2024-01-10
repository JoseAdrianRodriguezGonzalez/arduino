#include <Wire.h> //Incluye librería de I2C
#include<MechaQMC5883.h>  //Incluye librería del magnetometro 
MechaQMC5883  qmc;    //Se crea un objeto llamado qmc

void setup() {
Wire.begin(); //Se inicializa el I2C
Serial.begin(9600); //Se inicializa el monitor serie
qmc.init();   //Se inicializa el qmc
}

void loop() {
  int x,y,z,acimut;   //Se declaran las variables de los ejes y el azimut
  qmc.read(&x,&y,&z,&acimut);   //Se leen los ejes
  //Se escriben los ejes en el monitor serie
  Serial.print("x:");
  Serial.print(x);
  Serial.print("\t");
    Serial.print("y:");
  Serial.print(y);
  Serial.print("\t");
    Serial.print("z:");
  Serial.print(z);
  Serial.print("\t");
    Serial.print("azimut:");
  Serial.println(acimut);
delay(250);

}
