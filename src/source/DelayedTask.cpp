#include "DelayedTask.h"

DelayedTask::DelayedTask(int delay)
    :delayRemaining(delay)
{
}

bool DelayedTask::ShouldBeExecuted()
{
    return delayRemaining <= 0;
}

void DelayedTask::NotifyMillisecondsPassed(int millisecondsPassed)
{
    delayRemaining -= millisecondsPassed;
}