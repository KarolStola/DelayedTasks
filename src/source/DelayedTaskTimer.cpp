
#include "DelayedTaskManager.h"
#include "DelayedTaskTimer.h"

DelayedTaskTimer::DelayedTaskTimer(long timeRemaining)
    : timeRemaining(timeRemaining)
{
}

bool DelayedTaskTimer::CountedDown()
{
    return timeRemaining <= 0;
} 

void DelayedTaskTimer::Update()
{
    timeRemaining -= GetDeltaTime();
}
