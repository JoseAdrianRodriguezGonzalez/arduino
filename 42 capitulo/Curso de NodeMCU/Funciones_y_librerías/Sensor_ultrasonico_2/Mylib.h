float getDistancia(int trig, int echo){
  float DURACION;       //Se declara la variable de "duración"
float DISTANCIA;      //Se declara una variable llamada "distancia"

  digitalWrite(trig,HIGH);        //Dispara el sonido
  delay(1);   //A un milisegundo
  digitalWrite(trig,LOW);     //Se apaga el sonido
  DURACION=pulseIn(echo,HIGH);   //Medimos la duración con "pulseIn" lo que hace es devolver un valor de tiempo en microsegundos, y se activa eco, porque espera el sonido del trigger
  DISTANCIA= DURACION /58.2;            //Mide la distancia siendo igual a la duracion entre una constantre del fabricante y lo mide en centimetros}
  if (DISTANCIA >=2 && DISTANCIA < 400)   //Verificac si hay errores de medición
  return DISTANCIA;   //Devuelve la distancia
else 
return -1;    //Devuelve a -1 si no se cumple la condición
}
void binled(int n){
  if ( n==0){
  digitalWrite(L1,0);
  digitalWrite(L2,0);
}else if (n==1){
  
  digitalWrite(L1,1);
  digitalWrite(L2,0);
}
else if (n==2){
  
  digitalWrite(L1,0);
  digitalWrite(L2,1);
}
else if (n==3){
  digitalWrite(L1,1);
  digitalWrite(L2,1);
}
else{
  Serial.println("valor no valido");
}
}
