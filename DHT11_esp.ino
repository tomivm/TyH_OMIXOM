#include <DHT.h>
#include <DHT_U.h>

#include <Adafruit_Sensor.h>

// Uncomment one of the lines below for whatever DHT sensor type you're using!
//#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

const int DHTPin = 2;
DHT dht(DHTPin, DHTTYPE);

void dhtBegin(){  //funcion para inicializar dht
  dht.begin();
}

void readDht() {
  h = dht.readHumidity();      //lee humedad
  t = dht.readTemperature();   //lee temperatura

  if (isnan(h) || isnan(t)) {  //si la lectura fallo
      Serial.println("Failed to read from DHT sensor!");
      return;
  }
   Serial.println("");
   Serial.print("Humidity: ");
   Serial.print(h);
   Serial.println(" %\t");
   Serial.print("Temperature: ");
   Serial.print(t);
   Serial.print(" *C ");
}
