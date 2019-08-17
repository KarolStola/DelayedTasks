
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
    
    for(auto taskIterator = tasks.begin(); taskIterator < tasks.end(); )
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

void DelayedTaskManager::UpdateTaskIterator(Tasks::iterator & taskIterator)
{
    auto & task = *taskIterator;
    task->Update();

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

int DelayedTaskManager::GetTaskCount()
{
    return tasks.size() + tasksToAdd.size();
}

DelayedTaskManager::~DelayedTaskManager()
{
    for (auto & task : tasks)
    {
        delete(task);
    }

    for (auto & task : tasksToAdd)
    {
        delete(task);
    }
}