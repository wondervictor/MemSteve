//
// Created by VicChan on 2017/6/9.
//

#include "../include/Common.h"
#include <time.h>
#include <sys/time.h>

static timeval start;

void startTimer() {
    gettimeofday(&start, NULL);
}

void stopTimer(timeInterval& duration) {
    timeval end;
    gettimeofday(&end, NULL);
    duration = (timeInterval)((end.tv_usec - start.tv_usec) + 1000000*(end.tv_sec-start.tv_sec));
}