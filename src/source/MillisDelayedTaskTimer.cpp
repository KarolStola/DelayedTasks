
#include "MillisDelayedTaskTimer.h"
#include "DelayedTaskManager.h"

MillisDelayedTaskTimer::MillisDelayedTaskTimer(long timeRemainging)
    : DelayedTaskTimer(timeRemainging)
{
}

unsigned long MillisDelayedTaskTimer::GetDeltaTime()
{
    return DelayedTaskManager::Get().GetDeltaMillis();
}
