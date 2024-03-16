//ARDUINO LINE FOLLOWING CAR//
// YOU HAVE TO INSTALL THE AFMOTOR LIBRARY BEFORE UPLOAD THE CODE//
// GO TO SKETCH >> INCLUDE LIBRARY >> ADD .ZIP LIBRARY >> SELECT AF MOTOR ZIP FILE //
 
//including the libraries
#include <AFMotor.h>
#include<Servo.h> 
Servo m1; 
//defining pins and variables
#define left A0
#define right A1
#define pot A9

int sensorPin = A8;                                //Defines the pin of moisture sensor pin
int sensorValue; 


//defining motors
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);



void setup() {
  
  //declaring pin types
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  pinMode(pot,INPUT);
    m1.attach(10);                             //Define the attached pin for servo motor 1
  m1.write(120);
  //begin serial communication
  Serial.begin(9600);
  digitalWrite(18, HIGH);
  pinMode(18, OUTPUT);
  delay(3000);
}

void loop(){
  //printing values of the sensors to the serial monitor
  Serial.println(digitalRead(left));
  
  Serial.println(digitalRead(right));
  Serial.println(digitalRead(pot));


  //line detected by both
  if(digitalRead(left)==0 && digitalRead(right)==0 && digitalRead(pot)==0){
    //Forward
    motor1.run(FORWARD);
    motor1.setSpeed(150);
    motor2.run(FORWARD);
    motor2.setSpeed(150);
    motor3.run(FORWARD);
    motor3.setSpeed(150);
    motor4.run(FORWARD);
    motor4.setSpeed(150);
  }
  //line detected by left sensor
  else if(digitalRead(left)==0 && !digitalRead(right)==0 && digitalRead(pot)==0){
    //turn left
    motor1.run(FORWARD);
    motor1.setSpeed(200);
    motor2.run(FORWARD);
    motor2.setSpeed(200);
    motor3.run(BACKWARD);
    motor3.setSpeed(200);
    motor4.run(BACKWARD);
    motor4.setSpeed(200);
    
  }
  //line detected by right sensor
  else if(!digitalRead(left)==0 && digitalRead(right)==0 && digitalRead(pot)==0){
    //turn right
    motor1.run(BACKWARD);
    motor1.setSpeed(200);
    motor2.run(BACKWARD);
    motor2.setSpeed(200);
    motor3.run(FORWARD);
    motor3.setSpeed(200);
    motor4.run(FORWARD);
    motor4.setSpeed(200);
   
  }
  //line detected by none
  else if(!digitalRead(left)==0 && !digitalRead(right)==0){
    //stop
    motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    motor3.run(RELEASE);
    motor3.setSpeed(0);
    motor4.run(RELEASE);
    motor4.setSpeed(0);
   
  }


    if(digitalRead(left)==0 && digitalRead(right)==0 && !digitalRead(pot)==0){
    //Forward
    motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    motor3.run(RELEASE);
    motor3.setSpeed(0);
    motor4.run(RELEASE);
    motor4.setSpeed(0);
    delay(3000);
   m1.write(0);
   delay(500);
   sensorValue = analogRead(sensorPin);
   Serial.print("analog : ");
   Serial.println(sensorValue);
   delay(4000);
   if(sensorValue>=900){
delay(1500);
            digitalWrite(18, LOW);
delay(10000);
            digitalWrite(18, HIGH);
         delay(3000);  
m1.write(120);
delay(1500);

    motor1.run(FORWARD);
    motor1.setSpeed(150);
    motor2.run(FORWARD);
    motor2.setSpeed(150);
    motor3.run(FORWARD);
    motor3.setSpeed(150);
    motor4.run(FORWARD);
    motor4.setSpeed(150);
delay(300);}
else{
  m1.write(120);
  delay(1500);
    motor1.run(FORWARD);
    motor1.setSpeed(150);
    motor2.run(FORWARD);
    motor2.setSpeed(150);
    motor3.run(FORWARD);
    motor3.setSpeed(150);
    motor4.run(FORWARD);
    motor4.setSpeed(150);
delay(300);}
  }
       
  }


   
  
  
