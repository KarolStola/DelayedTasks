
#include <Arduino.h>
#include "MillisDelayedTaskTimer.h"
#include "DelayedTaskManager.h"

unsigned long MillisDelayedTaskTimer::GetCurrentTime()
{
    return millis();
}
