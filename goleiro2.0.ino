#include <Ultrasonic.h>
#include <Servo.h>

#define SERVO_PIN   8

#define ECHO        6
#define TRIGGER     7

Ultrasonic ultrasonic(ECHO, TRIGGER);

Servo servoMotor;

int distance;

void setup() {
  servoMotor.attach(SERVO_PIN);
  Serial.begin(9600);
  Serial.println("<<< Bem vindo ao goleiro robotico >>>");
  delay(2000);
}

void loop() {
  distance = ultrasonic.read();

  if (distance > 0 && distance < 12) {
    servoMotor.write(10);
    delay(2000);
  } else if (distance > 14 && distance < 28) {
    servoMotor.write(170);
    delay(2000);
  } else {
    servoMotor.write(90);
  }
  
  Serial.println(distance);
  delay(5);
}
