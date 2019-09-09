#ifndef DELAYED_MEMBER_TASK_H
#define DELAYED_MEMBER_TASK_H

#include <DelayedTask.h>

template<class Object>
class DelayedMemberTask : public DelayedTask
{
public:

    DelayedMemberTask(DelayedTaskTimeResolution timeResolution, Object * object, void (Object::*function)());
    DelayedMemberTask(int delay, DelayedTaskTimeResolution timeResolution, Object * object, void (Object::*function)());
    virtual void Execute() override;
    
private:
    Object * object = nullptr;
    void (Object::*function)() = nullptr;
};

template<class Object>
DelayedMemberTask<Object>::DelayedMemberTask(DelayedTaskTimeResolution timeResolution, Object *  object, void (Object::*function)())
    : DelayedTask(timeResolution)
    , object(object)
    , function(function)
{
}

template<class Object>
DelayedMemberTask<Object>::DelayedMemberTask(int delay, DelayedTaskTimeResolution timeResolution, Object *  object, void (Object::*function)())
    : DelayedTask(delay, timeResolution)
    , object(object)
    , function(function)
{
}

template<class Object>
void DelayedMemberTask<Object>::Execute()
{
    (object->*function)();
}

#endif