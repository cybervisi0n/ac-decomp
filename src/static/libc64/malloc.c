#include "libc64/__osMalloc.h"
#include "libc64/malloc.h"

OSArena malloc_arena;

#ifdef GAMECUBE
extern void* malloc(size_t size) {
    return __osMalloc(&malloc_arena, size);
}

extern void free(void* ptr) {
    __osFree(&malloc_arena, ptr);
}
#endif

#ifdef PCPORT
void* animalcrossing_malloc(size_t size) {
    return __osMalloc(&malloc_arena, size);
}

void animalcrossing_free(void* ptr) {
    __osFree(&malloc_arena, ptr);
}
#endif

extern void DisplayArena(void) {
    __osDisplayArena(&malloc_arena);
}

#ifdef GAMECUBE
extern void GetFreeArena(u32* max, u32* free, u32* alloc)
#else
extern void GetFreeArena(size_t* max, size_t* free, size_t* alloc)
#endif
{
    #ifdef GAMECUBE
    __osGetFreeArena(&malloc_arena, max, free, alloc);
    #else
    __osGetFreeArena(&malloc_arena, (u32*)max, (u32*)free, (u32*)alloc);
    #endif
}
#ifdef GAMECUBE
extern void MallocInit(void* start, u32 size) 
#else
extern void MallocInit(void* start, size_t size) 
#endif
{
    __osMallocInit(&malloc_arena, start, size);
}

extern void MallocCleanup(void) {
    __osMallocCleanup(&malloc_arena);
}
