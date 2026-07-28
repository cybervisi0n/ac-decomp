#include "libultra/gu.h"
#ifdef GAMECUBE
#include "MSL_C/w_math.h"
#else
# include "math.h"
#endif

void guNormalize(float* x, float* y, float* z) {
    float norm = sqrtf(*x * *x + *y * *y + *z * *z);
    norm = 1.0f / norm;
    *x *= norm;
    *y *= norm;
    *z *= norm;
    // might return norm
}
