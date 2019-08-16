
#ifndef DELAYED_TASK_H
#define DELAYED_TASK_H

class DelayedTask
{
public:
    DelayedTask(int delay);
    void Update(unsigned long deltaTime);
    bool WasExecuted();

protected:
    virtual void Execute() = 0;

private:
    bool ShouldBeExecuted();
    
    int delayRemaining  = 0;
};

#endif
