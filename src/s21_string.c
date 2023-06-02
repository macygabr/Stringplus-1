#include "s21_string.h"
#include <stdio.h>

void *memchr(const void *str, int c, s21_size_t n) {
    const char *str_big = (const char *)str;
    s21_size_t lenght;
    for (lenght = 0; lenght < n; lenght++) {
        if (str_big[lenght] == c) {
            return (void *)&str_big[lenght];
        }
    }
    return S21_S21_NULL;
}

int memcmp(const void *str1, const void *str2, s21_size_t n) {
    const unsigned char *p1 = str1;
    const unsigned char *p2 = str2;

    for (s21_size_t i = 0; i < n; i++)
    {
        if (*p1 != *p2) {
            return (*p1 < *p2 ? -1 : 1);
        }
        ++str1;
        ++str2;
    const unsigned char *p1 = str1;
    const unsigned char *p2 = str2;

    for (s21_size_t i = 0; i < n; i++)
    {
        if (*p1 != *p2) {
            return (*p1 < *p2 ? -1 : 1);
        }
        ++str1;
        ++str2;
    }
    return 0;
    return 0;
}
}

s21_size_t strlen(const char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++)
        ;
    return i;
}

char *strncat(char *dest, const char *src, s21_size_t n) {
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


char *strncpy(char *dest, const char *src, s21_size_t n) {
    s21_size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    if (i < n) {
        dest[i] = '\0';
    }
    return dest;
}


void *memcpy(void *dest, const void *src, s21_size_t n) {
    char *d = dest;
    const char *s = src;
    while (n > 0) {
        *d++ = *s++;
        n--;
    }
    return dest;
}

void *memset(void *str, int c, s21_size_t n) {
    char *s = str;
    while(n > 0) {
        *s++ = c;
        n--;
    }
    return str;
}


int strncmp(const char *str1, const char *str2, s21_size_t n)  {

    for (s21_size_t i = 0; i < n; i++)
    for (s21_size_t i = 0; i < n; i++)
    {
        if (str1[i] != str2[i]) {
            return (str1[i] < str2[i] ? -1 : 1);
        }
    }
    return 0;
}

char *strpbrk(const char *str1, const char *str2)  {
    if (str1 == S21_NULL || str1 == S21_NULL) {
        return S21_NULL;
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
    return S21_NULL;
}

char *strrchr(const char *str, int c) {
    const char *endStr = str + strlen(str);
     for(;*endStr != *str; endStr--) {
        if (*endStr == c) {
            return (char*)endStr;
        }
    }
    return S21_NULL;
}

char *strchr(const char *str, int c)  {
     for(;*str != '\0'; str++) {
        if (*str == c) {
            return (char*)str;
        }
    }
    return NULL;
}

char *strstr(const char *haystack, const char *needle) {
    size_t s1 = strlen(haystack);
    size_t s2 = strlen(needle);
    if (s2 > s1 || s2 == 0) {
        return NULL;
    }
    for (size_t i = 0; i <= s1 - s2; i++) {
        if (strncmp(haystack + i, needle, s2) == 0) {
            return (char*)haystack + i;
        }
    }
    return NULL;
}

char *strtok(char* str, const char* delim) {
    static char *last = NULL;
    if (str != NULL) {
        last = str; 
    }
    if (last == NULL) { 
        return NULL;
    }
    char* result = last; 
    char* separator;
    for(;*last != '\0'; last++) {
        separator = (char*)delim;
        for(; *separator != '\0'; separator++) {
            if(*last == *separator) {
                *last = '\0';
                last++;
                if (result[0] != '\0') {
                    return result;
                }
                else {
                    result = last;
                    break;
                }
            }
        }
    }
    if (result[0] == '\0') {
        return NULL;
    }
     else { 
        return result;
    }
}

size_t strcspn(const char *str1, const char *str2) {
    int result = strlen(str1);
    if(strpbrk(str1,str2) != NULL) {
        result = strpbrk(str1,str2) - str1;
    }
    return result;
}