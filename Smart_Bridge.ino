#include <Servo.h>

Servo left_servo;            // Servo 1
Servo right_servo;           // Servo 2
int moisture_sensor_pin = A0; // Analog pin for the moisture sensor
int left_servo_pin = 5;
int right_servo_pin = 6;
int buzzer_pin = 8;          // Digital pin for the buzzer

const int moistureThreshold = 900;  // Adjust this threshold value as needed
bool isFlooded = false;
bool bridgeRaised = false;

void setup() {
  left_servo.attach(left_servo_pin);
  right_servo.attach(right_servo_pin);
  pinMode(moisture_sensor_pin, INPUT);
  pinMode(buzzer_pin, OUTPUT);
  lowerBridge();  // Ensure the bridge is initially lowered
}

void loop() {
  int moistureValue = analogRead(moisture_sensor_pin);

  if (moistureValue > moistureThreshold) {
    if (!isFlooded) {
      // Flood detected, raise the bridge
      raiseBridge();
      alert();
      isFlooded = true;
    }
  } else {
    if (isFlooded) {
      // No flood, lower the bridge
      lowerBridge();
      isFlooded = false;
    }
  }
}

void raiseBridge() {
  if (!bridgeRaised) {
    left_servo.write(0);  // Angle to raise the bridge (adjust as needed)
    right_servo.write(0);
    bridgeRaised = true;
  }
}

void lowerBridge() {
  if (bridgeRaised) {
    left_servo.write(90);  // Angle to lower the bridge (adjust as needed)
    right_servo.write(90);
    bridgeRaised = false;
  }
}

void alert() {
  digitalWrite(buzzer_pin, HIGH); delay(2000); digitalWrite(buzzer_pin, LOW); 
}