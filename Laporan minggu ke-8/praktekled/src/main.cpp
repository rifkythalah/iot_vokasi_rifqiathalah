#include <Arduino.h>

// Pin sensor ultrasonik
#define TRIG_PIN 12
#define ECHO_PIN 14

// Pin lampu LED
#define RED_LED 33
#define YELLOW_LED 25

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
}

void loop() {
  long duration;
  int distance;

  // Trigger sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Baca echo
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  // Tampilkan jarak di serial monitor
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Logika lampu berdasarkan jarak
  if (distance > 0 && distance <= 20) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
  } else if (distance > 20 && distance <= 50) {
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
  } else if (distance > 50) {
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
  } else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
  }

  delay(200);
}