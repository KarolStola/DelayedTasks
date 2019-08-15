#ifndef DELAYED_TASK_H
#define DELAYED_TASK_H

class DelayedTask
{
public:
    DelayedTask(int delay);
    virtual void Execute() = 0;
    bool ShouldBeExecuted();
    void NotifyMillisecondsPassed(int millisecondsPassed);

private:
    int delayRemaining  = 0;
};

#endif
