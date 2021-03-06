#ifndef DEFS_HPP
#define DEFS_HPP

#include <stdlib.h>
#include <iostream>
#include <sys/time.h>

// function that gets the current time
double ClockGetTime()
{
    timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return (double)ts.tv_sec + (double)ts.tv_nsec / 1000000000;
}


#endif /* Standard defines */
