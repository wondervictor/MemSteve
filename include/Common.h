//
// Created by VicChan on 2017/6/9.
//

#ifndef MEMSTEVE_COMMON_H
#define MEMSTEVE_COMMON_H

// unit: u seconds
typedef unsigned int timeInterval;

// start the timer
void startTimer();

// stop the timer and get the duration
void stopTimer(timeInterval& duration);

#endif //MEMSTEVE_COMMON_H
