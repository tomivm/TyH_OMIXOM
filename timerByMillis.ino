bool pushed=0;

void revisar_timer(void) {
    if (500 <= (millis() - tiempo_anterior))
    {
      tiempo_anterior = millis();
      contador++;   //timer para sensart TEMP y HUMI   
      if (digitalRead(3) == 1)
      {
        pushed=1;
        mp++;
      }
      if (pushed == 1 && digitalRead(3) == 0){
        configMode=1;
        pushed=0;
      }
      
    }
  }
  
