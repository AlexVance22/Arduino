#ifndef INFRARED_H
#define INFRARED_H

#include <arduino.h>


class InfraRed
{
    byte p_out;

public:
    void init(byte out);
    bool get() { return digitalRead(p_out); }
};

#endif