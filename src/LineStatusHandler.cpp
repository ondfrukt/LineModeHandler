#include "LineStatusHandler.h"

LineSystem::LineSystem() {
    // Initialize all lines to idle state
    for (int i = 0; i < 8; ++i) {
        lineArray[i].line_number = i;
        lineArray[i].current_status = line_idle;
    }
}

void LineSystem::setLineStatus(int lineNumber, statuses new_status) {
    
    // Uppdating line status and store time when last changed
    if (lineNumber >= 0 && lineNumber < 8) {
        lineArray[lineNumber].previus_status = lineArray[lineNumber].current_status:
        lineArray[lineNumber].current_status = new_status;
        lineArray[lineNumber].lastTimeChanged = millis();
    } else {
        Serial.println("Invalid line number!");
    }
}

statuses LineSystem::getCurrentLineStatus(int lineNumber) {
    if (lineNumber >= 0 && lineNumber < 8) {
        return lines[lineNumber].current_status;
    }
    Serial.println("Invalid line number!");
    return line_idle;  // Return default state for invalid line
}

statuses LineSystem::getPreviousLineStatus(int lineNumber) {
    if (lineNumber >= 0 && lineNumber < 8) {
        return lines[lineNumber].previous_status;
    }
    Serial.println("Invalid line number!");
    return line_idle;  // Return default state for invalid line
}



void LineSystem::displayAllLineStatuses() {
    for (int i = 0; i < 8; ++i) {
        Serial.print("Line ");
        Serial.print(lines[i].line_number);
        Serial.print(": ");
        Serial.println(getStatusString(lines[i].current_status));
    }
}

const char* LineSystem::getStatusString(statuses status) {
    // Convert enum to string representation
    switch(status) {
        case line_idle: return "Idle";
        case line_ready: return "Ready";
        case line_pulse_dialing: return "Pulse Dialing";
        case line_tone_dialing: return "Tone Dialing";
        case line_connecting: return "Connecting";
        case line_busy: return "Busy";
        case line_fail: return "Fail";
        case line_ringing: return "Ringing";
        case line_connected: return "Connected";
        case line_disconnected: return "Disconnected";
        case line_timeout: return "Timeout";
        case line_abandoned: return "Abandoned";
        case line_incoming: return "Incoming";
        case line_operator: return "Operator";
        case system_config: return "System Config";
        default: return "Unknown";
    }
}
