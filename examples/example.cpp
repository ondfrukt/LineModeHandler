#include <Arduino.h>
#include "PhoneModeHandler.h"

PhoneSystem phoneSystem;  // Create an instance of the PhoneSystem

void setup() {
    Serial.begin(9600);  // Initialize serial communication
    
    // Example usage: Set modes for a couple of phone lines
    phoneSystem.setPhoneMode(0, call_ringing);
    phoneSystem.setPhoneMode(3, call_connected);
}

void loop() {
    Serial.println(F("Status of all phones:"));
    phoneSystem.displayAllPhoneStatus();
    delay(5000);  // Wait for 5 seconds before next update
}
