#ifndef MATH_H
#define MATH_H

#include "types.h"

__sil_uint32_t pow(int n1, int n2) {
    if (n2 == 0) return 1;
    uint32_t r = n1;
    for (uint32_t i = n2; i != 1; i--) r *= n1;
    return r;
}

__sil_int abs(int num) { return (num < 0) ? -num : num; }
__sil_int min(int a, int b) { return (a < b) ? a : b; }
__sil_int max(int a, int b) { return (a > b) ? a : b; }

#endif