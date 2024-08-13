#include "LineModeHandler.h"

PhoneSystem::PhoneSystem() {
    // Initialize all phones to idle state
    for (int i = 0; i < 8; ++i) {
        phones[i].current_mode = call_idle;
        phones[i].line_number = i;
    }
}

void PhoneSystem::setPhoneMode(int line, modes new_mode) {
    if (line >= 0 && line < 8) {
        phones[line].current_mode = new_mode;
    } else {
        Serial.println(F("Invalid phone line!"));
    }
}

modes PhoneSystem::getPhoneMode(int line) {
    if (line >= 0 && line < 8) {
        return phones[line].current_mode;
    }
    Serial.println(F("Invalid phone line!"));
    return call_idle;  // Return default state for invalid line
}

void PhoneSystem::displayAllPhoneStatus() {
    for (int i = 0; i < 8; ++i) {
        Serial.print(F("Line "));
        Serial.print(phones[i].line_number);
        Serial.print(F(": "));
        Serial.println(getModeString(phones[i].current_mode));
    }
}

const __FlashStringHelper* PhoneSystem::getModeString(modes mode) {
    // Convert enum to string representation
    // Using F() macro to store strings in flash memory
    switch(mode) {
        case call_idle: return F("Idle");
        case call_ready: return F("Ready");
        case call_pulse_dialing: return F("Pulse Dialing");
        case call_tone_dialing: return F("Tone Dialing");
        case call_connecting: return F("Connecting");
        case call_busy: return F("Busy");
        case call_fail: return F("Fail");
        case call_ringing: return F("Ringing");
        case call_connected: return F("Connected");
        case call_disconnected: return F("Disconnected");
        case call_timeout: return F("Timeout");
        case call_abandoned: return F("Abandoned");
        case call_incoming: return F("Incoming");
        case call_operator: return F("Operator");
        case system_config: return F("System Config");
        default: return F("Unknown");
    }
}
