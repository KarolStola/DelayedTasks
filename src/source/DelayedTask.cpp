#include "DelayedTask.h"

DelayedTask::DelayedTask(int delay)
    :delayRemaining(delay)
{
}

bool DelayedTask::ShouldBeExecuted()
{
    return delayRemaining <= 0;
}

void DelayedTask::Update(unsigned long deltaTime)
{
    delayRemaining -= deltaTime;

    if (ShouldBeExecuted())
    {
        Execute();
    }
}

bool DelayedTask::WasExecuted()
{
    return ShouldBeExecuted();
}