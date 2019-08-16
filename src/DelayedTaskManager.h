#ifndef DELAYED_TASK_MANAGER_H
#define DELAYED_TASK_MANAGER_H

#include <Arduino.h>
#include "DelayedTask.h"

class DelayedTaskManager
{
public:
    void AddDelayedTask(DelayedTask *newTask);
    void Update();

private:
    void UpdateTask(DelayedTask *newTask, float deltaTime);

    unsigned long currentTime = 0;
    std::vector<DelayedTask *> tasks;
};

#endif