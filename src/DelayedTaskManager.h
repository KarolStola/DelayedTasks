#ifndef DELAYED_TASK_MANAGER_H
#define DELAYED_TASK_MANAGER_H

#include <vector>
#include "DelayedTask.h"

class DelayedTaskManager
{
public:
    void AddDelayedTask(DelayedTask * newTask);
    void Update();
    static DelayedTaskManager & Get();

private:
    typedef std::vector<DelayedTask *> Tasks;

    void UpdateTimes();
    void UpdateTaskIterator(Tasks::iterator & taskIterator);

    unsigned long currentTime = 0;
    unsigned long deltaTime = 0;
    bool isBeingUpdated = false;
    Tasks tasks;
    Tasks tasksToAdd;

    static DelayedTaskManager delayedTaskManager;
};

#endif