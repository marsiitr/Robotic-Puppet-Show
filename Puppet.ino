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
   //myStepper.step((-2) * stepsPerRevolution);
   normal();
   Serial.println("MINNNNN");
   while(Serial.available() == 0) { }
   command = Serial.parseInt();
   if (command == 1)
   {
    myStepper.step(-stepsPerRevolution);
    pappu();
   } 
   else if (command == 2) 
   {
    dance();
    
   }
   else if (command == 3)
   {
    Serial.println("How many steps ?");
     while(Serial.available() == 0) { }
     int rot = Serial.parseInt();
    myStepper.step(rot * stepsPerRevolution);
   }
   //delay(2000);
   //high();
   //delay(1000);
   //walk(4);
   //normal();
   //delay(4000);
   //pappu();

  // Sthlm Sunset
  
   
} 

void dance_forever() {
  while (1) {
    dance();
  }
}
void dance() {
 delay(5000);
 for (int i  = 0; i < 5; i++){
  delay(500);
  dance_random();
  delay(200);
  myStepper.step((-1) *stepsPerRevolution);
  dance_random();
  delay(200);
  dance_random();
  delay(200);
  dance_random();
  myStepper.step((1) *stepsPerRevolution);
  }
}

void dance_random() {
  int ran = random(1, 3);
  if (ran == 1) {
    dance_1();
  }
  else if (ran == 2) {
    dance_2();
  }
  else {
    dance_3();
  }
}

void pappu()
{
  // Assi machine bnaunga
  delay(400);
  right_upper.write(100);
  right_lower.write(170);
  delay(200);
  for (int i = 0; i < 10; i++)
  {
    right_lower.write(180);
    delay(100);
    
    right_lower.write(160);
    delay(100);
  }
  right_lower.write(170);
  delay(200);
  
  // is side se allu ghusega
  left_lower.write(170);
  left_upper.write(100);
  delay(400);

  // uss side se sonaa niklega
  delay(300);
  right_upper.write(180);
  right_lower.write(180);
  delay(1200);
  right_upper.write(0);
  right_lower.write(0);
  left_lower.write(0);
  left_upper.write(0);
  delay(1000);

  
  // iss side se aloo dalloo, uss side se sona nikalo
  right_upper.write(100);
  right_lower.write(170);
  delay(400);
  left_lower.write(170);
  left_upper.write(100);
  delay(500);
  right_upper.write(180);
  right_lower.write(180);
  delay(500);
  
  // itnaa paisa bnega apko .. pta nhi hoga kya krna hai iss paise ka
  right_upper.write(40);
  right_lower.write(90);
  delay(1000);

  right_upper.write(180);
  right_lower.write(180);
  delay(100);

  right_upper.write(0);
  right_lower.write(0);
  
}

void high() {
   right_lower.write(180);
   left_lower.write(180);
   left_upper.write(180);
   right_upper.write(180);
   left_leg.write(180);
   right_leg.write(180);
   Serial.println("MAXXX");
}


void dance_1() {
  // step 1
  right_lower.write(180);
  delay(200);
  for (int i = 0; i <= 180; i+=18)
  {
    left_lower.write(i);
    right_lower.write(180 - i);
    delay(60);
  }
  for (int i = 0; i <= 90; i+=18)
  {
    left_lower.write(180 - i);
    right_lower.write(i);
    delay(50);
  }
  left_lower.write(0);
  right_lower.write(0);
  delay(100);
  
}

void dance_2() {
  right_lower.write(180);
  left_leg.write(180);
  delay(200);
  for (int i = 0; i <= 180; i+=9)
  {
    left_lower.write(i);
    right_leg.write(i);
    left_leg.write(180 - i);
    right_lower.write(180 - i);
    delay(60);
  }
  for (int i = 0; i <= 90; i+=9)
  {
    left_lower.write(180 - i);
    right_lower.write(i);
    right_leg.write(180 - i);
    left_leg.write(i);
    delay(100);
  }
  
  right_leg.write(0);
  left_leg.write(0);
  left_lower.write(0);
  right_lower.write(0);
  delay(200);
  
}


void dance_3() {
  right_lower.write(180);
  left_lower.write(180);
  delay(300);
  left_leg.write(180);
  right_lower.write(180);
    
  for (int i = 0; i <= 180; i+=18)
  {
    left_upper.write(i);
    right_leg.write(i);
    left_leg.write(180 - i);
    right_lower.write(180 - i);
    delay(60);
  }
  for (int i = 0; i <= 180; i+=18)
  {
    left_upper.write(180 - i);
    right_leg.write(180 - i);
    left_leg.write(i);
    right_lower.write(i);
    delay(60);
  }
  delay(100);
}


void walk(int n) {
  for (int i = 0; i < 180; i+= 20){
    right_leg.write(i);
    delay(100);
  }
  for (int i = 0; i < n - 1; i++) {
    for (int i = 0; i < 180; i+= 20) {
      right_leg.write(180 - i);
      left_leg.write(i);
      delay(100);
    }
    for (int i = 0; i < 180; i+= 20) {
      right_leg.write(i);
      left_leg.write(180 - i);
      delay(100);
    }
  }
  right_leg.write(0);
}

void punch() {
  for(int i = 0; i < 30; i++)
  {
    right_lower.write(3 * i);
    delay(100);
  }
  for(int i = 0; i < 10; i++)
  {
    right_upper.write(i * 6);
    delay(100);
  }
}

void normal() {
  right_lower.write(0);
  left_lower.write(0);
  left_upper.write(0);
  right_upper.write(0);
  left_leg.write(0);
  right_leg.write(0);
}

void kick() {
  right_leg.write(45);
  delay(500);
  right_leg.write(0);
}


