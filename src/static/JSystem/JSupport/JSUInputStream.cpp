#include "JSystem/JSupport/JSUStream.h"

#ifndef GAMECUBE
#define EOF JEOF
#endif

JSUInputStream::~JSUInputStream() {
}

int JSUInputStream::read(void* buf, s32 size) {
    int len = this->readData(buf, size);
    if (len != size) {
        this->setState(EOF);
    }
    return len;
}

char* JSUInputStream::read(char* str) {
    u16 size;
    int len = this->readData(&size, sizeof(size));
    if (len != sizeof(size)) {
        str[0] = '\0';
        this->setState(EOF);
        str = nullptr;
    } else {
        int strRead = this->readData(str, size);
        str[strRead] = '\0';
        if (strRead != size) {
            this->setState(EOF);
        }
    }

    return str;
}

/* @fabricated -- this method is confirmed to exist, but goes unused in AC */
char* JSUInputStream::readString() {
    u16 len;
    int r = this->readData(&len, sizeof(len));
    if (r != sizeof(len)) {
        this->setState(EOF);
        return nullptr;
    }

    char* buf = new char[len + 1];
    r = this->readData(buf, len);
    if (r != len) {
        delete[] buf;
        this->setState(EOF);
        return nullptr;
    }

    buf[len] = '\0';
    return buf;
}

/* @fabricated -- this method is confirmed to exist, but goes unused in AC */
char* JSUInputStream::readString(char* buf, u16 len) {
    int r = this->readData(buf, len);
    if (r != len) {
        this->setState(EOF);
        return nullptr;
    }

    buf[len] = '\0';
    return buf;
}

int JSUInputStream::skip(s32 amount) {
    u8 _p;
    int i;

    for (i = 0; i < amount; i++) {
        if (this->readData(&_p, sizeof(_p)) != sizeof(_p)) {
            this->setState(EOF);
            break;
        }
    }

    return i;
}

/* JSURandomInputStream */

int JSURandomInputStream::skip(s32 amount) {
    #ifdef GAMECUBE
    int s = this->seekPos(amount, SEEK_CUR);
    #else
    int s = this->seekPos(amount, JSEEK_CUR);
    #endif
    if (s != amount) {
        this->setState(EOF);
    }
    return s;
}

/* This method is confirmed to exist, but goes unused in AC. Retrieved from TP debug. */
int JSURandomInputStream::align(s32 alignment) {
    int pos = this->getPosition();
    int aligned = ((alignment - 1) + pos) & ~(alignment - 1);
    int change = aligned - pos;

    if (change != 0) {
        #ifdef GAMECUBE
        int s = this->seekPos(aligned, SEEK_SET);
        #else
        int s = this->seekPos(aligned, JSEEK_SET);
        #endif
        if (s != change) {
            this->setState(EOF);
        }
    }

    return change;
}

/* This method is confirmed to exist, but goes unused in AC. Retrieved from TP debug. */
int JSURandomInputStream::peek(void* buf, s32 len) {
    int pos = this->getPosition();
    int r = this->read(buf, len);
    if (r != 0) {
        #ifdef GAMECUBE
        this->seekPos(pos, SEEK_SET);
        #else
        this->seekPos(pos, JSEEK_SET);
        #endif
    }

    return r;
}

int JSURandomInputStream::seek(s32 offset, JSUStreamSeekFrom from) {
    int s = this->seekPos(offset, from);
    this->clrState(EOF);
    return s;
}
