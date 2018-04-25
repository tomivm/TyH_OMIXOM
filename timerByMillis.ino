bool pushed=0;

void revisar_timer(void) {
    if (500 <= (millis() - tiempo_anterior))    //cada 500 ms entra a este if
    {
      tiempo_anterior = millis();
      contador++;   //timer para sensart TEMP y HUMI   
      if (digitalRead(3) == 1) //lee si se presiono el boton
      {
        pushed=1;
        mp++; //suma cada 500ms del boton pulsado
      }
      if (pushed == 1 && digitalRead(3) == 0){ //lee si se solto el boton
        configMode=1;
        pushed=0;
      }
      
    }
  }
  
