
//----------------Función para grabar en la EEPROM-------------------
void grabar(int addr, String a) {         //Posicion de la memoria EEPROM y string
  int tamano = a.length(); 
  char inchar[50]; 
  a.toCharArray(inchar, tamano+1);
  for (int i = 0; i < tamano; i++) {
    EEPROM.write(addr+i, inchar[i]);
  }
  for (int i = tamano; i < 50; i++) {
    EEPROM.write(addr+i, 255);
  }
  EEPROM.commit();
}

//-----------------Función para leer la EEPROM------------------------
String leer(int addr) {                 //Posicion de la memoria EEPROM
   byte lectura;
   String strlectura;
   for (int i = addr; i < addr+50; i++) {
      lectura = EEPROM.read(i);
      if (lectura != 255) {
        strlectura += (char)lectura;
      }
   }
   return strlectura;
}


