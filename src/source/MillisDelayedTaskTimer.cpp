
#include <Arduino.h>
#include "MillisDelayedTaskTimer.h"

unsigned long MillisDelayedTaskTimer::GetCurrentTime()
{
    return millis();
}
