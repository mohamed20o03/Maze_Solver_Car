#include <NewPing.h>

// Define pins for motor 1
int leftmotor1 = 13;
int leftmotor2 = 12;
int enl = 11; // PWM pin for motor 1

// Define pins for motor 2
int rightmotor1 = 9;
int rightmotor2 = 8;
int enr = 10; // PWM pin for motor 2

// Define pins for ultrasonic sensor
int trigR = A0;
int echoR = A1;

int trigL = A5;
int echoL = A4;

int trigM = A3;
int echoM = A2;

// Define variables for ultrasonic sensor
int maxdistance = 300;
int max_front_wall_distance = 20;
int d_from_the_wall = 5;// Define variables to store distance readings
int distanceLeft = 0;
int distanceFront = 0;
int distanceRight = 0;
int error = 0;
int initialspeed = 120, maxspeed = 150;
int PID_value = 0, previous_error = 0, Kp = 15, Ki = 0, Kd = 200;
int P = 0, I = 0, D = 0;


// Define variables to store distance readings
NewPing sonarright(trigR, echoR, maxdistance);     // NewPing setup of pins and maximum distance
NewPing sonarleft(trigL, echoL, maxdistance);
NewPing sonarfront(trigM, echoM, maxdistance);

void setup() {
  // Set motor pins as outputs
  pinMode(leftmotor1, OUTPUT);
  pinMode(leftmotor2, OUTPUT);
  pinMode(enl, OUTPUT);
  pinMode(rightmotor1, OUTPUT);
  pinMode(rightmotor2, OUTPUT);
  pinMode(enr, OUTPUT);

  // Set ultrasonic sensor pins
  pinMode(trigL, OUTPUT);
  pinMode(echoL, INPUT);
  pinMode(trigR, OUTPUT);
  pinMode(echoR, INPUT);
  pinMode(trigM, OUTPUT);
  pinMode(echoM, INPUT);

  // Initialize Serial communication
  Serial.begin(9600);
}

void loop() {

  distanceLeft = sonarleft.ping_cm();
  distanceFront = sonarfront.ping_cm();
  distanceRight = sonarright.ping_cm();
  
  if( distanceLeft == 0 )distanceLeft = maxdistance;
  if( distanceFront == 0 )distanceFront = maxdistance;
  if( distanceRight == 0 )distanceRight = maxdistance;

  
  //calculating the error
  error = distanceRight - d_from_the_wall;
  calculate_pid();

  if( distanceFront > max_front_wall_distance ){

    int rightspeed = initialspeed-PID_value;
    int leftspeed =initialspeed+PID_value;

    if(rightspeed > maxspeed) rightspeed = maxspeed;
    else if(rightspeed < -40) rightspeed = -40; 
 
    if (leftspeed > maxspeed) leftspeed = maxspeed;
    else if(leftspeed < -40) leftspeed = -40;

    analogWrite(11,abs(leftspeed));
    digitalWrite(leftmotor1, leftspeed > 0 ? HIGH : LOW);
    digitalWrite(leftmotor2, leftspeed > 0 ? LOW : HIGH);
    
    analogWrite(10, abs(rightspeed));
    digitalWrite(rightmotor1, rightspeed > 0 ? HIGH : LOW);
    digitalWrite(rightmotor2, rightspeed > 0 ? LOW : HIGH);

   /* Serial.print("rightspeed: ");
   Serial.print(rightspeed);
   Serial.print("leftspeed: ");
   Serial.println(leftspeed);*/

  }
  else {
    turnleft();

  }

  // Print distance readings to serial monitor
  Serial.print("Left: ");
  Serial.print(distanceLeft);
  Serial.print(" cm\tCenter: ");
  Serial.print(distanceFront);
  Serial.print(" cm\tRight: ");
  Serial.print(distanceRight);
  Serial.println(" cm");
  
  
  
}

void calculate_pid()//calculating pid 
{
    P = error;
    I = I + error;
    D = error-previous_error;
    
    PID_value = (Kp*P) + (Ki*I) + (Kd*D);
}

void turnleft(){
  digitalWrite(leftmotor1, LOW);
  digitalWrite(leftmotor2, HIGH);
  digitalWrite(rightmotor1, HIGH);
  digitalWrite(rightmotor2, LOW);
  analogWrite(enl,initialspeed);
  analogWrite(enr,initialspeed);


}
