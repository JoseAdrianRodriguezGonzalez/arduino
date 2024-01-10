int PULSADOR = 2;     // las variables
int LED = 3;
int ESTADO = LOW;
void setup() {      // Se establecen los pines
 pinMode(PULSADOR, INPUT);     
 pinMode(LED, OUTPUT);
}

void loop() {    // Bucle
  while(digitalRead(PULSADOR) == LOW){     // Mientras que se lea que el pulsador este apagado,no hará nada, si no
    
  }
  ESTADO=digitalRead(LED);            // El estado leerá al LED
  digitalWrite(LED, !ESTADO);            //Y se escribirá la negación del estado al LED
  while(digitalRead(PULSADOR) == HIGH);{         //Efecto "anti-rebote" del pulsador
  }
}
