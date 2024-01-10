#define MOSFET 3  //Se define el pin del mosfet
int BRILLO;   //Se define la variable brillo
void setup() {
  pinMode(MOSFET, OUTPUT);    //Se declara el MOSFET como SALIDA
}

void loop() {
  //Aumenta el brillo cada 25 milisegundos
  for(BRILLO = 0; BRILLO < 256; BRILLO++){    
    analogWrite(MOSFET,BRILLO);
    delay(25);
  }
  //Disminuye el brillo
  for(BRILLO = 255; BRILLO >= 0; BRILLO--){
   analogWrite(MOSFET,BRILLO);
    delay(25);
  }
}
