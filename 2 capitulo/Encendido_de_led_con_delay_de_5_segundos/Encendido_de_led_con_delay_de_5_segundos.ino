int PULSADOR = 2;     // las variables
int LED = 3;
int ESTADO = LOW;
void setup() {      // Se establecen los pines
 pinMode(PULSADOR, INPUT);     
 pinMode(LED, OUTPUT);
}

void loop() {    // Bucle
  while(digitalRead(PULSADOR) == LOW){     // Mientras que se lea que el pulsador este apago,no hará nada, si no
    
  }
 digitalWrite(LED,HIGH);    //Escribira en el led un valor alto
 delay(5000);         //retraso de 5 segundos
 digitalWrite(LED,LOW);   //Se apaga el led
  while(digitalRead(PULSADOR) == HIGH);{         //Efecto "anti-rebote" del pulsador
  }
}
