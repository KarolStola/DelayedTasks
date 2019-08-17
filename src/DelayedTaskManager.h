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
    void Clear();
    virtual ~DelayedTaskManager();

private:
    typedef std::vector<DelayedTask *> Tasks;

    void UpdateTaskIterator(Tasks::iterator & taskIterator);
    void Clear(Tasks & tasksToClear);

    bool isBeingUpdated = false;
    Tasks tasks;
    Tasks tasksToAdd;

};

#endif