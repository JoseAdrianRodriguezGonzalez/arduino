#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED)  || !defined(CONFIG_BLUEDROID_ENABLED)
#error bluetooth is not enabled! Please run "make menuconfig" to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("UWU");
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if(Serial.available()){
    SerialBT.write(Serial.read());
}  
  if(SerialBT.available()){
    Serial.write(SerialBT.read());
}
  delay(20);
}
