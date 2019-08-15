#ifndef DELAYED_TASK_MANAGER_H
#define DELAYED_TASK_MANAGER_H

#include "DelayedTask.h"

class DelayedTaskManager
{
public:
    void AddDelayedTask(DelayedTask * newTask);
    void Update();
private:
    unsigned long currentTime = 0;
    DelayedTask* task;
};

#endif