#ifndef MALLOC_H
#define MALLOC_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

extern void* malloc(size_t size);
extern void free(void* ptr);

#ifdef PCPORT
void* animalcrossing_malloc(size_t size);
void animalcrossing_free(void* ptr);
#endif

extern void MallocInit(void* base, size_t len);
extern void MallocCleanup();
extern int  MallocIsInitalized();
extern void GetFreeArena(size_t* max_size, size_t* free_size, size_t* alloc_size);
extern int CheckArena(); /* @unused */
extern void DisplayArena();

#ifdef PCPORT
#define malloc(_size) animalcrossing_malloc(_size)
#define free(_ptr) animalcrossing_free(_ptr)
#endif

#ifdef __cplusplus
}
#endif

#endif
