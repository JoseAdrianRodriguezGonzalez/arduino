int TRIG =  10;   // Se declara el disparador del sonido 
int   ECO = 9;      //Se declara el receptor del sonido
int LED= 3;       //Se declara el led
int DURACION;       //Se declara la variable de "duración"
int DISTANCIA;      //Se declara una variable llamada "distancia"
void setup() {
  pinMode(TRIG, OUTPUT);    //Se declara el disparador como "salida"
  pinMode(ECO,INPUT);     //Se declara el receptor como entrada
  pinMode(LED, OUTPUT);  //Se decl ara el led como salida
  Serial.begin(9600);   //Se inicializa el monitor serie a 9600 baudios
}

void loop() {
  digitalWrite(TRIG,HIGH);        //Dispara el sonido
  delay(1);   //A un milisegundo
  digitalWrite(TRIG,LOW);     //Se apaga el sonido
  DURACION=pulseIn(ECO,HIGH);   //Medimos la duración con "pulseIn" lo que hace es devolver un valor de tiempo en microsegundos, y se activa eco, porque espera el sonido del trigger
  DISTANCIA= DURACION /58.2;            //Mide la distancia siendo igual a la duracion entre una constantre del fabricante y lo mide en centimetros
  Serial.println(DISTANCIA);      // Se imprime en el monitor serie
  delay(200);       //Lo hace cada 200 milisegundos
}
