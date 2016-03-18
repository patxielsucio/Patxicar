#include <Ultrasonic.h> //con esta libreria vamos ha hacer funcionar 
                        //el piloto automatico ya que funciona con un sensor ultrasonidos


Ultrasonic ultra(9,8);//Definimos los pines en los que va conectado el sensor

char rx = 0; // Variable para almacenar datos del puerto serie

int iz = 5;//Definimos 
int der = 6;//los pines
int iz1 = 10;//de los
int der1 = 11;//motores

int led = 13;//Definimos el led
int buzzer = 12;// y el buzzer

int pecho = 2;//Definimos la entrada del sensor ultrasonico
int ptrig = 3;//Definimos la salida del sensor ultrasonico

int vel = 255; //creamos una variable que cambia la velocidad general de los motores 

int dis = 10; //creamos la variable que define el numero de CM
              //que el piloto automatico tendra en cuenta
              
void setup()
{
        

        pinMode(iz, OUTPUT);//Declaramos todos los pines
        pinMode(der, OUTPUT);
        pinMode(iz1, OUTPUT);
        pinMode(der1, OUTPUT);
	pinMode(led, OUTPUT);
        pinMode(buzzer, OUTPUT);
        pinMode(pecho, INPUT);
        pinMode(ptrig, OUTPUT);

	Serial.begin(9600);//Inicializamos comunicación serie a 9600 baudios
}
 

void loop()//Iniciamos el bucle 
{
	
  if(Serial.available())//Comprobamos si hay datos en el buffer
  {
  
  rx = Serial.read();//Almacena los datos en una variable
       if(rx == 'A') //ALANTE
         {
         analogWrite(iz, vel);
         analogWrite(der, 0);
         analogWrite(iz1, 0);
         analogWrite(der1, vel);
         }
         
         if(rx == 'B') //ATRAS
         {
         analogWrite(iz, 0);
         analogWrite(der, vel);
         analogWrite(iz1, vel);
         analogWrite(der1, 0);         
         }
         
         if(rx == 'C') //DERECHA
         {
         analogWrite(iz, vel);
         analogWrite(der, 0);
         analogWrite(iz1, vel);
         analogWrite(der1, 0);
         
         }
         
         if(rx == 'D') //IZQUIERDA      
         {
         analogWrite(iz1, 0);
         analogWrite(iz, 0);
         analogWrite(der, vel);
         analogWrite(der1, vel);
         }
          if(rx == 'E') //PARAR
         {
         analogWrite(iz, 0);
         analogWrite(der, 0);
         analogWrite(iz1, 0);
         analogWrite(der1, 0);
         
         }
         
     
         if(rx == 'F') //Encender led
         {
         digitalWrite(led, HIGH);
         }
         
         if(rx == 'G') //Apagar led
         {
         digitalWrite(led, LOW);
         }
         
   if(rx == 'H') //Apagar led
         {
         for(int x = 0; x < 200; x++)
             {
             digitalWrite(buzzer, HIGH);
             delay(5);
             digitalWrite(buzzer, LOW);
         
             }
         }
         
           
          while(rx == 'I'){ //Piloto automatico
       digitalWrite(led, HIGH);
       delay(1000);
       digitalWrite(led,LOW);
     
     if (ultra.Ranging(CM) < dis){    
        digitalWrite(13,HIGH);                
        
        analogWrite(der, 0);                 
        analogWrite(iz, 0); 
        analogWrite(der1, 0);    
        analogWrite(iz1, 0); 
        delay (200);
        
        analogWrite(der, vel);
        analogWrite(iz1, vel);
        delay(500);           
        
        analogWrite(iz1, 0);
        analogWrite(iz, 0);
        analogWrite(der, vel);
        analogWrite(der1, vel); 
        delay(1100);
        
        digitalWrite(13,LOW);
     }
     if(ultra.Ranging(CM) > dis){
       
         analogWrite(iz, vel);
         analogWrite(der, 0);
         analogWrite(iz1, 0);
         analogWrite(der1, vel);}
         while(Serial.available()){
         rx = Serial.read();
         }
     }
     
  }
  
  

	
	delay(100);

Serial.println(rx);
 

          delay(100);
}
