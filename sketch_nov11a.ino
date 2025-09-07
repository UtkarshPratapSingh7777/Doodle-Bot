
const int leftMotorForward = 11;
const int leftMotorBackward = 10;
const int rightMotorForward = 6;//11
const int rightMotorBackward =5;//10


const int forwardSpeed = 80;  
const int turnSpeed = 80;     

void setup() {
  
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);
}

void moveForward(int duration) {
  analogWrite(leftMotorForward, forwardSpeed);
  analogWrite(rightMotorForward, forwardSpeed);
  analogWrite(leftMotorBackward, 0);
  analogWrite(rightMotorBackward, 0);
  delay(duration);
  stopBot();
}

void turnLeft() {
  analogWrite(leftMotorForward, 0);
  analogWrite(rightMotorForward, turnSpeed);
  analogWrite(leftMotorBackward, 0);
  analogWrite(rightMotorBackward, 0);
  delay(1300); 
  stopBot();
}

void turnRight() {
  analogWrite(leftMotorForward, turnSpeed);
  analogWrite(rightMotorForward, 0);
  analogWrite(leftMotorBackward, 0);
  analogWrite(rightMotorBackward, 0);
  delay(1300);  
  stopBot();
}

void stopBot() {
  analogWrite(leftMotorForward, 0);
  analogWrite(leftMotorBackward, 0);
  analogWrite(rightMotorForward, 0);
  analogWrite(rightMotorBackward, 0);
}

void loop() {
 
  char instructions[] = {'S', 'L', 'R', 'L', 'R', 'L', 'L', 'E'};
  int numInstructions = sizeof(instructions) / sizeof(instructions[0]);

  
  for (int i = 0; i < numInstructions; i++) {
    char instruction = instructions[i];
    
    if (instruction == 'S') {
      moveForward(3000);  
    }
    else if (instruction == 'L') {
      turnLeft();
      delay(800);         
      moveForward(3000);  
    }
    else if (instruction == 'R') {
      turnRight();
      delay(800);         
      moveForward(3000);  
    }
    else if (instruction == 'E') {
      stopBot(); 
      break;      
    }

  }

  
  delay(2000);  
}
