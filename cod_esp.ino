#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "string.h"

#define  UDP_BUFF_SIZE 512
byte packetBuffer[512]; 
char dato[1];

//
//const char* ssid = "JAKFIBER_GUTIERREZ";
//const char* password = "lg2019@@++";


const char* ssid = "Tp-24GH";
const char* password = "raham123";

WiFiUDP Udp;
unsigned int localUdpPort = 1337;  // local port to listen on
 // buffer for incoming packets
char  replyPacket[] = "Hi there! Got the message :-)";  // a reply string to send back

////////////adelante atras 
int OUTPUT2 = 4;
int OUTPUT1 = 0;

int  PWM=2;
int STB=5;

////////////izquierda derecha
//
int OUTPUT4 = 12;
int OUTPUT3 = 13;

int  PWM2=15;
int STB2=14;


void setup()
{
  Serial.begin(115200);
  pinMode (OUTPUT1, OUTPUT);
  pinMode (OUTPUT2, OUTPUT);
  pinMode (PWM, OUTPUT);
  pinMode (STB, OUTPUT);
  pinMode (OUTPUT3, OUTPUT);
  pinMode (OUTPUT4, OUTPUT);
  pinMode (PWM2, OUTPUT);
  pinMode (STB2, OUTPUT);

        
     delay(10);
  Serial.println();
                analogWrite(PWM, 1000);  
              analogWrite(PWM2, 500);

  Serial.printf("Connecting to %s ", ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    
  }


  
  Serial.println(" connected");

  Udp.begin(localUdpPort);
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);
}




void loop()
{
  int packet_size = Udp.parsePacket();
    

  if (packet_size > 0) {
    
   int len = Udp.read(packetBuffer,packet_size);
        
    
    // receive incoming UDP packets
    Serial.printf("Received %d bytes from %s, port %d\n", packet_size, Udp.remoteIP().toString().c_str(), Udp.remotePort());
    Serial.printf("UDP packet contents: %s\n", packetBuffer);

    //dato=  (packetBuffer);


      strncpy(dato, (char*)packetBuffer,sizeof(dato));
 
      if (dato[1] == 'w') { 
              digitalWrite(OUTPUT1, 0);
              digitalWrite(OUTPUT2, 1);
        
              digitalWrite(STB, 1); 
//              analogWrite(PWM, 800);  

      
              digitalWrite(OUTPUT3, 0);
              digitalWrite(OUTPUT4, 0);

              digitalWrite(STB2, 0); 
  //            analogWrite(PWM2, 500);
        
         } else if (dato[1] == 'e') {  

              digitalWrite(OUTPUT1, 0);
              digitalWrite(OUTPUT2, 1);
        
              digitalWrite(STB, 1); 
    //          analogWrite(PWM, 800);  

      
              digitalWrite(OUTPUT3, 0);
              digitalWrite(OUTPUT4, 1);

              digitalWrite(STB2, 1); 
      //        analogWrite(PWM2, 500);
         
            
          } else if (dato[1] == 'q') { 

              digitalWrite(OUTPUT1, 0);
              digitalWrite(OUTPUT2, 1);
        
              digitalWrite(STB, 1); 
        //      analogWrite(PWM, 800);  

      
              digitalWrite(OUTPUT3, 1);
              digitalWrite(OUTPUT4, 0);

              digitalWrite(STB2, 1); 
          //    analogWrite(PWM2, 500);


      
         } else if (dato[1] == 's') { 

              digitalWrite(OUTPUT1, 1);
              digitalWrite(OUTPUT2, 0);
        
              digitalWrite(STB, 1); 
            //  analogWrite(PWM, 800);  

      
              digitalWrite(OUTPUT3, 0);
              digitalWrite(OUTPUT4, 0);

              digitalWrite(STB2, 0); 
              //analogWrite(PWM2, 500);
     


       } else if (dato[1] == 'd') {  

              digitalWrite(OUTPUT1, 1);
              digitalWrite(OUTPUT2, 0);
        
              digitalWrite(STB, 1); 
              //analogWrite(PWM, 800);  

      
              digitalWrite(OUTPUT3, 0);
              digitalWrite(OUTPUT4, 1);

              digitalWrite(STB2, 1); 
              //analogWrite(PWM2, 500);


      } else if (dato[1] == 'a') { 

              digitalWrite(OUTPUT1, 1);
              digitalWrite(OUTPUT2, 0);
        
              digitalWrite(STB, 1); 
              //analogWrite(PWM, 800);  

      
              digitalWrite(OUTPUT3, 1);
              digitalWrite(OUTPUT4, 0);

              digitalWrite(STB2, 1); 
              //analogWrite(PWM2, 500);
         
      }else if (dato[1] == 'p') {
              digitalWrite(OUTPUT1, 0);
                digitalWrite(OUTPUT2, 0); 
      
               digitalWrite(OUTPUT3, 0);
               digitalWrite(OUTPUT4, 0);


               digitalWrite(STB, 0); 
               digitalWrite(STB2, 0); 
      }
      
      
   
delay(260);
//   if (len > 0) {
//     digitalWrite(OUTPUT1, 0);
//      digitalWrite(OUTPUT2, 0);
//      packetBuffer[len] = 0;
//      
//      
//    } 

    
//  }else {
//    digitalWrite(OUTPUT1, 0);
//    digitalWrite(OUTPUT2, 0);
//    digitalWrite(OUTPUT3, 0);
//    digitalWrite(OUTPUT4, 0);
  }

//
digitalWrite(OUTPUT1, 0);
    digitalWrite(OUTPUT2, 0);
    digitalWrite(OUTPUT3, 0);
    digitalWrite(OUTPUT4, 0);

  
}
