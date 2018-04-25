#include <ESP8266HTTPClient.h>

String postData(String data) {
  HTTPClient http;
  int statusData = http.begin("https://new.omixom.com", data);   //Specify request
  Serial.println(statusData);
  int httpCode = http.GET();
  Serial.println(httpCode);
  String payload = http.getString();                  //Get the response payload
  Serial.println(payload);    //Print request response payload
  http.end();  //Close connection
  return payload;
}


