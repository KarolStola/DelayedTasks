
#ifndef DELAYED_TASK_TIMER_H
#define DELAYED_TASK_TIMER_H

class DelayedTaskTimer
{
public:
    DelayedTaskTimer(long timeRemaining);
    void Update();
    bool CountedDown();

protected:
    virtual unsigned long GetDeltaTime() = 0;

private:
    long timeRemaining = 0;
};

#endif
