// Define pins for motor 1
int motor1_pin1 = 13;
int motor1_pin2 = 12;
int motor1_enable = 11; // PWM pin for motor 1

// Define pins for motor 2
int motor2_pin1 = 9;
int motor2_pin2 = 8;
int motor2_enable = 10; // PWM pin for motor 2

// Define pins for ultrasonic sensor
int trig_pin = A3;
int echo_pin = A2;

// Define variables for ultrasonic sensor
long duration;
int distance;

void setup() {
  // Set motor pins as outputs
  pinMode(motor1_pin1, OUTPUT);
  pinMode(motor1_pin2, OUTPUT);
  pinMode(motor1_enable, OUTPUT);
  pinMode(motor2_pin1, OUTPUT);
  pinMode(motor2_pin2, OUTPUT);
  pinMode(motor2_enable, OUTPUT);

  // Set ultrasonic sensor pins
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

  // Initialize Serial communication
  Serial.begin(9600);
}

void loop() {
  // Trigger ultrasonic sensor to send pulse
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  // Measure the duration of the pulse
  duration = pulseIn(echo_pin, HIGH);

  // Calculate distance
  distance = duration * 0.034 / 2;

  // Print distance to serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If distance is less than 30cm, stop motors
  if (distance < 30) {
    digitalWrite(motor1_enable, LOW); // Stop motor 1
    digitalWrite(motor2_enable, LOW); // Stop motor 2
  } else {
    // Run motors forward
    digitalWrite(motor1_enable, HIGH);
    digitalWrite(motor1_pin1, HIGH);
    digitalWrite(motor1_pin2, LOW);
    analogWrite(motor1_enable, 255); // Full speed

    digitalWrite(motor2_enable, HIGH);
    digitalWrite(motor2_pin1, HIGH);
    digitalWrite(motor2_pin2, LOW);
    analogWrite(motor2_enable, 255); // Full speed
  }

  delay(100); // Adjust the delay as needed
}
