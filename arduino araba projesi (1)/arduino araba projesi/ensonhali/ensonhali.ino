#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(9, 10);
#define Trig A0
#define Echo A1

int olcum;
int vSpeed;
int maximumRange = 500;
int minimumRange = 0;

long duration;
int distance;
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

char command;

void setup()
{
  bluetoothSerial.begin(9600); 
  pinMode(Trig, OUTPUT); 
  pinMode(Echo, INPUT); 
  Serial.begin(9600); 
}

void loop() {
  if (bluetoothSerial.available() > 0) {
    command = bluetoothSerial.read();
   if (command == '0'){
      vSpeed=0;}
    else if (command == '1'){
      vSpeed=75;}
    else if (command == '2'){
      vSpeed=95;}
    else if (command == '3'){
      vSpeed=110;}
    else if (command == '4'){
      vSpeed=135;}
    else if (command == '5'){
      vSpeed=155;}
    else if (command == '6'){
      vSpeed=175;}
    else if (command == '7'){
      vSpeed=195;}
    else if (command == '8'){
      vSpeed=215;}
    else if (command == '9'){
      vSpeed=235;}
    else if (command == 'q'){
      vSpeed=255;}
  

    Stop(); //initialize with motors stoped
    int olcum = mesafe(maximumRange, minimumRange);


    
    switch (command) {
      case 'F':
      if(olcum<35&&olcum>2){
      
          back();
      
        }
        else{
        forward();
        }
        break;
      case 'B':

        back();
             
        
        break;
      case 'R':
        left();
        break;
      case 'L':
        right();
        break;
        case 'J':
        gerisag();
        break;
        case 'H':
        gerisol();
        break;
        case 'I':
        ilerisol();
        break;
        case 'G':
        ilerisag();
        break;
    }
  }
 
}


void back()
{
  motor1.setSpeed(vSpeed); 
  motor1.run(FORWARD);  
  motor2.setSpeed(vSpeed); 
  motor2.run(FORWARD);  
  motor3.setSpeed(vSpeed); 
  motor3.run(FORWARD);  
  motor4.setSpeed(vSpeed); 
  motor4.run(FORWARD);  
}

void forward()
{
  motor1.setSpeed(vSpeed); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(vSpeed); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(vSpeed); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(vSpeed); 
  motor4.run(BACKWARD); 
}

void left()
{
  motor1.setSpeed(vSpeed); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(vSpeed); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(vSpeed); 
  motor3.run(FORWARD);  
  motor4.setSpeed(vSpeed); 
  motor4.run(FORWARD);  
}

void right()
{
  motor1.setSpeed(vSpeed); 
  motor1.run(FORWARD);  
  motor2.setSpeed(vSpeed); 
  motor2.run(FORWARD);  
  motor3.setSpeed(vSpeed); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(vSpeed); 
  motor4.run(BACKWARD); 
}

void Stop()
{
  motor1.setSpeed(0);  
  motor1.run(RELEASE); 
  motor2.setSpeed(0);  
  motor2.run(RELEASE); 
  motor3.setSpeed(0);  
  motor3.run(RELEASE); 
  motor4.setSpeed(0);  
  motor4.run(RELEASE); 
}
void gerisag()
{
  motor1.setSpeed(vSpeed);  
  motor1.run(FORWARD); 
  motor2.setSpeed(vSpeed);  
  motor2.run(FORWARD); 
  motor3.setSpeed(0);  
  motor3.run(RELEASE); 
  motor4.setSpeed(0);  
  motor4.run(RELEASE); 
  
}
void gerisol()
{
  motor1.setSpeed(0);  
  motor1.run(RELEASE); 
  motor2.setSpeed(0);  
  motor2.run(RELEASE); 
  motor3.setSpeed(vSpeed);  
  motor3.run(FORWARD); 
  motor4.setSpeed(vSpeed);  
  motor4.run(FORWARD); 
}
void ilerisag()
{
  motor1.setSpeed(0);  
  motor1.run(RELEASE); 
  motor2.setSpeed(0);  
  motor2.run(RELEASE); 
  motor3.setSpeed(vSpeed);  
  motor3.run(BACKWARD); 
  motor4.setSpeed(vSpeed);  
  motor4.run(BACKWARD); 
}
void ilerisol()
{
  motor1.setSpeed(vSpeed);  
  motor1.run(BACKWARD); 
  motor2.setSpeed(vSpeed);  
  motor2.run(BACKWARD); 
  motor3.setSpeed(0);  
  motor3.run(RELEASE); 
  motor4.setSpeed(0);  
  motor4.run(RELEASE); 
}


int mesafe(int maxrange, int minrange)
{
  long duration, distance;

  digitalWrite(Trig,LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);

  duration = pulseIn(Echo, HIGH);
  distance = duration / 58.2;
  



    Serial.print("Distance: ");
    Serial.println(distance);
      
    return distance;
}