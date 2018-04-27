#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
//String postData(String data) {
//  HTTPClient http;
//  http.begin("https://new.omixom.com:443/add_measure?token=vwrnlDhZtz&code=70001&temp1=25&hume1=95","A3 9A 18 E5 44 C9 59 EA 0D 7A AC 32 AE AA 27 13 2E 3C 30 AC");
//  int httpCode = http.GET();
//  Serial.print(httpCode);
//  String response;
//  if(httpCode == HTTP_CODE_OK)
//  {
//     Serial.print("HTTP response code ");
//     Serial.println(httpCode);
//     response = http.getString();
//     Serial.println(response);
//  }
//  else
//  {
//     Serial.println("Error in HTTP request");
//  }
//   
//  http.end();
//  return response;
//}

String postData(String data)
    {
    Serial.print("con ");  
    String PostData = "";  
    WiFiClient client;   
    PostData = data;  
    Serial.print("connecting to ");     
    Serial.println(host);
    Serial.println (httpsPort);
    if (!client.connect(host.c_str(), httpsPort.toInt())) 
      {
      Serial.println("connection failed");
      return "error" ;
      }
      String url = "/add_measure?token=vwrnlDhZtz&code=70001&temp1=25&hume1=95";
      client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
//      String url = "/";
//    Serial.print("requesting URL: ");
//    Serial.println(url);
//    client.print(String("POST ") + url + " HTTP/1.1\r\n" +
//               "Host: " + host + "\r\n" +
//               "User-Agent: BuildFailureDetectorESP8266\r\n" +
//               "Content-Type: application/x-www-form-urlencoded\r\n"+
//               "Content-Length: " );              
//    client.println(PostData.length());
//    client.println("\r\n"+
//                 PostData);
//    client.print("Connection: close\r\n\r\n");
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
