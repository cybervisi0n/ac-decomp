#ifndef SPRINTF_H
#define SPRINTF_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef GAMECUBE
int sprintf(char* dst, const char* fmt, ...);
#endif

#ifdef __cplusplus
}
#endif

#endif