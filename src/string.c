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

// char *s21_strcpy(char *destination, const char *source) {
//     while (*source != '\0' || *destination != '\0') {
//         *destination = *source;
//         ++destination;
//         ++source;
//     }
//     return 0;
// }

char *s21_strcat(char *str1, char *str2) {
    char *p = str1 + strlen(str1);
    while (*str2 != '\0') {
        *p++ = *str2++;
    }
    *p = '\0';
    return str1;
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

// char *strtok(char *str, const char *delim) {
//     const char *str1 = NULL;
//     if (str != NULL) {
//         str1 = str;
//         for (int i = 0; delim[i] != '\0'; i++) {
//             for (int j = 0; str1[j] != '\0'; j++) {
//               if (str1[j] == delim[i]) {
//                 printf("'\0'");
//                 j++;
//               }
//               printf("%c", str1[j]);
//             }
//         }
//     }
// }


char *strtok(char *str, const char *delim) {
    char *pDelim = delim;
    static char *endStr = NULL;
    char *curentStr = NULL;
    str != NULL ? endStr = str : NULL;
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

// char *strtok(char *str, const char *delim) {
//     static char *lastToken = NULL; // указатель на последний токен
//     char *token = NULL; // указатель на текущий токен
//     const char *delimPtr = delim; // указатель на текущий разделитель
//     if (str != NULL) {
//         lastToken = str; // начинаем с начала строки
//     }
//     if (lastToken == NULL) {
//         return NULL; // уже все токены разобрали
//     }
//     while (*lastToken != '\0') {
//         delimPtr = delim; // начинаем с начала разделителей
//         while (*delimPtr != '\0') {
//             if (*lastToken == *delimPtr) {
//                 // найден разделитель, заменяем его на нулевой символ
//                 *lastToken = '\0';
//                 token = lastToken - strlen(str); // указатель на текущий токен
//                 lastToken++; // сдвигаем указатель на следующий символ
//                 return token;
//             }
//             delimPtr++;
//         }
//         lastToken++; // продолжаем искать разделитель
//     }
//     // все токены разобрали, возвращаем NULL
//     lastToken = NULL;
//     return NULL;
// }