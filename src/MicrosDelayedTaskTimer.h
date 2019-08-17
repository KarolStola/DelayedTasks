
#ifndef MICROS_DELAYED_TASK_TIMER_H
#define MICROS_DELAYED_TASK_TIMER_H

#include "DelayedTaskTimer.h"

class MicrosDelayedTaskTimer : public DelayedTaskTimer
{
public:
    MicrosDelayedTaskTimer(long timeRemainging);
    
protected:
    virtual unsigned long GetCurrentTime() override;
};

#endif
