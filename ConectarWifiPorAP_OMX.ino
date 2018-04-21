
bool wifiConect=0; //leer la eeprom
bool passwordSave=0;
const char *ssid = "t/h OMIXOM";
const char *password = "420420420";
//"192.168.43.137";//"192.168.43.109";//"172.20.10.2";//"192.168.0.16";

  

String search_next_word(String string,String Word,String fin);
//void AP_on(void);


String response[2][20];
byte colsNumber=0;

bool AP_on (void)
  { 
  WiFi.mode(WIFI_AP_STA);  
  Serial.print("Configuring access point..."); 
  WiFi.softAP(ssid,password);
  server.begin();
  IPAddress myIP = WiFi.softAPIP();
  Serial.println(myIP);
  Serial.println("HTTP server started");
  wifiConect=1;
  passwordSave=0;
  WiFiClient client;
  //WiFiClient client = server.available();
  String clave = "";
  String ssidWiFi = "";
  while(!client){
   client = server.available();

     //ingresar boton para cancelarr*********************************************
   }
  Serial.println("somebody has connected :)");
  String request = client.readString();
  //ssid=Fibertel WiFi718,clave=0141650064,
  Serial.println(request);
  ssidWiFi = search_next_word(request,"ssid=",",");
  clave = search_next_word(request,"clave=",",");
  Serial.println(ssidWiFi);
  Serial.println(clave);
  if(adminMode==1){
    serialNumber = search_next_word(request,"serialNumber=",",");
    httpsPort = search_next_word(request,"port=",",");
    host = search_next_word(request,"host=",",");
    EEPROM.put(serialNumberPos, serialNumber);
    EEPROM.put(httpsPortPos, httpsPort);
    EEPROM.put(hostPos, porq) ;      
    Serial.println(serialNumber);
    Serial.println(httpsPort);
    Serial.println(host);
    adminMode=0;
  }
  
  client.println("conectando");
  if (clave=="NO"){
    WiFi.begin(ssidWiFi.c_str());
  } 
  else   {
   WiFi.begin(ssidWiFi.c_str(),clave.c_str());
  }
  bool conect=1;
  static int timeOut=0;  
  while (WiFi.status() != WL_CONNECTED) {    
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
    //passwordSave=1;
    //escribir en la eEprom 
    client.print("wifi conectado");
    client.println();
    //delay(1500);
    //client.stop();
    server.stop();
   // WiFi.mode(WIFI_STA);
    Serial.println("");
    Serial.println("WiFi connected");
    WiFi.mode(WIFI_STA);
    return 1;
    }
  }      
String search_next_word(String string,String Word,String fin)
    {
    int posicion=0;  
    if((posicion = string.indexOf(Word))== -1);
    int offset = Word.length();
    //Serial.println(posicion);
    int Stop = string.indexOf(fin,posicion);
    //Serial.println(string.substring(posicion+offset,Stop));
    return string.substring(posicion+offset,Stop);
    }   
//    if(postID==1)
//      {
//      strcpy (INSERT_DATA,"INSERT into caill.CAILLlist (idcaill) value ('%s')");  
//      String convert = WiFi.macAddress();
//      convert.toCharArray(idcaill,35);
//      sprintf(query, INSERT_DATA,idcaill);//idcaill);
//      while(!insertData()) 
//      postID=0;
//      EEPROM.write(postIDPos , postID);
//      EEPROM.commit();
//      Serial.print("estas registrado");
//      delay(1500);
//      }
//    }  
//  }
//
//  bool insertData(void)
//  {
////    if (conn.connect(server_addr, 3000, user, passwordMySQL)) {
////    delay(1000);
//    // Initiate the query class instance
//    MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
//    // Save    
//    // Execute the query
//    cur_mem->execute(query);
//    // Note: since there are no results, we do not need to read any data
//    // Deleting the cursor also frees up memory used
//    delete cur_mem;
//    Serial.println("Data recorded.");
//******
//    return 1;
//  }
//  else
//  {
//    Serial.println("Connection failed.");
//    return 0;
//  }  
//  conn.close();
//  }
