
#ifndef DELAYED_TASK_H
#define DELAYED_TASK_H

#include "DelayedTaskTimeResolution.h"

class DelayedTask
{
public:
    DelayedTask(long delay, DelayedTaskTimeResolution timeResolution);
    void Update();
    bool WasExecuted();
    virtual ~DelayedTask();

protected:
    virtual void Execute() = 0;

private:
    class DelayedTaskTimer * CreateTimerForResolution(long timeRemaining, DelayedTaskTimeResolution timeResolution);
    bool ShouldBeExecuted();
    void Cleanup();

    bool wasExecuted = false;
    class DelayedTaskTimer * timer;
};

#endif
