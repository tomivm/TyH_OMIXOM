#include <EEPROM.h>   

//----------------variables de posicion en la eeprom----
int hostPos = 0;
int httpsPortPos = 50;
int serialNumberPos = 100;
int modelNumberPos = 150;
//---------------------------------
//------includes WiFi--------
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
WiFiClient client;
WiFiServer server(80);

bool adminMode=1; //var para ingresar a modo admin
bool configMode=0;  // var para ingresar al modo configuracion

unsigned long tiempo_anterior = 0;  //timerByMillis
int contador= 1200;   //timer para sensart TEMP y HUMI   
char mp=0;      //mantener pulsado para boton para modo ingresar a modo config

String data = "code=70001&token=vwrnlDhZtz&Id=%s&temp1=%s&hume1=%s"; //String  con la forma de request
String reciveData; //dato que responde el servidor

String    host = /*"192.168.0.18";*/"https://new.omixom.com"; 
String    httpsPort = "443";  
String    serialNumber = "420";  // numero de serie. 1 por cliente
String    modelNumber = "1";      //numero de modulo del cliente
float     t= 50.2;                //var Temperatura
float     h= 80.50;               //var Humedad

void setup() {
  EEPROM.begin(512);
  Serial.begin(115200);
  delay(1000);
  pinMode(3,INPUT);                    //pin para boton 
  Serial.println("Arrancando OMX"); 
  WiFi.mode(WIFI_STA);                //modo WiFi estacion
  dhtBegin();                         //inicializa sensor

  host= leer(hostPos);                  //levanta valores de la eeprom
  httpsPort= leer(httpsPortPos);  
  serialNumber= leer(serialNumberPos);
  modelNumber= leer(modelNumberPos);
  Serial.print (serialNumber);  
  Serial.print (modelNumberPos);
  Serial.print (httpsPort); 
  Serial.print(host); 
  
}

void loop() {
  
  revisar_timer();         //funcion que revisa el tiempo si el timer se disparo
  if(contador >= 1200){      //timer para leer sensor y enviar Data
    contador=0;            //flag timer
    //readDht();
    char query[300];       //declaramos un char array para pegar los datos necesarios en la url 
    sprintf(query,"/add_measure?token=vwrnlDhZtz&code=%s&temp%d=%.2f&hume%d=%.2f",serialNumber.c_str(),modelNumber.toInt(),t,modelNumber.toInt(),h);
    Serial.println(query);
    if(WiFi.status()== WL_CONNECTED){   //ver si hay conexion WiFi
      reciveData=postData(query);       //postear data a https://new.omixom.com
      Serial.print(reciveData);       
    }
  }
  
  if(configMode==1){         //si el boton fue presionado, permite la configuracion de ssid WiFi y pass
    if (mp >= 6){            // si el boton fue presionado por 3 sec
      adminMode=1;           //permite la configuracion de:  SerialNumber,modelNumber,httpsPort y host
    } 
    mp = 0;  
    configMode=0;  
    AP_on();                //coloca al modulo en modo AccesPoint para su configuracion
  }    
}
