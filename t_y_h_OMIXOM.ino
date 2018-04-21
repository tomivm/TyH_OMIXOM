#include <EEPROM.h>   

byte hostPos = 0;
byte httpsPortPos = 100;
byte serialNumberPos = 200;

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
WiFiClient client;
WiFiServer server(80);
bool adminMode=1;
bool configMode=0;

unsigned long tiempo_anterior = 0;  //timerByMillis
char contador;   //timer para sensart TEMP y HUMI   
char mp=0;      //mantener pulsado para boton

String data = "title=foo&body=bar&Id=%s&t=%s&h=%s";

String host = "192.168.0.100";
String httpsPort = "3001";
String serialNumber = "";
float     t= 50.2;
float     h= 80.50;

char porq [20]= '3''0''0''2';

String reciveData;

void setup() {
  EEPROM.begin(512);
  Serial.begin(115200);
  delay(1000);
  pinMode(3,INPUT);
  Serial.println("Arrancando OMX"); 
  WiFi.mode(WIFI_STA);
  dhtBegin();
  //EEPROM.get(serialNumberPos,serialNumber);
  //EEPROM.get(httpsPortPos,httpsPort);
  
  Serial.print (serialNumber);  
  Serial.print (httpsPort); 
  Serial.print(host); 
  AP_on();
  
}

void loop() {
  
  revisar_timer();
  if(contador >= 10){
    contador=0;
    readDht();
    char query[128];
    sprintf(query,"title=foo&body=bar&id=%s&t=%f&h=%f",serialNumber.c_str(),t,h);
    reciveData=postData(query);  
    EEPROM.get (hostPos,porq) ; 
    Serial.print(porq); 
  }
  
  if(configMode==1){
    if (mp >= 4){
      adminMode=1;
    } 
    mp = 0;  
    configMode=0;  
    AP_on();    
  }    
}
