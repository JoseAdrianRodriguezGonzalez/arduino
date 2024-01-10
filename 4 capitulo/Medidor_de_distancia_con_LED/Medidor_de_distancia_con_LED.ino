int TRIG = 10;    // Se declara el trigger(emisor)
int ECO =9;     // Se declara el eco(receptor)
int LED= 3;     //Se declara el led
int DURACION;   //Se declara una variable llamada "duración"
int DISTANCIA;      //Se declara una variable llamada "distancia"
void setup(){
  pinMode(TRIG, OUTPUT);      //Se declara el emisor como salida
  pinMode(ECO, INPUT);        //Se declara el receptor como entrada 
  pinMode(LED,OUTPUT);      //Se declara el led como salida
  Serial.begin(9600);   //Se inicializa el monitor serie
}
void loop(){
  digitalWrite(TRIG,HIGH);      //El emisor se enciende
  delay(1);     //Se demora un milisegundo
  digitalWrite(TRIG,LOW);   //Se apaga el emisor
  DURACION=pulseIn(ECO,HIGH);     //Lo recibe el "eco" aa traves de la variable "pulseIn" y argumenta la variable "duración"
  DISTANCIA=DURACION/58.2;    //Se argumenta la variable Distancia y da igual a una medida en centimetros
  Serial.println(DISTANCIA);     // el monitor serie imprime el valor recibido de "distancia"
  delay(200);   // Se demora 200 milisegundos
   if(DISTANCIA <=20 && DISTANCIA >=0){   //Si la distancia es menor que 20 e igual o mayor que 0...
    digitalWrite(LED,HIGH);   //El LED se encenderá
    delay(DISTANCIA*10);      //El retraso sera igual el producto de la distancia por 10
    digitalWrite(LED, LOW);   //El led se apagará
  }
}
