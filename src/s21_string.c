#include "s21_string.h"
#include <stdio.h>

void *s21_memchr(const void *str, int c, s21_size_t n) {
    const char *str_big = (const char *)str;
    s21_size_t lenght;
    for (lenght = 0; lenght < n; lenght++) {
        if (str_big[lenght] == c) {
            return (void *)&str_big[lenght];
        }
    }
    return S21_NULL;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    const unsigned char *s1 = str1;
    const unsigned char *s2 = str2;

    for (s21_size_t i = 0; i < n; i++)
    {
        if (*s1 != *s2) {
            return (*s1 < *s2 ? -1 : 1);
        }
        ++str1;
        ++str2;
    }
    return 0;
}

s21_size_t s21_strlen(const char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++)
        ;
    return i;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    char *begin = dest + strlen(dest);
    char *end = dest + strlen(dest) + n - 1;
    while (*src != '\0' && begin <= end) {
        *begin++ = *src++;
    }
    *begin = '\0';
    return dest;
}


char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    s21_size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    if (i < n) {
        dest[i] = '\0';
    }
    return dest;
}


void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    char *d = dest;
    const char *s = src;
    while (n > 0) {
        *d++ = *s++;
        n--;
    }
    return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
    char *s = str;
    while(n > 0) {
        *s++ = c;
        n--;
    }
    return str;
}


int *s21_strncmp(const char *str1, const char *str2, s21_size_t n)  {
    int result = 0;
    for (s21_size_t i = 0; i < n; i++)
    {
        if (str1[i] != str2[i]) {
        (str1[i] < str2[i]) ? result = -1 : result = 1;
        }
    }
    return result;
}

char *s21_strpbrk(const char *str1, const char *str2)  {
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

char *max(const char *str1, const char *str2)  {
   char*result = NULL;
    const char *s1 = str1 + strlen(str1);
    for(;*s1 != *str1; s1--) {
        const char *s2 = str2 + strlen(str2);
        for(;*s2 != *str2; s2--) {
            if(*s1 == *s2) {
                result = (char*)s1;
            }
        }
    }
    return result;
}


char *s21_strchr(const char *str, int c) {
    char *result = S21_NULL;
    const char *endStr = str + s21_strlen(str);
     for(;*endStr != *str; endStr--) {
        if (*endStr == c) {
            result = (char*)endStr;
        }
    }
    return result;
}

char *s21_strrchr(const char *str, int c)  {
    char *result = S21_NULL;
     for(;*str != '\0'; str++) {
        if (*str == c) {
            result = (char*)str;
        }
    }
    return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
    s21_size_t s1 = strlen(haystack);
    s21_size_t s2 = strlen(needle);
    char *result = S21_NULL;
    s21_size_t i = 0;
    while((!strncmp(haystack + i, needle, s2) == 0) && (i <= s1 - s2)) {
        ++i;
        result = (char*)haystack + i;
    }
    return result;
}

char *s21_strtok(char* str, const char* delim) {
    static char *last = S21_NULL;
    if (str != S21_NULL) {
        last = str; 
    }
    if (last == S21_NULL) { 
        return S21_NULL;
    }
    char *result = last; 
    char *separator;
    for(; *last != '\0'; last++) {
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
        return S21_NULL;
    }
     else { 
        return result;
    }
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    int result = s21_strlen(str1);
    if(s21_strpbrk(str1,str2) != S21_NULL) {
        result = s21_strpbrk(str1,str2) - str1;
    }
    return result;
}