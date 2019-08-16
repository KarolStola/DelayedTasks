
#include "DelayedTask.h"
#include "MillisDelayedTaskTimer.h"

DelayedTask::DelayedTask(long delay)
    :timer(new MillisDelayedTaskTimer(delay))
{
}

bool DelayedTask::ShouldBeExecuted()
{
    return timer->CountedDown();
}

void DelayedTask::Update()
{
    timer->Update();

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