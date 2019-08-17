
#include <Arduino.h>
#include "MillisDelayedTaskTimer.h"
#include "DelayedTaskManager.h"

MillisDelayedTaskTimer::MillisDelayedTaskTimer(long timeRemainging)
    : DelayedTaskTimer(timeRemainging, GetCurrentTime())
{
}

unsigned long MillisDelayedTaskTimer::GetCurrentTime()
{
    return millis();
}
