#include <Arduino.h>
#include "MicrosDelayedTaskTimer.h"

unsigned long MicrosDelayedTaskTimer::GetCurrentTime()
{
    return micros();
}
