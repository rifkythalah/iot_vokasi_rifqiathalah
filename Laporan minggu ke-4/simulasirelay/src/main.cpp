#include <Arduino.h>

// Define pin numbers
const int ButtonPin = 19;  // GPIO19 connected to the pushbutton
const int LedPin = 18;     // GPIO18 connected to the LED
const int RelayPin = 23;   // GPIO23 connected to the relay module

void setup() {
  Serial.begin(115200); 
  pinMode(ButtonPin, INPUT_PULLUP);  // Set the button pin as an input with an internal pull-up resistor
  pinMode(LedPin, OUTPUT);           // Set the LED pin as an output
  pinMode(RelayPin, OUTPUT);         // Set the relay pin as an output

  // Initialize the outputs to be OFF
  digitalWrite(LedPin, LOW);
  digitalWrite(RelayPin, LOW);
}

void loop() {
    int buttonState = digitalRead(ButtonPin);
    
    Serial.print("Button State: ");
    Serial.println(buttonState);
    
    if (buttonState == LOW) {
      Serial.println("LED & Relay ON");
      digitalWrite(LedPin, HIGH);
      digitalWrite(RelayPin, HIGH);
    } else {
      Serial.println("LED & Relay OFF");
      digitalWrite(LedPin, LOW);
      digitalWrite(RelayPin, LOW);
    }
    delay(200); 
  }
  
