
#include "DelayedTaskTimer.h"

void DelayedTaskTimer::Start(unsigned long newDelay)
{
    delay = newDelay;
    Restart();
}

void DelayedTaskTimer::Restart()
{
    isStarted = true;
    startTime = GetCurrentTime();
}

void DelayedTaskTimer::Stop()
{
    isStarted = false;
}

bool DelayedTaskTimer::CountedDown()
{
    if(isStarted)
    {
        return GetElapsedTime() >= delay;
    }
    else
    {
        return false;
    }
    
} 

unsigned long DelayedTaskTimer::GetElapsedTime()
{
    if(isStarted)
    {
        return GetCurrentTime() - startTime;
    }
    else
    {
        return 0;
    }
    
}

