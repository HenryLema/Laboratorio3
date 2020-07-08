 #include <LiquidCrystal.h>
 #include<TimerOne.h>
 #include<MsTimer2.h> 
LiquidCrystal lcd (13,12,11,10,9,8);
const int leds[4] = {2,3,4,5};
//const int leds [6]={13,12,11,10,9,8};
 int on=0; // int0
 int cont; // int1
 int i; //variables de conteo
 int j=0;  //variables de conteo

void setup(){
  for(i=0;i<6;i++){ // configuración de leds
      pinMode(leds[i],OUTPUT);
    }  
   i=0;
   Serial.begin(9600); //activación de cx serial
   attachInterrupt(0,activacion,LOW); // interrupt 0 habilitada
   attachInterrupt(1,contador,LOW);  // interrupt 1 habilitada
}

void loop(){
  if(on==2){ // condición de juego
      for(;i<cont;i++){ // límite de juego
          for(j=0;j<6;j++){ // ciclo de luces
              digitalWrite(leds[j],HIGH);
              delay(200);
              digitalWrite(leds[j],LOW);
              delay(200);
            }
        }
    }
}
void activacion (){
  switch(on){ // opciones de boton 
      case 0:
        Serial.println("Inicio de Sistema");
        Serial.println("Sistema domotico");
        on++;
      break;
      case 1:
        Serial.println("luces");
        on++;
      break;
      case 2:
        Serial.println("hora");
        cont=0;
        on=0;
        i=0;
      break;
    }
}
void contador(){
  if(on==1){ // restricción de juego
      cont++;
      Serial.println(String("Juega" )+String(cont)+String(" veces"));
    }
}
