// ---------------------------------------------------------------- // 
// Arduino Origami Bot 
// Created by Benjamin Mannino
// Using Arduino IDE 1.8.19
// Tested Oct. 21 2025 
// ---------------------------------------------------------------- // 
const int trigPin = 9;   // TRIG pin of HC-SR04
const int echoPin = 10;  // ECHO pin of HC-SR04
const int LEDPin = 11;   // LED pin
const int in1 = 4;
const int in2 = 5;
const int in3 = 6;
const int in4 = 7;

void setup() {
  pinMode(trigPin, OUTPUT);   // TRIG is an output
  pinMode(echoPin, INPUT);    // ECHO is an input
  pinMode(in1, OUTPUT);       // in1 is an output
  pinMode(in2, OUTPUT);       // in2 is an output
  pinMode(in3, OUTPUT);       // in3 is an output
  pinMode(in4, OUTPUT);       // in4 is an output
  pinMode(LEDPin, OUTPUT);    // LEDPin is an output
  Serial.begin(9600);         // Start Serial Monitor
}

void loop() {
  // Pulse Section 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);           // Clear TRIG
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);          // Send pulse
  digitalWrite(trigPin, LOW);

  // Measurement Section
  long duration = pulseIn(echoPin, HIGH);  // microseconds
  float distance = (duration * 0.034) / 2; // convert to cm

  // Print Section
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Decision Section
  if (distance < 0 || distance > 200) {
    digitalWrite(in1, LOW);       // Turn left wheel backwards
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);      // Turn right wheel forwards
    digitalWrite(in4, LOW);
    digitalWrite(LEDPin, HIGH);   // Enable LED
  } 
  else if (distance < 10) {
    digitalWrite(in1, LOW);       // Turn left wheel backwards
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);       // Turn right wheel backwards
    digitalWrite(in4, HIGH);
    digitalWrite(LEDPin, LOW);    // Disable LED
  } 
  else if (distance < 20) {
    digitalWrite(in1, LOW);       // No left wheel movement
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);       // No right wheel movement
    digitalWrite(in4, LOW);
    digitalWrite(LEDPin, LOW);    // Disable LED
  } 
  else {
    digitalWrite(in1, HIGH);      // Turn left wheel forwards
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);      // Turn right wheel forwards
    digitalWrite(in4, LOW);
    digitalWrite(LEDPin, LOW);    // Disable LED
  }

  delay(10); // wait 0.01s 
}
