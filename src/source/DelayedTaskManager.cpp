
#include <Arduino.h>
#include "DelayedTaskManager.h"
#include "DelayedTask.h"

DelayedTaskManager DelayedTaskManager::delayedTaskManager;

void DelayedTaskManager::AddDelayedTask(DelayedTask * newTask)
{
    if(isBeingUpdated)
    {
        tasksToAdd.push_back(newTask);
    }
    else
    {
        tasks.push_back(newTask);
    }
    
}

void DelayedTaskManager::Update()
{
    isBeingUpdated = true;
    
    UpdateTimes();

    for(auto taskIterator = tasks.begin(); taskIterator != tasks.end(); )
    {
        UpdateTaskIterator(taskIterator);
    }

    isBeingUpdated = false;

    for (auto & task : tasksToAdd)
    {
        AddDelayedTask(task);
    }
    
    tasksToAdd.clear();
}

void DelayedTaskManager::UpdateTimes()
{
    auto newTime = millis();
    deltaTime = newTime - currentTime;
    currentTime = newTime;
}


void DelayedTaskManager::UpdateTaskIterator(Tasks::iterator & taskIterator)
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

DelayedTaskManager & DelayedTaskManager::Get()
{
    return delayedTaskManager;
}
