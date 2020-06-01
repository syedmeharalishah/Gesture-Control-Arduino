//necessary libraries

#include <SPI.h>      //SPI library for communicate with the nRF24L01+
#include "RF24.h"     //The main library of the nRF24L01+
#include <SoftwareSerial.h> //For serial communication






//SoftwareSerial ss(RXPin, TXPin);

//enable pins of the Motors
const int enbA = 3;
const int enbB = 5;

//control pins of the Motors

const int IN1 = 6;    //Right Motor (-)
const int IN2 = 7;    //Right Motor (+)

const int IN3 = 4;    //Left Motor (+)
const int IN4 = 2;    //Left Motor (-)




//packet for the direction (X axis and Y axis)
int data[2];



//define object from RF24 library - 9 and 10 are a digital pin numbers to which signals CE and CSN are connected
RF24 radio(9,10);

//pipe addresses for the communicate
const uint64_t pipe = 0xE8E8F0F0E1LL;




void setup(){
  //define the motor pins as OUTPUT
  pinMode(enbA, OUTPUT);
  pinMode(enbB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);


  //starting communication
  Serial.begin(9600); 
  
  radio.begin();                    //Start the nRF24 communicate            
  radio.openReadingPipe(1, pipe);   //Sets the address of the transmitter to which the program will receive data.
  radio.startListening(); 
  

    
       
  }


  void loop(){


  //Gesture control//
  if (radio.available()){
    radio.read(data, sizeof(data));


   //forward move with speed control   
 if(data[0] > 365 && data[0] <=370){
              
      analogWrite(enbA, 70);
      analogWrite(enbB, 70);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }

    else if(data[0] > 370 && data[0] <=375){
              
      analogWrite(enbA, 100);
      analogWrite(enbB, 100);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }

    else if(data[0] > 375 && data[0] <=380){
              
      analogWrite(enbA, 150);
      analogWrite(enbB, 150);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }

    else if(data[0] > 380 && data[0] <=385){
              
      analogWrite(enbA, 200);
      analogWrite(enbB, 200);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }

    else if(data[0] > 385 ){
              
      analogWrite(enbA, 255);
      analogWrite(enbB, 255);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }

    
//*****************************************************//

//reverse with speed control
if(data[0]<=325 && data[0]>320){

      analogWrite(enbA, 105);
      analogWrite(enbB, 100);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
}

else if (data[0]<=320 && data[0]>315)
{
      analogWrite(enbA, 145);
      analogWrite(enbB, 140);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
  }

  else if (data[0]<=315 && data[0]>310)
{
      analogWrite(enbA, 205);
      analogWrite(enbB, 200);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
  }

  else if (data[0]<=310 && data[0]>305)
{
      analogWrite(enbA, 225);
      analogWrite(enbB, 220);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
  }



//*****************************************************//

        //right side move with speed control
  if(data[1] <= 130 && data[1] > 120){ 
     

      
        analogWrite(enbA, 70);
        analogWrite(enbB, 70);
       digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);

  }

       else  if (data[1] <=120 && data[1] >115){


        analogWrite(enbA, 100);
        analogWrite(enbB, 100);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      }

      

      else  if (data[1] <=115 && data[1] >110){


        analogWrite(enbA, 150);
        analogWrite(enbB, 150);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      }

     else  if (data[1] <=110 && data[1] >105){


        analogWrite(enbA, 200);
        analogWrite(enbB, 200);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      }

     else  if (data[1] <=105 ){

//&& data[1] >100
        analogWrite(enbA, 255);
        analogWrite(enbB, 255);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      }

//*****************************************************//

   //left side move with speed control
   if(data[1] > 170 && data[1] <= 175){
     
      analogWrite(enbA, 70);
      analogWrite(enbB, 70);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }

    else if(data[1] > 175 && data[1] <= 180){
     
      analogWrite(enbA, 100);
      analogWrite(enbB, 100);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }
    
    else if(data[1] > 180 && data[1] <= 185){
     
      analogWrite(enbA, 150);
      analogWrite(enbB, 150);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }

     else if(data[1] > 185 && data[1] <= 190){
     
      analogWrite(enbA, 200);
      analogWrite(enbB, 200);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }

    
     else if(data[1] > 190 ){
     
      analogWrite(enbA, 250);
      analogWrite(enbB, 250);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }



       //stop car
    
    if(data[0] > 330 && data[0] < 360 && data[1] > 135 && data[1] < 165){
      //stop car
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
    }
  }

//*********************************************************//
       //****************************************//
  //Bluetooth control//


   if(Serial.available() > 0)
  {
    char data;
    data = Serial.read();
    Serial.write(Serial.read());

    switch (data)
    {
      case '1': //FORWARD
         analogWrite(enbA, 165);
         analogWrite(enbB, 162);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
        break;

        
      case '2': //RIGHT
              analogWrite(enbA, 165);
               analogWrite(enbB, 162);
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        break;

        
      case '3': // LEFT
           analogWrite(enbA, 165);
           analogWrite(enbB, 162);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
        break;

      case '4': //REVERSE

          analogWrite(enbA, 165);
          analogWrite(enbB, 162);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
        break;


         
        


     
      default: //If bluetooth module receives any value not listed above, both motors turn off
        analogWrite(enbA, 0);
        analogWrite(enbB, 0);
    }
  }
   




}
