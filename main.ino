#define m1 7  //Right Motor MA1
#define m2 6  //Right Motor MA2
#define m3 4  //Left Motor MB1
#define m4 5  //Left Motor MB2
#define e1 11  //Right Motor Enable Pin EA
#define e2 3 //Left Motor Enable Pin EB

//**********6 Channel IR Sensor Connection**********//
#define ir1 A1
#define ir2 A2
#define ir3 A3
#define ir4 A4
#define ir5 A5
#define ir6 8

//*************************************************//

void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
  pinMode(ir6, INPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  
}

void loop() {
  int x=255;
  //Reading Sensor Values
  int s1 = digitalRead(ir1);  //Left Most Sensor
  int s2 = digitalRead(ir2);  //Left Sensor
  int s3 = digitalRead(ir3);  //Middle Sensor
  int s4 = digitalRead(ir4);  //Right Sensor
  int s5 = digitalRead(ir5);  //Right Most Sensor
  int s6 = digitalRead(ir6);  //Sensor for stoping condition
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);

  //if only middle sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  {
    //going forward with full speed 
    analogWrite(e1, x); //you can adjust the speed of the motors from 0-x
    analogWrite(e2, x); //you can adjust the speed of the motors from 0-x
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }
  
  //if only left sensor detects black line
  if((s1 == 1) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
    //going right with full speed 
    analogWrite(e1, x); //you can adjust the speed of the motors from 0-x
    analogWrite(e2, x); //you can adjust the speed of the motors from 0-x
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }
  
  //if only left most sensor detects black line
  if((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
    //going right with full speed 
    analogWrite(e1, x); //you can adjust the speed of the motors from 0-x
    analogWrite(e2, x); //you can adjust the speed of the motors from 0-x
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
  }

  //if only right sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 1))
  {
    //going left with full speed 
    analogWrite(e1, x); //you can adjust the speed of the motors from 0-x
    analogWrite(e2, x); //you can adjust the speed of the motors from 0-x
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }

  //if only right most sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 0))
  {
    //going left with full speed 
    analogWrite(e1, x); //you can adjust the speed of the motors from 0-x
    analogWrite(e2, x); //you can adjust the speed of the motors from 0-x
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }

  //if middle and right sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 1))
  {
    //going left with full speed 
    analogWrite(e1, x); //you can adjust the speed of the motors from 0-x
    analogWrite(e2, x); //you can adjust the speed of the motors from 0-x
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }

  //if middle and left sensor detects black line
  if((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  {
    //going right with full speed 
    analogWrite(e1, x); //you can adjust the speed of the motors from 0-x
    analogWrite(e2, x); //you can adjust the speed of the motors from 0-x
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }

  //if middle, left and left most sensor detects black line
  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  {
    //going right with full speed 
    analogWrite(e1, x); //you can adjust the speed of the motors from 0-x
    analogWrite(e2, x); //you can adjust the speed of the motors from 0-x
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }

  //if middle, right and right most sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {
    //going left with full speed 
    analogWrite(e1, x); //you can adjust the speed of the motors from 0-x
    analogWrite(e2, x); //you can adjust the speed of the motors from 0-x
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }
  if((s1 == 0) && (s2 == 1) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  {
    //going right with full speed 
    analogWrite(e1, x); //you can adjust the speed of the motors from 0-x
    analogWrite(e2, x); //you can adjust the speed of the motors from 0-x
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
    delay(500);
  }
  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 1) && (s5 == 0))
  {
    //going left with full speed 
    analogWrite(e1, x); //you can adjust the speed of the motors from 0-x
    analogWrite(e2, x); //you can adjust the speed of the motors from 0-x
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
    delay(500);
      }
   
if((s1 == 0) && (s2 == 0) &&(s3 ==0) && (s4 == 0) && (s5 == 0) && (s6==1))
  {
    //going forward with full speed 
    analogWrite(e1, x); //you can adjust the speed of the motors from 0-x
    analogWrite(e2, x); //you can adjust the speed of the motors from 0-x
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
  }
  //if all sensors are on a black line
  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0) && (s6==0))
  {
    //stop
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }
}