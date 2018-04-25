const char *ssid = "t/h OMIXOM";  //ssid para el modulo en AP
const char *password = "420420420"; //pass para el modulo en AP

String search_next_word(String string,String Word,String fin);

bool AP_on (void)
  { 
  WiFi.mode(WIFI_AP_STA);  //modo AccesPoint y station a la vez
  Serial.print("Configuring access point..."); 
  WiFi.softAP(ssid,password);    //se crea la red
  server.begin();                //se inicia el server
  IPAddress myIP = WiFi.softAPIP(); //se cofigura la ip del server
  Serial.println(myIP);      
  Serial.println("HTTP server started");
  WiFiClient client;               
  //WiFiClient client = server.available();
  String clave = "";
  String ssidWiFi = "";
  while(!client){     //se espera al cliente
   client = server.available();
   if(digitalRead(3) == 0){    //boton para cancelar modo AP
    WiFi.mode(WIFI_STA);
    return 0;
   }
  }
  Serial.println("somebody has connected :)");
  String request = client.readString();   //leemos la request del cliete
  Serial.println(request);
  ssidWiFi = search_next_word(request,"ssid=",","); //buscamos los datos enviados por el cliente
  clave = search_next_word(request,"clave=",",");
  Serial.println(ssidWiFi);
  Serial.println(clave);
  if(adminMode==1){
    httpsPort = search_next_word(request,"port=",",");
    host = search_next_word(request,"host=",",");
    serialNumber = search_next_word(request,"serialNumber=",",");
    modelNumber = search_next_word(request,"modelNumber=",",");

    grabar(httpsPortPos,httpsPort);     //graba los valores en la eeprom
    grabar(hostPos,host); 
    grabar(serialNumberPos,serialNumber);
    grabar(modelNumberPos,modelNumber);
          
    Serial.println(httpsPort);
    Serial.println(host);
    adminMode=0;
  }
  
  client.println("conectando");
  if (clave=="NO"){                 //si la red no tiene clave especificamos un NO en su valor
    WiFi.begin(ssidWiFi.c_str());   //conectamos a la red
  } 
  else   {
   WiFi.begin(ssidWiFi.c_str(),clave.c_str()); //conectamos a la red
  }
  bool conect=1;
  static int timeOut=0;  
  while (WiFi.status() != WL_CONNECTED) {    //revisa la coneccion. si no se conecta en el time out la contraseña es erronea
    delay(500);
    timeOut++;
    if(timeOut==35){
      WiFi.disconnect();
      client.println("contraseña erronea"); 
      Serial.print("Contraseña erronea");        
      timeOut=0;
      conect=0;
      break;
    }
    Serial.print(timeOut); 
    Serial.print("."); 
  } 
  Serial.print(conect); 
  if(conect==1)
    {
    client.print("wifi conectado");
    client.println();
    server.stop();
    Serial.println("");
    Serial.println("WiFi connected");
    WiFi.mode(WIFI_STA);
    return 1;
    }
  }      
String search_next_word(String string,String Word,String fin)  //funcion para buscar palabras entre dos palabras en un string
    {
    int posicion=0;  
    if((posicion = string.indexOf(Word))== -1);
    int offset = Word.length();
    //Serial.println(posicion);
    int Stop = string.indexOf(fin,posicion);
    //Serial.println(string.substring(posicion+offset,Stop));
    return string.substring(posicion+offset,Stop);
    }   

