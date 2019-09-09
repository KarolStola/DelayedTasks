
#ifndef DELAYED_TASK_H
#define DELAYED_TASK_H

#include "DelayedTaskTimeResolution.h"

class DelayedTask
{
public:
    DelayedTask(DelayedTaskTimeResolution timeResolution);
    DelayedTask(long delay, DelayedTaskTimeResolution timeResolution);
    void Delay(unsigned long delay);
    void Cancel();
    void Update();
    bool WasExecuted();
    virtual ~DelayedTask();

protected:
    virtual void Execute() = 0;

private:
    class DelayedTaskTimer * CreateTimerForResolution(DelayedTaskTimeResolution timeResolution);
    bool ShouldBeExecuted();
    void Cleanup();

    bool wasExecuted = false;
    class DelayedTaskTimer * timer;
};

#endif
