#include "jaudio_NES/os.h"
#include "dolphin/os.h"
#include "jaudio_NES/dummyrom.h"
#include "jaudio_NES/sample.h"
#ifdef PCPORT
#include <SDL2/SDL_mutex.h>
#endif

extern void Z_osWritebackDCacheAll() {
}

extern void osInvalDCache2(void* src, s32 size) {
    DCInvalidateRange(src, size);
}

extern void osWritebackDCache2(void* src, s32 size) {
    DCStoreRange(src, size);
}

extern void Z_osCreateMesgQueue(OSMesgQueue* mq, OSMesg* msg, s32 count) {
    mq->msg = msg;
    mq->msgCount = count;
    mq->validCount = 0;
    mq->first = 0;
    #ifdef PCPORT
    mq->sdlSemaphore = SDL_CreateSemaphore(0);
    mq->sdlMutex = SDL_CreateMutex();
    #endif
}

extern s32 Z_osSendMesg(OSMesgQueue* mq, OSMesg msg, s32 flags) {
    #ifdef PCPORT
    SDL_LockMutex((SDL_mutex*)mq->sdlMutex);
    #endif
    int msgCount = mq->msgCount;
    if (mq->validCount == mq->msgCount) {
        #ifdef PCPORT
        SDL_UnlockMutex((SDL_mutex*)mq->sdlMutex);
        #endif
        return -1;
    }

    int count = mq->first + mq->validCount;

    if (count >= mq->msgCount) {
        count -= mq->msgCount;
    }

    mq->msg[count] = msg;

    mq->validCount++;

    #ifdef PCPORT
    SDL_UnlockMutex((SDL_mutex*)mq->sdlMutex);
    SDL_SemPost((SDL_sem*)mq->sdlSemaphore);
    #endif

    return 0;
}

extern s32 Z_osRecvMesg(OSMesgQueue* mq, OSMesg* msg, s32 flags) {
    if (flags == OS_MESG_BLOCK) {
        #ifdef PCPORT
        SDL_SemWait((SDL_sem*)mq->sdlSemaphore);
        #else
        while (!mq->validCount) {};
        #endif
    }

    #ifdef PCPORT
    SDL_LockMutex((SDL_mutex*)mq->sdlMutex);
    #endif
    if (mq->validCount == 0) {
        if (msg != NULL) {
            *msg = NULL;
        }
        #ifdef PCPORT
        SDL_UnlockMutex((SDL_mutex*)mq->sdlMutex);
        #endif
        return -1;
    }

    mq->validCount -= 1;

    if (msg != NULL) {
        *msg = mq->msg[mq->first];
    }

    mq->first++;

    if (mq->first == mq->msgCount) {
        mq->first = 0;
    }

    #ifdef PCPORT
    SDL_UnlockMutex((SDL_mutex*)mq->sdlMutex);
    #endif
    return 0;
}

extern s32 Z_osEPiStartDma(OSPiHandle* handler, OSIoMesg* msg, s32 dir) {
    ARAMStartDMAmesg(1, (uintptr_t)msg->dramAddr, msg->devAddr, msg->size, 0, msg->hdr.retQueue);
    return 0;
}

void Z_bcopy(void* src, void* dst, size_t size) {
    Jac_bcopy(src, dst, size);
}
