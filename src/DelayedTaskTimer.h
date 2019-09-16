
#ifndef DELAYED_TASK_TIMER_H
#define DELAYED_TASK_TIMER_H

class DelayedTaskTimer
{
public:
    void Start(unsigned long delay);
    void Restart();
    void Stop();
    bool CountedDown();
    unsigned long GetElapsedTime();

protected:
    virtual unsigned long GetCurrentTime() = 0;

private:
    bool isStarted = false;
    unsigned long delay = 0;
    unsigned long startTime = 0;
};

#endif
