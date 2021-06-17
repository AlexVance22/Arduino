#ifndef ULTRASOUND_H
#define ULTRASOUND_H

#include <arduino.h>


class UltraSound
{
    byte p_trigger;
    byte p_echo;

public:
    void init(byte trigger, byte echo);
    unsigned long getAsMicroseconds();
};

#endif