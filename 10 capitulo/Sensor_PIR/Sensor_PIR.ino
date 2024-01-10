 const int PIR = 11;    //Se declara el sensor PIR
 int LED = 10;    //Se declara el LED


void setup() {
pinMode( PIR, INPUT);   //Se declara como entrada el PIR
pinMode(LED,OUTPUT);    //Se declara el led como salida
}

void loop() {
   if (digitalRead(PIR)){   //Si lee algo el PIR
   digitalWrite(LED, HIGH);   //El LED se activa
   delay(4000);   //Por 4 segundos
} else{
  digitalWrite(LED, LOW);   //Si no, se apaga
}
}
