
#include "DelayedTask.h"
#include "MicrosDelayedTaskTimer.h"

DelayedTask::DelayedTask(long delay)
    :timer(new MicrosDelayedTaskTimer(delay))
{
}

bool DelayedTask::ShouldBeExecuted()
{
    return timer->CountedDown();
}

void DelayedTask::Update()
{
    if (ShouldBeExecuted())
    {
        Execute();
        wasExecuted = true;
    }
}

bool DelayedTask::WasExecuted()
{
    return wasExecuted;
}

DelayedTask::~DelayedTask()
{
    Cleanup();
}

void DelayedTask::Cleanup()
{
    delete(timer);
}