#define MOSFET 3    //ASe define la variable del MOSFET
void setup(){
  pinMode(MOSFET, OUTPUT);    //Se declara el MOSFET como salida
}
void loop(){
  digitalWrite(MOSFET,HIGH);    //Se enciende durante 1 segundo
  delay(1000);
  digitalWrite(MOSFET, LOW);    //Se apaga durante 2 segundoss
  delay(2000); 
}
