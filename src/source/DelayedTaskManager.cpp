
#include <Arduino.h>
#include "DelayedTaskManager.h"
#include "DelayedTask.h"

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
    
    for(int i = 0; i < tasks.size(); i++)
    {
        tasks[i]->Update();
    }

    for(int i = tasks.size()-1; i >= 0; i--)
    {
        auto task = tasks[i]; 
        if(task->WasExecuted())
        {
            delete(task);
            tasks.erase(tasks.begin()+i);
        }
    }

    isBeingUpdated = false;

    for (auto & task : tasksToAdd)
    {
        AddDelayedTask(task);
    }

    tasksToAdd.clear();
}

int DelayedTaskManager::GetTaskCount()
{
    return tasks.size() + tasksToAdd.size();
}

void DelayedTaskManager::Clear()
{
    Clear(tasks);
    Clear(tasksToAdd);
}

void DelayedTaskManager::Clear(Tasks & tasksToClear)
{
    for (auto & task : tasksToClear)
    {
        delete(task);
    }

    tasksToClear.clear();
}

DelayedTaskManager::~DelayedTaskManager()
{
    Clear();
}