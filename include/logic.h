#ifndef LOGIC_H
#define LOGIC_H

#include "types.h"

__sil_uint8_t int_len(int num) {
    if (num == 0) return 1;
    if (num < 0) num = -num;
    uint8_t l = 0;
    for (; num > 0; num /= 10, l++);
    return l;
}

__sil_size_t string_len(const char* str) { for (size_t i = 0;; i++) if (str[i] == '\0') return i; }

__sil_uint8_t str_equals(const char* str1, const char* str2) {
    size_t i = 0;
    while (str1[i] == str2[i] && str1[i] != '\0') i++;
    return str1[i] == str2[i];
}

#endif