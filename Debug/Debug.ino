#include <Stepper.h>
#include <Servo.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution

Servo right_lower;
Servo left_lower;
Servo right_upper;
Servo left_upper;
Servo left_leg;
Servo right_leg;
Stepper myStepper(stepsPerRevolution, 22, 23, 24, 25);
int command = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Started!...");
  right_lower.attach(13);
  left_lower.attach(12);
  left_upper.attach(8);
  right_upper.attach(9);
  left_leg.attach(10);
  right_leg.attach(11);
  myStepper.setSpeed(90);
  /**
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  **/
}
  void loop() {
  // put your main code here, to run repeatedly:
  left_lower.write(90);
  delay(1000);
  left_lower.write(0);
  delay(1000);
}
