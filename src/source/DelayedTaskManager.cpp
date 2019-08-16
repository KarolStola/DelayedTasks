
#include "DelayedTaskManager.h"

void DelayedTaskManager::AddDelayedTask(DelayedTask *newTask)
{
    tasks.push_back(newTask);
}

void DelayedTaskManager::Update()
{
    auto newTime = millis();
    auto deltaTime = newTime - currentTime;
    currentTime = newTime;

    for(auto taskIterator = tasks.begin(); taskIterator != tasks.end(); )
    {
        auto & task = *taskIterator;
        task->Update(deltaTime);

        if(task->WasExecuted())
        {
            delete(task);
            tasks.erase(taskIterator);
        }
        else
        {
            taskIterator++;
        }
    }
}
