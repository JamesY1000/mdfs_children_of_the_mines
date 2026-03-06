#include <Arduino.h>
#include <Servo.h>

// Setup pinouts
Servo gripperServo;

const int GRIPPER_SERVO_PIN = 2;

const int open_gripper = 180;
const int close_gripper = 75;

int current_position = open_gripper;

void setup() {
  Serial.begin(115200);
  gripperServo.attach(GRIPPER_SERVO_PIN);

  // Start open
  gripperServo.write(open_gripper);
  current_position = open_gripper;
  Serial.println("Gripper servo ready. Send 'o' to open, 'c' to close.");
}

void loop() {

  if (Serial.available() > 0)
  {
    char cmd = Serial.read();

    // Open gripper (decrease toward 0)
    if (cmd == 'o' && current_position < open_gripper)
    {
      current_position++;
      gripperServo.write(current_position);
      Serial.print("Opening: ");
      Serial.println(current_position);
    }
    // Close gripper (increase toward 180)
    else if (cmd == 'c' && current_position > close_gripper) 
    {
      current_position--;
      gripperServo.write(current_position);
      Serial.print("Closing: ");
      Serial.println(current_position);
    }
  }

}