#define TRIG D5   // Se declara el disparador del sonido 
# define ECO D6      //Se declara el receptor del sonido
#define L1 D0
#define L2 D1 
boolean band=0;

float getDistancia(int trig, int echo){
  float DURACION;       //Se declara la variable de "duración"
float DISTANCIA;      //Se declara una variable llamada "distancia"

  digitalWrite(trig,HIGH);        //Dispara el sonido
  delay(1);   //A un milisegundo
  digitalWrite(trig,LOW);     //Se apaga el sonido
  DURACION=pulseIn(echo,HIGH);   //Medimos la duración con "pulseIn" lo que hace es devolver un valor de tiempo en microsegundos, y se activa eco, porque espera el sonido del trigger
  DISTANCIA= DURACION /58.2;            //Mide la distancia siendo igual a la duracion entre una constantre del fabricante y lo mide en centimetros}
  if (DISTANCIA >=2 && DISTANCIA < 400)   //Verificac si hay errores de medición
  return DISTANCIA;
else 
return -1;    //Devuelve a -1 si no se cumple la condición
}

void setup() {
  pinMode(TRIG, OUTPUT);    //Se declara el disparador como "salida"
  pinMode(ECO,INPUT);     //Se declara el receptor como entrada
  pinMode(L1, OUTPUT);  //Se declara el led como salida
  pinMode (L2, OUTPUT);
  digitalWrite (L1, band);
  digitalWrite (L2, !band);
  Serial.begin(9600);   //Se inicializa el monitor serie a 9600 baudios
}

void loop() {
  float DISTANCIA;    //Se crea una variable global llamada distancia
  DISTANCIA= getDistancia(TRIG,ECO);    //Distancia será igual a la función getDistancia
  band=!band;
  digitalWrite (L1, band);
  digitalWrite (L2, !band);
  Serial.println(DISTANCIA);      // Se imprime en el monitor serie
  delay(200);       //Lo hace cada 200 milisegundos
}
