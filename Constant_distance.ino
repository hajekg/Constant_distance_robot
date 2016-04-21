
// Include both the distance sensor library 

#include <NewPing.h>

//Define your global variables for the distance sensor 

#define sensor_echo 7
#define sensor_trigger 6  
#define max_distance  300

//Define your global variables for the motor shield 


// direction pins on the motor shield 

#define direction_A 12 
#define direction_B 13

//pins that control each motor on the motor shield 

#define motor_A 3
#define motor_B 11

//motor parameters

#define speed_motorA 200
#define speed_motorB 200


//Initialize the NewPin library

NewPing sonar(sensor_trigger, sensor_echo, max_distance);



void setup(){ 

pinMode(direction_A, OUTPUT);
pinMode(direction_B, OUTPUT);

Serial.begin(9600);
 
}


void loop(){
  
int constant_distance = 15;

int echo_time = sonar.ping_median(3);

unsigned int distance = sonar.convert_cm(echo_time);

Serial.println(distance);


if((distance < constant_distance + 2) && (distance > constant_distance - 2)){
  
 Stop(); 
  
}


  if(distance >= constant_distance + 2){ 
 
 forward();

}


  if(distance <= constant_distance - 2){
  
 back_up(); 
  
   }
}



void Stop(){
 
analogWrite(motor_A, 0);
analogWrite(motor_B, 0); 

}

void forward(){

analogWrite(motor_A, speed_motorA);
digitalWrite(direction_A, LOW);

analogWrite(motor_B, speed_motorB);
digitalWrite(direction_B, LOW);
  
}


void back_up(){

analogWrite(motor_A, speed_motorA);
digitalWrite(direction_A, HIGH);

analogWrite(motor_B, speed_motorB);
digitalWrite(direction_B, HIGH);
  
}
