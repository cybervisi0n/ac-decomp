#ifndef JSUSTREAMENUM_H
#define JSUSTREAMENUM_H

enum JSUStreamSeekFrom {
    #ifdef GAMECUBE
    SEEK_SET = 0, 
    SEEK_CUR = 1, 
    SEEK_END = 2 
    #else
    JSEEK_SET = 0,
    JSEEK_CUR = 1,
    JSEEK_END = 2,
    #endif
};

enum EIoState { 
    GOOD = 0,
    #ifdef GAMECUBE 
    EOF = 1
    #else
    JEOF = 1
    #endif
};

#endif
