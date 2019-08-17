#ifndef DELAYED_TASK_MANAGER_H
#define DELAYED_TASK_MANAGER_H

#include <vector>
#include "DelayedTask.h"

class DelayedTaskManager
{
public:
    void AddDelayedTask(DelayedTask * newTask);
    int GetTaskCount();
    void Update();
    static DelayedTaskManager & Get();
    virtual ~DelayedTaskManager();

private:
    typedef std::vector<DelayedTask *> Tasks;

    void UpdateTaskIterator(Tasks::iterator & taskIterator);

    bool isBeingUpdated = false;
    Tasks tasks;
    Tasks tasksToAdd;

    static DelayedTaskManager delayedTaskManager;
};

#endif