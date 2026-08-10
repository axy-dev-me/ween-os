#ifndef LOGIC_H
#define LOGIC_H

static inline int str_equals(char* str1, char* str2) {
    int i = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) return 0; i++;
    }
    return 1;
}

static inline int int_len(int num) {
    if (num == 0) return 1;
    if (num < 0) num = -num;
    short len = 0;
    while (num > 0) {
        len++;
        num /= 10;
    }
    return len;
}

#endif