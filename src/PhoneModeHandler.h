#ifndef PhoneModeHandler_h
#define PhoneModeHandler_h

#include <Arduino.h>

// Enum representing all possible states of a phone
enum modes {
    call_idle,          // Phone is not in use
    call_ready,         // Dial tone is playing, waiting for input
    call_pulse_dialing, // Old-style rotary dialing in progress
    call_tone_dialing,  // Modern touch-tone dialing in progress
    call_connecting,    // Attempting to establish a connection
    call_busy,          // Receiving busy signal
    call_fail,          // Call failed to connect
    call_ringing,       // Phone is ringing (outgoing call)
    call_connected,     // Call is active
    call_disconnected,  // Call has ended, but line not yet idle
    call_timeout,       // Call timed out
    call_abandoned,     // Call was abandoned
    call_incoming,      // Incoming call
    call_operator,      // Connected to operator
    system_config       // Phone is in configuration mode
};

// Structure representing a single phone
struct Phone {
    modes current_mode; // Current state of the phone
    int line_number;    // Identifier for the phone line (0-7)
};

class PhoneSystem {
public:
    PhoneSystem();
    // Set the mode of a specific phone line
    void setPhoneMode(int line, modes new_mode);
    // Get the current mode of a specific phone line
    modes getPhoneMode(int line);
    // Display the status of all phone lines
    void displayAllPhoneStatus();
private:
    Phone phones[8];  // Array to hold 8 phone lines
    // Helper function to convert mode enum to string
    const __FlashStringHelper* getModeString(modes mode);
};
#endif
