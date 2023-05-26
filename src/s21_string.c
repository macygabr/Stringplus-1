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
// int memcmp(const void *str1, const void *str2, size_t n) {
//     const unsigned char *p1 = str1;
//     const unsigned char *p2 = str2;

//     for (size_t i = 0; i < n; i++)
//     {
//         if (*p1 != *p2) {
//             return (*p1 < *p2 ? -1 : 1);
//         }
//         ++str1;
//         ++str2;
//     }
//     return 0;
// }


// Реализовать возврат 3 значений (-1, 0, 1)

// char *strchr(const char *str, int c) {
   
//     int i = 0;
//     while (str[i] && str[i] != c) ++i;
//     return c == str[i] ? (char*)str + i : NULL;

// }


size_t strlen(const char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++)
        ;
    return i;
}

char *strncat(char *dest, const char *src, size_t n) {
    if (n == 0) {
        return dest;
    }
    char *begin = dest + strlen(dest);
    char *end = dest + strlen(dest) + n - 1;
    while (*src != '\0' && begin <= end) {
        *begin++ = *src++;
    }
    *begin = '\0';
    return dest;
}

char *strncpy(char *dest, const char *src, size_t n) {
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    if (i < n) {
        dest[i] = '\0';
    }
    return dest;
}

void *memcpy(void *dest, const void *src, size_t n) {
    char *d = dest;
    const char *s = src;
    while (n > 0) {
        *d++ = *s++;
        n--;
    }
    return dest;
}

void *memset(void *str, int c, size_t n) {
    char *s = str;
    while(n > 0) {
        *s++ = c;
        n--;
    }
    return str;
}

int strncmp(const char *str1, const char *str2, size_t n)  {

    for (size_t i = 0; i < n; i++)
    {
        if (str1[i] != str2[i]) {
            return (str1[i] < str2[i] ? -1 : 1);
        }
    }
    return 0;
}

char *strpbrk(const char *str1, const char *str2)  {
    if (str1 == NULL || str1 == NULL) {
        return NULL;
    }
    const char *s1 = str1;
    for(;*s1 != '\0'; s1++) {
        const char *s2 = str2;
        for(;*s2 != '\0'; s2++) {
            if(*s1 == *s2) {
                return (char*)s1;
            }
        }
    }
    return NULL;
}

char *strrchr(const char *str, int c) {
    const char *endStr = str + strlen(str);
     for(;*endStr != *str; endStr--) {
        if (*endStr == c) {
            return (char*)endStr;
        }
    }
    return NULL;
}