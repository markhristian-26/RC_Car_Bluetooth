#include <SimpleDHT.h>

#include <Adafruit_SSD1306.h>
#include <splash.h>

//L293D
//Motor A
int motor_Pin_1 = 5; // Pin 14 of L293
int motor_Pin_2 = 6; // Pin 10 of L293

//Motor B
int motor_Pin_3 = 10; // Pin 7 of L293
int motor_Pin_4 = 9; // Pin 2 of L293
//Signal Light and Head Light
int front_right_led = 11;
int front_left_led = 12;
int tail_right_led = 7;
int tail_left_led = 8;
char bt = 'S';
void setup(){
  Serial.begin(9600); //Set pins as outputs
    pinMode(motor_Pin_1, OUTPUT); // right wheel forward
    pinMode(motor_Pin_2, OUTPUT); // right wheel backward
    pinMode(motor_Pin_3, OUTPUT); // left wheel forward
    pinMode(motor_Pin_4, OUTPUT); // left wheel backward
    pinMode(front_right_led,OUTPUT); //front right led
    pinMode(front_left_led,OUTPUT); // front left led
    pinMode(tail_right_led,OUTPUT); // rear right led
    pinMode(tail_left_led,OUTPUT); // rear left led
    pinMode(bt, INPUT);
}
void loop(){
  bt = Serial.read();
  //Forward
  if(bt=='F'){
  digitalWrite(motor_Pin_1, HIGH);
  digitalWrite(motor_Pin_2, LOW);
  digitalWrite(motor_Pin_3, HIGH);
  digitalWrite(motor_Pin_4, LOW);
  }
  //Backward
  else if(bt=='B'){
  digitalWrite(motor_Pin_1, LOW);
  digitalWrite(motor_Pin_2, HIGH);
  digitalWrite(motor_Pin_3, LOW);
  digitalWrite(motor_Pin_4, HIGH);
  }
  //Right
  else if(bt=='R'){
  digitalWrite(motor_Pin_1, LOW);
  digitalWrite(motor_Pin_2, HIGH);
  digitalWrite(motor_Pin_3, HIGH);
  digitalWrite(motor_Pin_4, LOW);
  delay(100);
  digitalWrite(motor_Pin_1, HIGH);
  digitalWrite(motor_Pin_2, LOW);
  digitalWrite(motor_Pin_3, HIGH);
  digitalWrite(motor_Pin_4, LOW); 
  }
  //Left
  else if(bt=='L'){
  digitalWrite(motor_Pin_1, HIGH);
  digitalWrite(motor_Pin_2, LOW);
  digitalWrite(motor_Pin_3, LOW);
  digitalWrite(motor_Pin_4, HIGH);
  delay(100);
  digitalWrite(motor_Pin_1, HIGH);
  digitalWrite(motor_Pin_2, LOW);
  digitalWrite(motor_Pin_3, HIGH);
  digitalWrite(motor_Pin_4, LOW);
  }
  //Stop
  else if(bt=='S'){
  digitalWrite(motor_Pin_1, LOW);
  digitalWrite(motor_Pin_2, LOW);
  digitalWrite(motor_Pin_3, LOW);
  digitalWrite(motor_Pin_4, LOW);
  }
  //Head light on
  else if(bt=='H'){
  digitalWrite(front_right_led,HIGH);
  digitalWrite(front_left_led,HIGH);
  }
  //Head light off
  else if(bt=='I'){
  digitalWrite(front_right_led,LOW);
  digitalWrite(front_left_led,LOW);
  }
  //Tail light on
  else if(bt=='T'){
  digitalWrite(tail_right_led,HIGH);
  digitalWrite(tail_left_led,HIGH);
  }
  //Tail light off
  else if(bt=='U'){
  digitalWrite(tail_right_led,LOW);
  digitalWrite(tail_left_led,LOW);
  }
}
