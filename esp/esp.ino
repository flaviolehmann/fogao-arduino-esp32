#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char * ssid = "Smart_FogEco";
const char * password = "123456789";
WiFiServer server(80);
String cod = "";
String tempo = "";
String temperatura = "";
String boca = "";
WiFiClient client;


void gerarPag(){
  String buf = "";

  buf += "HTTP/1.1 200 OK\r\n";
  buf += "Content-Type: text/html\r\n\r\n";
  buf += "<!DOCTYPE HTML>\r\n<html>\r\n";
  buf += "<meta charset=\"UTF-8\">";
  buf += "<h3>ESP8266 Servidor Web</h3>";
  buf += "<p>BOCA:  <a href=\"?function=boca_on\"><button>LIGA</button></a><a href=\"?function=boca_off\"><button>DESLIGA</button></a></p>";
  buf += "<p>Tempo:  <a href=\"?function=05minC\"><button>5 Minutos</button></a><a href=\"?function=10minC\"><button>10 Minutos</button></a><a href=\"?function=15minC\"><button>15 Minutos</button></a></p>";
  buf += "<p>Temperatura:  <a href=\"?function=80C\"><button>80ºC</button></a><a href=\"?function=90C\"><button>90ºC</button></a><a href=\"?function=100C\"><button>100ºC</button></a></p>";
  buf += "<p><a href=\"?function=atualizar\"><button>Atualizar</button></a></p>";
  buf += "</html>\n"; 

  client.print(buf);
  delay(1);
  //client.flush();
}

void setupWIFI(){
  IPAddress staticIP(192,168,50,4); // IP STATIC
  IPAddress gateway(192,168,50,1); // GATEWAY STATIC
  IPAddress subnet(255,255,255,0); // SUBNET STATIC

  uint8_t mac[WL_MAC_ADDR_LENGTH];
  WiFi.softAPmacAddress(mac);
  WiFi.softAPConfig(staticIP, gateway, subnet);
  WiFi.mode(WIFI_AP_STA); 
  WiFi.softAP(ssid, password);  
  WiFi.begin();
  server.begin();

  Serial.println("Server Iniciado!!!");
  Serial.print("Server Ip: ");
  Serial.println(WiFi.softAPIP());  
}

void tratarReq(String req){
  if (req.indexOf("boca_on") != -1)
  {
    boca = "1";
  }
  else if (req.indexOf("boca_off") != -1)
  {
    boca = "0";
  }
  else if (req.indexOf("15minC") != -1){
    tempo = "015";
  }
  else if (req.indexOf("05minC") != -1){
    tempo = "005";
  }
  else if (req.indexOf("10minC") != -1){
    tempo = "010";
  }
  else if (req.indexOf("80C") != -1){
    temperatura = "080";
  }
  else if (req.indexOf("90C") != -1){
    temperatura = "090";
  }
  else if (req.indexOf("100C") != -1){
    temperatura = "100";
  }
  else if (req.indexOf("atualizar") != -1){
    cod = boca;
    cod += tempo;
    cod += temperatura;
    Serial.println(cod);
  }
  else {
    //Requisicao invalida!
    return;
  }
}


void setup() {
  Serial.begin(9600);

  setupWIFI();  
}

void loop() {
  client = server.available(); // verifica acesso do cliente
  
  if(!client){ // espera cliente enviar algo
    return;
   }

  String req = client.readStringUntil('\r'); // captura dados que o cliente enviou
  //req = req.substring(req.indexOf("/") + 1, req.indexOf("HTTP") +1);
  client.flush();

  gerarPag();
  
  tratarReq(req);

  /*client.print("HTTP/1.1 200 OK\n\n");
  client.flush();
  */
 }
