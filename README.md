# TyH_OMIXOM 
Este modulo Mide temperatura y humedad y luego realiza un get a un servidor.
<h2> Programacion con ide de arduino</h2>
<p>Seguir los pasos de este link para instalar los archivos del modulo esp8266 https://www.prometec.net/esp8266-pluggin-arduino-ide/ 
abrir el codigo en la ide ade arduino. Mantener pulsado el boton de reset. Mantener pulsado el boton de program. Soltar boton de reset. Soltar boton de program.El modulo esta en modo programacion</p>
<p>En la ide de arduino seleccionar.Herramientas > flash mode > DOUT.
Presionar la flecha de la esquina superior izquierda de la pantalla y el modulo </p> 

<h2> Configuracion de variables y wifi</h2>

<p>Para ingresar a la configuracion de adminitrador se debe apretar el boton por 3 segundos.Esto nos permitira editar los siguientes parametros mas los dos anteriore
ssid=....,clave=.....,serialNumber=....,modelNumber=.....,host=......,httpsPort=......,
EJEMPLO:"ssid=Fibertel WiFi718,clave=0141650064,serialNumber=420,modelNumber=1,host=https://new.omixom.com,httpsPort=443,"</p>
Con Esto ya echo y el modulo conectado a la Red Wifi, este realiza una medicion cada 10 min y lo sube al servidor.
<img src=https://www.omixom.com/wp-content/uploads/2017/08/omixomLogo.png >

<p>Para conectar el modulo a la red Wifi , este debe colocarse en modo AccesPoint (emite una red wifi),apretando el boton, nos conectamos a "T y H OMIXOM"
y por medio de una app como "Httper" que nos permite hacer request desde el celular, realizamos un POST a la IP:192.168.4.1 con un raw 
con el texto "ssid=......(ssid del WiFi que deseamos conectarnos),clave=....(contraseña o "NO" en caso de que no tenga).
EJEMPLO:"ssid=Fibertel WiFi718,clave=0141650064,"</p>
