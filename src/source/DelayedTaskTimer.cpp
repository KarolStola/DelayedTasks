
#include "DelayedTaskManager.h"
#include "DelayedTaskTimer.h"

DelayedTaskTimer::DelayedTaskTimer(unsigned long delay, unsigned long startTime)
    : delay(delay)
    , startTime(startTime)
{
}

bool DelayedTaskTimer::CountedDown()
{
    return GetElapsedTime() >= delay;
} 

unsigned long DelayedTaskTimer::GetElapsedTime()
{
    return GetCurrentTime() - startTime;
}

