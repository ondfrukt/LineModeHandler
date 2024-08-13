#ifndef LineModeHandler_h
#define LineModeHandler_h
#include <Arduino.h>

enum modes {
    call_idle, call_ready, call_pulse_dialing, call_tone_dialing,
    call_connecting, call_busy, call_fail, call_ringing,
    call_connected, call_disconnected, call_timeout,
    call_abandoned, call_incoming, call_operator, system_config
};

struct Phone {
    modes current_mode;
    int line_number;
};

class PhoneSystem {
public:
    PhoneSystem();
    void setPhoneMode(int line, modes new_mode);
    modes getPhoneMode(int line);
    void displayAllPhoneStatus();

private:
    Phone phones[8];
    const __FlashStringHelper* getModeString(modes mode);
};

#endif
