//Arduino programming language (C++)

//Left Sensor(LSP) on digitalPin2
//Right Sensor(PSp) on digitalPin3
int LSP = 12;
int RSP = 13;

//Left Motor connected to 4, 5 digitalPins
//Right Motor connected to 10, 9 digitalPins
int LMP = 15;
int LMN = 14;
int RMP = 2;
int RMN = 16;
int en1 = 3;
int en2 = 1;


void setup() {
  // put your setup code here, to run once:
  //Sensor pins are INPUT
  pinMode(LSP, INPUT);
  pinMode(RSP, INPUT);

  //Motor pins are OUTPUT
  pinMode(LMP, OUTPUT);
  pinMode(LMN, OUTPUT);
  pinMode(RMP, OUTPUT);
  pinMode(RMN, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  analogWrite(en1, 150);
  analogWrite(en2, 150);

}

void loop() {
  // put your main code here, to run repeatedly:
  //Read sensor data and store it
  int LSD = digitalRead(LSP);
  int RSD = digitalRead(RSP);

  //Check the sensor Data
  //LSD and RSD are 0 if both are on white
  if (LSD == 0 && RSD == 0){
    //Move Forward
    digitalWrite(LMP, LOW);
    digitalWrite(LMN, HIGH);
    digitalWrite(RMP, HIGH);
    digitalWrite(RMN, LOW);
  }

  //LSD and RSD are 1, 0 if left sensor is on Block
  //RIght Sensor is on WHite
  else if (LSD == 1 && RSD == 0){
    //Left Turn
    digitalWrite(LMP, HIGH);
    digitalWrite(LMN, LOW);
    digitalWrite(RMP, HIGH);
    digitalWrite(RMN, LOW);
  }

  //LSD and RSD are 0,1 if Left Sensor is on white
  //RIght Sensor is on Black
  else if (LSD == 0 && RSD == 1){
    //Right Turn
    digitalWrite(LMP, LOW);
    digitalWrite(LMN, HIGH);
    digitalWrite(RMP, LOW);
    digitalWrite(RMN, HIGH);
  
  }

  //LSD and RSD are 1, 1 if Left Sensor is on Black
  //RIght sensor is on Black
  else if (LSD == 1 && RSD == 1){
    //Stop
    digitalWrite(LMP, LOW);
    digitalWrite(LMN, LOW);
    digitalWrite(RMP, LOW);
    digitalWrite(RMN, LOW);
  }

}
