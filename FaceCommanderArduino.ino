#include<SoftwareSerial.h>
#define enable_step_motor 5
#define left_eye 2
#define right_eye 4
#define smile 6

const int stepPin = 3; 
const int dirPin = 7; 

int motor1_rotate_right_and_left_pin1 = 8;
int motor1_rotate_right_and_left_pin2 = 9;

int motor2_look_up_and_down_pin1 = 10;
int motor2_look_up_and_down_pin2 = 11;

//Bluetooth serial 
const int txpin = 13;       
const int rxpin = 12;
SoftwareSerial blue(txpin, rxpin);
String state_look_right_left = "center" ;
String state_look_up_down = "center" ;
String state_rotate_right_left = "center" ;

char Command = 'o'  ;

void setup() {
 pinMode(stepPin,OUTPUT); 
 pinMode(dirPin,OUTPUT);
 digitalWrite(stepPin,LOW);
 digitalWrite(dirPin,LOW);
  
 blue.begin(9600);

  pinMode(enable_step_motor,OUTPUT); 
 digitalWrite(enable_step_motor,LOW); 
 
 pinMode(left_eye,OUTPUT); 
 digitalWrite(left_eye,LOW);

pinMode(right_eye,OUTPUT); 
 digitalWrite(right_eye,LOW);

 pinMode(smile,OUTPUT); 
 digitalWrite(smile,LOW);

 

   pinMode(motor1_rotate_right_and_left_pin1, OUTPUT);
  pinMode(motor1_rotate_right_and_left_pin2, OUTPUT);
  pinMode(motor2_look_up_and_down_pin1, OUTPUT);
  pinMode(motor2_look_up_and_down_pin2, OUTPUT);
 
}

void loop() {
  Serial.println(blue.read());

 
   if (blue.available()) {
       Command = blue.read();

       
//////////////////////////////////////////// Left Eye
     if(Command == 'L'){
        digitalWrite(left_eye,HIGH);
        blue.println("left_eye");
     }
     if(Command == 'l'){
        digitalWrite(left_eye,LOW);
        blue.println("left_eye_not");
   }
//////////////////////////////////////////// Right Eye
 if(Command == 'R'){
       digitalWrite(right_eye,HIGH);
        blue.println("right_eye");
     }
     if(Command == 'r'){
        digitalWrite(right_eye,LOW);
        blue.println("right_eye_not");
   }
//////////////////////////////////////////// Smile
   if(Command == 'S'){
        digitalWrite(smile,LOW);
        blue.println("smile");  
     }     
     if(Command == 's'){
        digitalWrite(smile,HIGH);
        blue.println("smile_not");
   }

//////////////////////////////////////////// Look Right and Left 
      if (Command == 'F' && state_look_right_left == "center"){
       state_look_right_left = "left" ;
       digitalWrite(dirPin,HIGH);  
       move(); 
       
     }           
      
      if (Command == 'G' && state_look_right_left == "center"){
      state_look_right_left = "right" ;
      digitalWrite(dirPin,LOW); 
      move();
     }  


     if (Command == 'f' && state_look_right_left == "left"){
       state_look_right_left = "center" ;
       digitalWrite(dirPin,LOW);  
       move(); 
       
     }          

      if (Command == 'g' && state_look_right_left == "right"){
       state_look_right_left = "center" ;
       digitalWrite(dirPin,HIGH);  
       move(); 
      
     }           
//////////////////////////////////////////// Look Up and Down


   if (Command == 'U' && state_look_up_down == "center"){
       state_look_up_down = "up" ;
     digitalWrite(motor2_look_up_and_down_pin1, LOW);
     digitalWrite(motor2_look_up_and_down_pin2, HIGH);
     delay(150);
     digitalWrite(motor2_look_up_and_down_pin1, LOW);
     digitalWrite(motor2_look_up_and_down_pin2, LOW);
       
     }           
      
      if (Command == 'D' && state_look_up_down == "center"){
      state_look_up_down = "down" ;
     digitalWrite(motor2_look_up_and_down_pin1, HIGH);
     digitalWrite(motor2_look_up_and_down_pin2, LOW);
     delay(150);
     digitalWrite(motor2_look_up_and_down_pin1, LOW);
     digitalWrite(motor2_look_up_and_down_pin2, LOW);
     
     }  


     if (Command == 'u' && state_look_up_down == "up"){
       state_look_up_down = "center" ;
       digitalWrite(motor2_look_up_and_down_pin1, HIGH);
     digitalWrite(motor2_look_up_and_down_pin2, LOW);
     delay(150);
     digitalWrite(motor2_look_up_and_down_pin1, LOW);
     digitalWrite(motor2_look_up_and_down_pin2, LOW);
      
       
     }          

      if (Command == 'd' && state_look_up_down == "down"){
       state_look_up_down = "center" ;
          digitalWrite(motor2_look_up_and_down_pin1, LOW);
     digitalWrite(motor2_look_up_and_down_pin2, HIGH);
     delay(150);
     digitalWrite(motor2_look_up_and_down_pin1, LOW);
     digitalWrite(motor2_look_up_and_down_pin2, LOW);
      
       
     }           



//////////////////////////////////////////// Rotate Right and Lift ////


   if (Command == 'O' && state_rotate_right_left == "center"){
       state_rotate_right_left = "rot_right" ;
     digitalWrite(motor1_rotate_right_and_left_pin1, LOW);
     digitalWrite(motor1_rotate_right_and_left_pin2, HIGH);
     delay(100);
     digitalWrite(motor1_rotate_right_and_left_pin1, LOW);
     digitalWrite(motor1_rotate_right_and_left_pin2, LOW);
       
     }           
      
      if (Command == 'A' && state_rotate_right_left == "center"){
      state_rotate_right_left = "rot_left" ;
     digitalWrite(motor1_rotate_right_and_left_pin1, HIGH);
     digitalWrite(motor1_rotate_right_and_left_pin2, LOW);
     delay(100);
     digitalWrite(motor1_rotate_right_and_left_pin1, LOW);
     digitalWrite(motor1_rotate_right_and_left_pin2, LOW);
     
     }  


     if (Command == 'o' && state_rotate_right_left == "rot_right"){
       state_rotate_right_left = "center" ;
       digitalWrite(motor1_rotate_right_and_left_pin1, HIGH);
     digitalWrite(motor1_rotate_right_and_left_pin2, LOW);
     delay(100);
     digitalWrite(motor1_rotate_right_and_left_pin1, LOW);
     digitalWrite(motor1_rotate_right_and_left_pin2, LOW);
      
       
     }          

      if (Command == 'a' && state_rotate_right_left == "rot_left"){
       state_rotate_right_left = "center" ;
          digitalWrite(motor1_rotate_right_and_left_pin1, LOW);
     digitalWrite(motor1_rotate_right_and_left_pin2, HIGH);
     delay(70);
     digitalWrite(motor1_rotate_right_and_left_pin1, LOW);
     digitalWrite(motor1_rotate_right_and_left_pin2, LOW);
       
   }
}
}

void move(){
   for(int x = 0; x < 25; x++) {
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(10000);
      digitalWrite(stepPin,LOW);
      delayMicroseconds(10000);
      }
  }
