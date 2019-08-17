
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
    }
}

bool DelayedTask::WasExecuted()
{
    return ShouldBeExecuted();
}

DelayedTask::~DelayedTask()
{
    Cleanup();
}

void DelayedTask::Cleanup()
{
    delete(timer);
}