#include <WiFi.h>

const char* ssid     = "INFINITUM0952";
const char* password = "4Qa7g5RgCb";

WiFiServer server(80);
int estado = LOW; 
void setup()
{
    Serial.begin(115200);
    pinMode(5, OUTPUT);      
    delay(10);
    Serial.println();
    Serial.println();
    Serial.print("Conectado al wifi de la vocacional ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi conectado.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    server.begin();

}

int value = 0;

void loop(){
 WiFiClient client = server.available();  

  if (client) {                            
    Serial.println("New Client.");           
    String currentLine = "";                
    while (client.connected()) {            
      if (client.available()) {             
        char c = client.read();             
        Serial.write(c);                    
        if (c == '\n') {                    
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.print("<!DOCTYPE html><html lang='es'><head><meta charset='UTF-8'> <title>Led</title></head>");
           client.print("<h1 align=center>Introduccion al Internet de las Cosas TT6<br> ");
            client.print("<input type='image' src='https://th.bing.com/th/id/OIP.0aJ1yEZvHCOtvzrnzdZQWAHaFS?w=216&h=180&c=7&r=0&o=5&pid=1.7' style='display:block; margin:auto;padding:0;'<br>");
            client.print("Click <a href=\"/H\">aqui</a> para encender el led.<br>");
            client.print("Click <a href=\"/L\">aqui</a> para apagar el led.<br></h1>");
            client.print("<h2 align=center> José Adrián Rodríguez González <br> Alexis Cervin González <br>Iker Isaac Capetillo Aguinaco <br> Gerardo Manuel Pérez Cervantes</h2>");
            client.println();
            break;
          } else {    
            currentLine = "";
          }
        } else if (c != '\r') {  
          currentLine += c;     
        }
        if (currentLine.endsWith("GET /H")) {
          digitalWrite(5, HIGH);               
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(5, LOW);               
        }
      }
    }
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
