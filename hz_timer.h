/**
 * HZ Timer
 * Make sure a code segment is executed under a specified Hertz rate
 * 
 * Author: Chester Abrahams
 * GitHub: https://github.com/ChesterOfTheSemester/hz_timer.h
 */

#ifndef HZ_TIMER
#define HZ_TIMER

#include <sys/time.h>
#include <stdlib.h>

struct
{
    struct      timeval  tp;
    unsigned    stack[0xFF],
                stack_lapsed[0xFF];

    unsigned getMS() {
        gettimeofday(&tp, NULL);
        return tp.tv_sec * 1000 + tp.tv_usec / 1000;
    }

    bool test(unsigned hz, unsigned uuid=0, unsigned timespan=1000)
    {
        unsigned ms = getMS();
        stack[uuid] = ms - stack_lapsed[uuid];

        if (stack[uuid] > timespan/hz) {
            stack_lapsed[uuid] = ms - (stack[uuid] % (timespan/hz));
            return true;
        }

        return false;
    }
} timer;

#endif
