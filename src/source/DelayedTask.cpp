
#include "DelayedTask.h"
#include "MicrosDelayedTaskTimer.h"
#include "MillisDelayedTaskTimer.h"

DelayedTask::DelayedTask(DelayedTaskTimeResolution timeResolution)
    :timer(CreateTimerForResolution(timeResolution))
{
}

DelayedTask::DelayedTask(long delay, DelayedTaskTimeResolution timeResolution)
    :timer(CreateTimerForResolution(timeResolution))
{
    timer->Start(delay);
}

bool DelayedTask::ShouldBeExecuted()
{
    return timer->CountedDown();
}

void DelayedTask::Delay(unsigned long delay)
{
    timer->Start(delay);
}

void DelayedTask::Cancel()
{
    timer->Stop();
}

void DelayedTask::Update()
{
    if (ShouldBeExecuted())
    {
        timer->Stop();
        Execute();
        wasExecuted = true;
    }
}

bool DelayedTask::WasExecuted()
{
    return wasExecuted;
}

class DelayedTaskTimer * DelayedTask::CreateTimerForResolution(DelayedTaskTimeResolution timeResolution)
{
    switch (timeResolution)
    {
    case DelayedTaskTimeResolution::Microseconds:
        return new MicrosDelayedTaskTimer();
    
    case DelayedTaskTimeResolution::Milliseconds:
        return new MillisDelayedTaskTimer();
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