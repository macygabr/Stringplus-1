#include <stdio.h>
#include <stdlib.h>

size_t strlen(const char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++)
        ;
    return i;
}

int memcmp(const void *str1, const void *str2, size_t n) {
    const unsigned char *p1 = str1;
    const unsigned char *p2 = str2;

    for (size_t i = 0; i < n; i++)
    {
        if (*p1 != *p2) {
            return 1;
        }
        ++str1;
        ++str2;
    }
    return 0;
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
// char *s21_strchr(const char *str, char *n) {
//     while (*str != '\0') {
//         if (*str == *n) {
//             return (char*)str;
//         }
//         str++;
//     }
//     if (*str == *n) {
//         return (char*)str;
//     }
//     return NULL;
// }


char *strtok(char *str, const char *delim) {
    char *pDelim = delim;
    static char *endStr = NULL;
    char *curentStr = NULL;
    if (str != NULL) {
        endStr = str;
    }
    if (endStr == NULL) {
        return NULL;
    }
    
    for (pDelim = delim; *pDelim != '\0'; pDelim++) {
        for (;*endStr != '\0'; endStr++) {
          if (*endStr == *pDelim) {
            *endStr = '\0';
            curentStr = str + *endStr;
            return curentStr;
          }
        }
    }
    endStr = NULL;
    return NULL;
}

char *s21_strcpy(char *destination, const char *source) {
    while (*source != '\0' || *destination != '\0') {
        *destination = *source;
        ++destination;
        ++source;
    }
    return 0;
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
        const char *separator = str2;
        for(;*separator != '\0'; separator++) {
            if(*s1 == *separator) {
                return (char*)s1;
            }
        }
    }
    return NULL;
}

char *strchr(const char *str, int c)  {
     for(;*str != '\0'; str++) {
        if (*str == c) {
            return (char*)str;
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



char *strstr(const char *haystack, const char *needle) {
    size_t s1 = strlen(haystack);
    size_t separator = strlen(needle);
    if (separator > s1 || separator == 0) {
        return NULL;
    }
    for (size_t i = 0; i <= s1 - separator; i++) {
        if (strncmp(haystack + i, needle, separator) == 0) {
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
    size_t s1 = strlen(str1);
    size_t s2 = strlen(str2);
    int counter = 0;
    int result = 0;

    for (size_t i = 0; i <= s1; i++) {
        counter = 0;
        for(size_t j = 0; j <=s2; j++) {
            if((str1 + i) == (str2 + j)) {
                continue;
            }

        }
        counter++;
        if(counter > result) {
            result = counter;
        }
        if(counter == s1) {
            return result;
        }
    }
}

size_t strcspn(const char *str1, const char *str2) {
    int result = strlen(str1);
    if(strpbrk(str1,str2) != NULL) {
        result = strpbrk(str1,str2) - str1;
    }
    return result;
}