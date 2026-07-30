#include "libc64/sleep.h"
#include "libultra/os_timer.h"
#include "dolphin/os/OSAlarm.h"
#include "dolphin/os/OSTimer.h"
#include "dolphin/os/OSThread.h"

void csleep(OSTime c) {
    OSMessage msg;
    OSMessageQueue mq;
    OSTimer timer;

    #ifdef GAMECUBE
    //TODO
    osCreateMesgQueue(&mq, &msg, 1);
    osSetTimer(&timer, c, 0, &mq, NULL);
    osRecvMesg(&mq, NULL, 1);
    #endif
}

void msleep(u32 ms) {
    csleep(OSMillisecondsToTicks((u64)ms));
}
