
#include "DelayedTask.h"
#include "MicrosDelayedTaskTimer.h"
#include "MillisDelayedTaskTimer.h"

DelayedTask::DelayedTask(long delay, DelayedTaskTimeResolution timeResolution)
    :timer(CreateTimerForResolution(delay, timeResolution))
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

class DelayedTaskTimer * DelayedTask::CreateTimerForResolution(long timeRemaining, DelayedTaskTimeResolution timeResolution)
{
    switch (timeResolution)
    {
    case DelayedTaskTimeResolution::Microseconds:
        return new MicrosDelayedTaskTimer(timeRemaining);
    
    case DelayedTaskTimeResolution::Milliseconds:
        return new MillisDelayedTaskTimer(timeRemaining);
    }
}

DelayedTask::~DelayedTask()
{
    Cleanup();
}

void DelayedTask::Cleanup()
{
    delete(timer);
}