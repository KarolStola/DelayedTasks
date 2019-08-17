
#ifndef DELAYED_TASK_TIMER_H
#define DELAYED_TASK_TIMER_H

class DelayedTaskTimer
{
public:
    DelayedTaskTimer(unsigned long delay, unsigned long startTime);
    bool CountedDown();
    unsigned long GetElapsedTime();

protected:
    virtual unsigned long GetCurrentTime() = 0;

private:
    
    unsigned long delay = 0;
    unsigned long startTime = 0;
};

#endif
