int FI = 2;
int val;
void setup() {
  Serial.begin(9600);
  pinMode(FI,INPUT);

}

void loop() {
  val =digitalRead(FI);
  if (FI ==HIGH){
    Serial.println("SI");
  }
  else{
    Serial.println("No");
  }
}
