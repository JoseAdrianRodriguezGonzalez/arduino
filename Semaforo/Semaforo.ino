#define ledrojo 15 //Led rojo en el pin 15
#define ledambar 2 //Led ambar en el pin 2
#define ledverde 4 //led verde en el 4
#define pushbutton 5

void IRAM_ATTR encendido(){
  digitalWrite(ledrojo,HIGH);
  digitalWrite(ledverde,HIGH);
  digitalWrite(ledambar,HIGH);
  semaforo();
}
void setup() {
  // put your setup code here, to run once:
  //Todos los leds se declaran como salidas
  pinMode(ledrojo, OUTPUT);
  pinMode(ledambar, OUTPUT);
  pinMode(ledverde, OUTPUT);
  pinMode(pushbutton,INPUT);
  attachInterrupt(pushbutton, encendido, RISING);
  
}
void semaforo(){
  // put your main code here, to run repeatedly:
 /*Ciclo verde*/
  digitalWrite(ledverde, HIGH); //Enciende el led verde durante 5 segundos
  delay(5000);
  /*Ciclo de parpadeo*/
  digitalWrite(ledverde, LOW);
  delay(500);
  digitalWrite(ledverde, HIGH);
  delay(500);  
  digitalWrite(ledverde, LOW);
  delay(500);
  digitalWrite(ledverde, HIGH);
  delay(500);
  digitalWrite(ledverde, LOW);
  delay(500);  
  digitalWrite(ledverde, HIGH);
  delay(500);  
  /*Ciclo del led amarillo*/
  digitalWrite(ledverde, LOW);//Se apaga el led verde
  digitalWrite(ledambar, HIGH);//se enciende el led amarillo durante dos segundos
  delay(2000);
  /*Ciclo del led rojo*/
  digitalWrite(ledambar, LOW); //Se apaga el led amarillo
  digitalWrite(ledrojo, HIGH);//Se enciende el led rojo durante 5 segundos
  delay(5000);
  digitalWrite(ledrojo, LOW);//Se apaga el led rojo
}
void loop() {
 semaforo(); 
}