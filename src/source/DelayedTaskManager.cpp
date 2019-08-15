#include <Arduino.h>
#include "DelayedTaskManager.h"

void DelayedTaskManager::AddDelayedTask(DelayedTask * newTask)
{
    task = newTask;
}

void DelayedTaskManager::Update()
{
    auto newTime = millis();
    auto deltaTime = newTime - currentTime;
    currentTime = newTime;

    task->NotifyMillisecondsPassed(deltaTime);
    if(task->ShouldBeExecuted())
    {
        task->Execute();
    }
}