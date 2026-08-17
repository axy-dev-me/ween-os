#include <stdint.h>
#include "logic.h"

int abs(int n) { return (n < 0) ? -n : n; }

int pow(int n, short s) { 
    int r = 1; 
    for (short i = 0; i < s; i++) r *= n;
    return r;
}

uint32_t hex_pow(uint32_t n, short s) { 
    uint32_t r = 1; 
    for (short i = 0; i < s; i++) r *= n;
    return r;
}

uint8_t int_len(int n) {
    uint8_t r = 0;
    for (int i = abs(n); i != 0; i /= 10) r++;
    return (r == 0) ? 1 : r;
}

uint8_t hex_len(uint32_t n) {
    uint8_t r = 0;
    for (uint32_t i = n; i != 0; i /= 16) r++;
    return (r == 0) ? 1 : r;
}