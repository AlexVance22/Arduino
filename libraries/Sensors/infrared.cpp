#include "infrared.h"


void InfraRed::init(byte out)
{
    p_out = out;

    pinMode(out, INPUT);
}