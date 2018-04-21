
String postData(String data)
    {
    Serial.print("con ");  
    String PostData = "";  
    WiFiClient client;   
    PostData = data;  
    Serial.print("connecting to ");     
    Serial.println(host);
    if (!client.connect(host.c_str(), httpsPort.toInt())) 
      {
      Serial.println("connection failed");
      return "error" ;
      }
       String url = "/";
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
      return line;
   }
