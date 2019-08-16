
#ifndef DELAYED_TASK_H
#define DELAYED_TASK_H

class DelayedTask
{
public:
    DelayedTask(long delay);
    void Update();
    bool WasExecuted();
    virtual ~DelayedTask();

protected:
    virtual void Execute() = 0;

private:
    bool ShouldBeExecuted();
    void Cleanup();

    class DelayedTaskTimer * timer;
};

#endif
