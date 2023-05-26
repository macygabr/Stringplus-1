#include "s21_string.h"
#include <stdio.h>

void *memchr(const void *str, int c, size_t n) {
    const char *str_big = (const char *)str;
    size_t lenght;
    for (lenght = 0; lenght < n; lenght++) {
        if (str_big[lenght] == c) {
            return (void *)&str_big[lenght];
        }
    }
    return NULL;
}

int memcmp(const void *str1, const void *str2, size_t n) {
    if (n != 0) {
        unsigned char *pstr1 = str1, *pstr2 = str2;
        do {
            if (*pstr1++ != *pstr2) {
                return (*--pstr1 - *--pstr2);
            }
        } while (--n != 0);
    }
    return (0);
}
// Реализовать возврат 3 значений (-1, 0, 1)

// char *strchr(const char *str, int c) {
   
//     int i = 0;
//     while (str[i] && str[i] != c) ++i;
//     return c == str[i] ? (char*)str + i : NULL;

// }