#include <stdio.h>
#include <math.h>

int analogPin=0;     // Pin donde esta conectado el divisor de tension en el Arduino

float Vin=5.0;       // [V]       Voltage de entrada en el divisor de tension
float Raux=10000;    // [ohm]     Valor de la resistencia secundaria del divisor de tension
float R0=100000;     // [ohm]     Valor de resistencia nominal del termistor (NTC) a 25ºC
float T0=298.15;     // [K] (25ºC)

float Vout=0.0;      // [V]        Voltage given by the Voltage-Divider
float Rout=0.0;      // [ohm]      Resistencia actual del Termistor (NTC)

// Valores para calcular el valor Beta, si no lo sabemos
// float T1=273;     // [K]        Temperatura del 1º punto del test (en grados Kelvin)
// float T2=373;     // [K]        Temperatura del 2º punto del test (en grados Kelvin)
// float RT1=19750;  // [ohms]     Resistencia a 273K grados Kelvin (0ºC)
// float RT2=2150;   // [ohms]     Resistencia a 373K grados Kelvin (100ºC)

float beta=0.0;      // [K]        Parametro Beta
float Rinf=0.0;      // [ohm]      Parametros Rinf
float TempK=0.0;     // [K]        Temperatura de salida en grados Kelvin
float TempC=0.0;     // [ºC]       Temperatura de salida en grados Celsius

int iCont;            // Contador de ciclos, par el calculo de la temperatura media
float cTemp1;         // Variable temporal para acumular las temperaturas leidas 

void setup() {
  // Configuramos el puerto Serie
  Serial.begin(9600);

  // Configuramos el pin del Arduino en entrada
  pinMode(analogPin, INPUT);

  // Parametros generales para el calculo
  // Formula para calcular el valor beta si no disponemos de el
  // beta=(log(RT1/RT2))/((1/T1)-(1/T2));
  // Valor beta, los fabricantes suelen disponer ya de este valor, 
  // mirar en la tabla de carateristicas del termistor
  beta = 4380;
  Rinf=R0*exp(-beta/T0);
}

void loop()
{
  cTemp1=0;  
  for (iCont = 1; iCont <= 500; iCont ++)
  {
    // Cálculo del valor de la resistencia termistor (NTC) actual (a través de Vout)
    Vout=Vin*((float)(analogRead(analogPin))/1024.0); 
    Rout=(Raux*Vout/(Vin-Vout));

    // Calculo de la temperatura en grados Kelvin
    TempK=(beta/log(Rout/Rinf));
    // Calculo de la temperatura en grados Celsius
    TempC=TempK-273.15; 
    // Hacemos una pausa de 10 milisegundos    
    delay(10);
  }

  // Mostramos la temperatura media en grados Celsius
  Serial.println(TempC);

  // Hacemos una pausda de 1 seg.
  delay(500);
}
