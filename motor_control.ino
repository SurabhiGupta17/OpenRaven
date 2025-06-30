#define DIR_LEFT 4
#define PWM_LEFT 5
#define DIR_RIGHT 6
#define PWM_RIGHT 7

#define TRIG_PIN 8
#define ECHO_PIN 9

const int speedVal = 130;
char currentCommand = 's';

void setup() {
  pinMode(DIR_LEFT, OUTPUT);
  pinMode(PWM_LEFT, OUTPUT);
  pinMode(DIR_RIGHT, OUTPUT);
  pinMode(PWM_RIGHT, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(9600);

  stopMotors();
}

void loop() {
  if (Serial.available()) {
    char newCommand = Serial.read();

    while(Serial.available()) {
      Serial.read();
    }

    if (newCommand != currentCommand) {
      currentCommand = newCommand;
      executeCommand();
    }
  }

  delay(50); 
}

void executeCommand() {
  int distance = getDistance();

  if ((currentCommand == 'f' || currentCommand == 'b') && distance < 10) {
    stopMotors();  // obstacle too close
    return;
  }

  if (currentCommand == 'f') {
    moveForward();
  } else if (currentCommand == 'b') {
    moveBackward();
  } else if (currentCommand == 'l') {
    turnLeft();
  } else if (currentCommand == 'r') {
    turnRight();
  } else {
    stopMotors();
  }
}

void moveForward() {
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  analogWrite(5, speedVal);
  analogWrite(7, speedVal);
}

void moveBackward() {
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  analogWrite(5, speedVal);
  analogWrite(7, speedVal);
}

void turnLeft() {
  digitalWrite(4, LOW);
  digitalWrite(6, HIGH);
  analogWrite(5, speedVal);
  analogWrite(7, speedVal);
}

void turnRight() {
  digitalWrite(4, HIGH);
  digitalWrite(6, LOW);
  analogWrite(5, speedVal);
  analogWrite(7, speedVal);
}

void stopMotors() {
  analogWrite(5, 0);
  analogWrite(7, 0);
}

int getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}
