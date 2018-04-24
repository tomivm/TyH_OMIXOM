

String postData(String data)
    {
//      if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
//     Serial.println("se1");
//     HTTPClient http;    //Declare object of class HTTPClient
//     Serial.println("se2"); 
//     http.begin("https:new.omixom.com/add_measures");      //Specify request destination
//     Serial.println("se3"); 
//     http.addHeader("Content-Type", "text/plain");  //Specify content-type header
//     Serial.println("se4"); 
//     int httpCode = http.POST("code=70001&token=vwrnlDhZtz&t=40&h=80");   //Send the request
//     Serial.println("se5"); 
//     String payload = http.getString();                  //Get the response payload
//     Serial.println("se6"); 
//     Serial.println(httpCode);   //Print HTTP return code
//     Serial.println("se7"); 
//     Serial.println(payload);    //Print request response payload
//     Serial.println("se8"); 
//   
//     http.end();  //Close connection
//     Serial.println("se9"); 
//     return payload;
//   }
//    } 
    Serial.print("con ");  
    String PostData = "";  
    WiFiClient client;   
    PostData = data;  
    Serial.print("connecting to ");     
    Serial.println(host);
    Serial.println(httpsPort);
    if (!client.connect(host.c_str(), httpsPort.toInt())) 
      {
      Serial.println("connection failed");
      return "error" ;
      }
       String url = "https://new.omixom.com/add_measure";
    Serial.print("requesting URL: ");
    Serial.println(url);
    client.print(String("POST ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: BuildFailureDetectorESP8266\r\n" +
               "Content-Type: application/x-www-form-urlencoded\r\n"+
               "Content-Length: " );              
    client.println(PostData.length());
    client.println("\r\n"+
                 PostData);
    client.print("Connection: close\r\n\r\n");
    Serial.println("request sent");
    while (client.connected()) 
      { 
      String line = client.readStringUntil('\n');
      Serial.println("aca ta");
      Serial.println(line);  
      if (line == "\r") 
        {
        Serial.println("headers received");
        break;
        }
      } 
      String line = client.readStringUntil('\n');
      if (line.startsWith("{\"state\":\"success\"")) 
        {
        Serial.println("esp8266/Arduino CI successfull!");
        } 
        else 
        {
        Serial.println("esp8266/Arduino CI has failed");
        }
      Serial.println("reply was:");
      Serial.println("==========");
      Serial.println(line);
      Serial.println("==========");
      Serial.println("closing connection"); 
      client.stop(); 
      return line;
   }
