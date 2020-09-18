#ifndef _POSIX_MONOTONIC_CLOCK
#error No support for non-monotonic clocks!
#endif

#include <time.h>

#define ONE_BILLION   1000000000
#define ONE_BILLION_F 1000000000.f

typedef struct linux_timer_info linux_timer_info;
struct linux_timer_info {
    u64 StartTime;
    f32 LastFrame;
};

global linux_timer_info LinuxTimer;

internal b32  LinuxTimerInit(void);
internal f64  LinuxTimerGetTime(void);
internal void LinuxTimerSleep(int ms);
internal void LinuxTimerBeginFrame(void);
internal void LinuxTimerEndFrame(void);
