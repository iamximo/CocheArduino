
#include <SoftwareSerial.h>


const int LeftMotorForward = 11;
const int LeftMotorBackward = 10;
const int RightMotorForward = 9;
const int RightMotorBackward = 8;


const int rxBt = 3;
const int txBt = 2;


boolean goesForward = false;

SoftwareSerial BT1(rxBt, txBt);

void setup(){

  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);   
    

  Serial.begin(9600);
  BT1.begin(9600); 

  

}

void loop(){
  

  if (BT1.available()){
        char leo = BT1.read();
        Serial.write(leo);
        if(leo=='1'){
          moveForward();
        }
        if(leo=='2'){
          moveBackward();
        }
        if(leo=='3'){
          turnRight();
        }
        if(leo=='4'){
          turnLeft();
        }
        if(leo=='5'){
          moveStop();
        }
  }

        
}


void moveStop(){
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}



void moveForward(){

  if(!goesForward){

    goesForward=true;
    
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
  
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW); 
  }
}

void moveBackward(){

  goesForward=false;

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
}

void turnRight(){
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
  
}

void turnLeft(){

   digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);



}
