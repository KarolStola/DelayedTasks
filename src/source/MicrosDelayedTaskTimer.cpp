#include <Arduino.h>
#include "MicrosDelayedTaskTimer.h"

MicrosDelayedTaskTimer::MicrosDelayedTaskTimer(long timeRemainging)
    : DelayedTaskTimer(timeRemainging, GetCurrentTime())
{
}

unsigned long MicrosDelayedTaskTimer::GetCurrentTime()
{
    return micros();
}
