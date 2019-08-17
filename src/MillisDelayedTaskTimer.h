#ifndef MILLIS_DELAYED_TASK_TIMER_H
#define MILLIS_DELAYED_TASK_TIMER_H

#include "DelayedTaskTimer.h"

class MillisDelayedTaskTimer : public DelayedTaskTimer
{
public:
    MillisDelayedTaskTimer(long timeRemainging);
    
protected:
    virtual unsigned long GetCurrentTime() override;

};

#endif
