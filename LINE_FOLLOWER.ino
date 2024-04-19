 // Define pins for IR sensors
const int SENSOR_LEFT = A0;
const int SENSOR_CENTER = A1;
const int SENSOR_RIGHT = A2;

// Define pins for motor control
const int MOTOR_LEFT_IN1 = 2;
const int MOTOR_LEFT_IN2 = 3;
const int MOTOR_RIGHT_IN1 = 4;
const int MOTOR_RIGHT_IN2 = 5;

// Define threshold for sensor readings
const int THRESHOLD = 500;

void setup() {
  // Initialize motor control pins as outputs
  pinMode(MOTOR_LEFT_IN1, OUTPUT);
  pinMode(MOTOR_LEFT_IN2, OUTPUT);
  pinMode(MOTOR_RIGHT_IN1, OUTPUT);
  pinMode(MOTOR_RIGHT_IN2, OUTPUT);

  // Initialize sensor pins as inputs
  pinMode(SENSOR_LEFT, INPUT);
  pinMode(SENSOR_CENTER, INPUT);
  pinMode(SENSOR_RIGHT, INPUT);
}

void loop() {
  // Read sensor values
  int leftSensor = analogRead(SENSOR_LEFT);
  int centerSensor = analogRead(SENSOR_CENTER);
  int rightSensor = analogRead(SENSOR_RIGHT);

  // Make decisions based on sensor readings
  if (leftSensor < THRESHOLD && centerSensor < THRESHOLD && rightSensor < THRESHOLD) {
    // All sensors off the line - Stop
    stopMotors();
  } else if (leftSensor > THRESHOLD && centerSensor < THRESHOLD && rightSensor > THRESHOLD) {
    // On the line - Go forward
    moveForward();
  } else if (leftSensor < THRESHOLD && centerSensor > THRESHOLD && rightSensor < THRESHOLD) {
    // Turn right
    turnRight();
  } else if (leftSensor > THRESHOLD && centerSensor > THRESHOLD && rightSensor < THRESHOLD) {
    // Slight right adjustment
    slightRight();
  } else if (leftSensor < THRESHOLD && centerSensor > THRESHOLD && rightSensor > THRESHOLD) {
    // Turn left
    turnLeft();
  } else if (leftSensor < THRESHOLD && centerSensor < THRESHOLD && rightSensor > THRESHOLD) {
    // Slight left adjustment
    slightLeft();
  }

  // Adjust the delay time as needed
  delay(100);
}

// Function to stop both motors
void stopMotors() {
  digitalWrite(MOTOR_LEFT_IN1, LOW);
  digitalWrite(MOTOR_LEFT_IN2, LOW);
  digitalWrite(MOTOR_RIGHT_IN1, LOW);
  digitalWrite(MOTOR_RIGHT_IN2, LOW);
}

// Function to move forward
void moveForward() {
  digitalWrite(MOTOR_LEFT_IN1, HIGH);
  digitalWrite(MOTOR_LEFT_IN2, LOW);
  digitalWrite(MOTOR_RIGHT_IN1, HIGH);
  digitalWrite(MOTOR_RIGHT_IN2, LOW);
}

// Function to turn left
void turnLeft() {
  digitalWrite(MOTOR_LEFT_IN1, LOW);
  digitalWrite(MOTOR_LEFT_IN2, HIGH);
  digitalWrite(MOTOR_RIGHT_IN1, HIGH);
  digitalWrite(MOTOR_RIGHT_IN2, LOW);
}

// Function to turn right
void turnRight() {
  digitalWrite(MOTOR_LEFT_IN1, HIGH);
  digitalWrite(MOTOR_LEFT_IN2, LOW);
  digitalWrite(MOTOR_RIGHT_IN1, LOW);
  digitalWrite(MOTOR_RIGHT_IN2, HIGH);
}

// Function for a slight left adjustment
void slightLeft() {
  digitalWrite(MOTOR_LEFT_IN1, LOW);
  digitalWrite(MOTOR_LEFT_IN2, LOW);
  digitalWrite(MOTOR_RIGHT_IN1, HIGH);
  digitalWrite(MOTOR_RIGHT_IN2, LOW);
}

// Function for a slight right adjustment
void slightRight() {
  digitalWrite(MOTOR_LEFT_IN1, HIGH);
  digitalWrite(MOTOR_LEFT_IN2, LOW);
  digitalWrite(MOTOR_RIGHT_IN1, LOW);
  digitalWrite(MOTOR_RIGHT_IN2, LOW);
}
