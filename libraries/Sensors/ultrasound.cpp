#include "ultrasound.h"


void UltraSound::init(byte trigger, byte echo)
{
    p_trigger = trigger;
    p_echo = echo;

    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
}

unsigned long UltraSound::getAsMicroseconds()
{
    delayMicroseconds(2);
    digitalWrite(p_trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(p_trigger, LOW);

    return pulseIn(p_echo, HIGH);
}