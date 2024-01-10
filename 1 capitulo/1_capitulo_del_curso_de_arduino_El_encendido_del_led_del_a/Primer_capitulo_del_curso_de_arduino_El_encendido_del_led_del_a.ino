void setup (){
  pinMode(13,OUTPUT);      // Se determina el de localización del led en el pin 13 y lo determina como saida
}
void loop (){
  digitalWrite(13,HIGH);        // Se prende el LED
  delay(2000);
  digitalWrite(13,LOW);         //Se apaga el led
  delay(2000);
}
