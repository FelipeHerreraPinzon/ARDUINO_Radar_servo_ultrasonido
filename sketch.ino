#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 11;

Servo myServo;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin);
}

void loop() {
  for (int pos = 0; pos <= 180; pos += 1) {
    myServo.write(pos);
    delay(50);
    long duration = measureDistance();
    long distance = duration * 0.034 / 2;
    Serial.print("Angle: ");
    Serial.print(pos);
    Serial.print(" Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  for (int pos = 180; pos >= 0; pos -= 1) {
    myServo.write(pos);
    delay(50);
    long duration = measureDistance();
    long distance = duration * 0.034 / 2;
    Serial.print("Angle: ");
    Serial.print(pos);
    Serial.print(" Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
}

long measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration;
}
