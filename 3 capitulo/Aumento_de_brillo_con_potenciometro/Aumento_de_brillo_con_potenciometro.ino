int LED = 3;    //Se declara el pin del led en PWM
int BRILLO;     //Se declara una variable llamada "brillo"
int POT = 0;        //Se declara el potenciometro en la entrada 0 analogica

void setup() {
 pinMode(LED, OUTPUT);    //Se declara el led como salida
      //En entradas analogicas no requiere inicialización porque solamente son "entradas"
}

void loop() {
 BRILLO=analogRead(POT) / 4;      //Brillo es igual al giro del potenciometro dividio de 1023 entre 4, dando igual a 256
 analogWrite(LED, BRILLO);        //Se escribe el valor de brillo al led

}
