#include "s21_string.h"
#include <stdio.h>

// Выполняет поиск первого вхождения указанного символа в массиве
void *s21_memchr(const void *str, int c, s21_size_t n) {
    int end = 1;
    char *ptr = (char *)str, *result = S21_NULL;
    for (s21_size_t i = 0; i < n && end == 1; i++) {
        int symbol;
        symbol = *(ptr + i);
        if (symbol == c) {
            end = 0;
            result = ptr + i;
        }
    }
    return result;
}

// Сравнивает первые n байтов двух массивов
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
        int result = 0;
        unsigned char *string1 = (unsigned char *)str1;
        unsigned char *string2 = (unsigned char *)str2;
        for (s21_size_t i = 0; i < n; i++) {
            if (*string1 == *string2) {
                string1++;
                string2++;
            } else {
                result = *string1 - *string2;
                n = 0;
            }
        }
    return result;
}

// Вычисляет длину строки str, не включая завершающий нулевой символ
s21_size_t s21_strlen(const char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++)
        ;
    return i;
}

// Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest,
// длиной до n символов.
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    char *begin = dest + strlen(dest);
    char *end = dest + strlen(dest) + n - 1;
    while (*src != '\0' && begin <= end) {
        *begin++ = *src++;
    }
    *begin = '\0';
    return dest;
}

// Копирует до n символов из строки, на которую указывает src, в dest.
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

// Копирует n символов из src в dest
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    char *d = dest;
    const char *s = src;
    while (n > 0) {
        *d++ = *s++;
        n--;
    }
    return dest;
}

// Заполнение массива указанными символами
void *s21_memset(void *str, int c, s21_size_t n) {
    char *s = str;
    while(n > 0) {
        *s++ = c;
        n--;
    }
    return str;
}

// Сравнивает не более первых n байтов str1 и str2
int s21_strncmp(const char *str1, const char *str2, s21_size_t n)  {
    int result = 0;
    for (s21_size_t i = 0; i < n; i++)
    {
        if (str1[i] != str2[i]) {
        (str1[i] < str2[i]) ? result = -1 : result = 1;
        }
    }
    return result;
}

// Находит первый символ в строке str1, который соответствует любому символу, указанному в str2.
char *s21_strbrk(const char *str1, const char *str2)  {
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

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке,
// на которую указывает аргумент str.
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

// Выполняет поиск последнего вхождения символа c (беззнаковый тип)
// в строке, на которую указывает аргумент str.
char *s21_strrchr(const char *str, int c)  {
    char *result = S21_NULL;
     for(;*str != '\0'; str++) {
        if (*str == c) {
            result = (char*)str;
        }
    }
    return result;
}

// Находит первое вхождение всей строки needle (не включая завершающий нулевой символ),
// которая появляется в строке haystack.
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

// Разбивает строку str на ряд токенов, разделенных delim.
char *s21_strtok(char* str, const char* delim) {
    static char *last = NULL;
    if (str != NULL) {
        last = str; 
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
    return (result[0] == '\0') ? NULL : result;
}

// Вычисляет длину начального сегмента str1, который полностью состоит из символов, не входящих в str2.
s21_size_t s21_strcspn(const char *str1, const char *str2) {
    int result = s21_strlen(str1);
    if(s21_strpbrk(str1,str2) != S21_NULL) {
        result = s21_strpbrk(str1,str2) - str1;
    }
    return result;
}

// Выполняет поиск во внутреннем массиве номера ошибки errnum и
// возвращает указатель на строку с сообщением об ошибке.
// Нужно объявить макросы, содержащие массивы сообщений об ошибке
// для операционных систем mac и linux.
// Описания ошибок есть в оригинальной библиотеке.
// Проверка текущей ОС осуществляется с помощью директив.
char *s21_strerror(int errnum) {
    #define MAX_NUM_ERR 107
    static const char *Error_[MAX_NUM_ERR] = {
        "Undefined error: 0",
        "Operation not permitted",
        "No such file or directory",
        "No such process",
        "Interrupted system call",
        "Input/output error",
        "Device not configured",
        "Argument list too long",
        "Exec format error",
        "Bad file descriptor",
        "No child processes",
        "Resource deadlock avoided",
        "Cannot allocate memory",
        "Permission denied",
        "Bad address",
        "Block device required",
        "Resource busy",
        "File exists",
        "Cross-device link",
        "Operation not supported by device",
        "Not a directory",
        "Is a directory",
        "Invalid argument",
        "Too many open files in system",
        "Too many open files",
        "Inappropriate ioctl for device",
        "Text file busy",
        "File too large",
        "No space left on device",
        "Illegal seek",
        "Read-only file system",
        "Too many links",
        "Broken pipe",
        "Numerical argument out of domain",
        "Result too large",
        "Resource temporarily unavailable",
        "Operation now in progress",
        "Operation already in progress",
        "Socket operation on non-socket",
        "Destination address required",
        "Message too long",
        "Protocol wrong type for socket",
        "Protocol not available",
        "Protocol not supported",
        "Socket type not supported",
        "Operation not supported",
        "Protocol family not supported",
        "Address family not supported by protocol family",
        "Address already in use",
        "Can't assign requested address",
        "Network is down",
        "Network is unreachable",
        "Network dropped connection on reset",
        "Software caused connection abort",
        "Connection reset by peer",
        "No buffer space available",
        "Socket is already connected",
        "Socket is not connected",
        "Can't send after socket shutdown",
        "Too many references: can't splice",
        "Operation timed out",
        "Connection refused",
        "Too many levels of symbolic links",
        "File name too long",
        "Host is down",
        "No route to host",
        "Directory not empty",
        "Too many processes",
        "Too many users",
        "Disc quota exceeded",
        "Stale NFS file handle",
        "Too many levels of remote in path",
        "RPC struct is bad",
        "RPC version wrong",
        "RPC prog. not avail",
        "Program version wrong",
        "Bad procedure for program",
        "No locks available",
        "Function not implemented",
        "Inappropriate file type or format",
        "Authentication error",
        "Need authenticator",
        "Device power is off",
        "Device error",
        "Value too large to be stored in data type",
        "Bad executable (or shared library)",
        "Bad CPU type in executable",
        "Shared library version mismatch",
        "Malformed Mach-o file",
        "Operation canceled",
        "Identifier removed",
        "No message of desired type",
        "Illegal byte sequence",
        "Attribute not found",
        "Bad message",
        "EMULTIHOP (Reserved)",
        "No message available on STREAM",
        "ENOLINK (Reserved)",
        "No STREAM resources",
        "Not a STREAM",
        "Protocol error",
        "STREAM ioctl timeout",
        "Operation not supported on socket",
        "Policy not found",
        "State not recoverable",
        "Previous owner died",
        "Interface output queue is full"
    };
    if (errnum < 0 || errnum >= MAX_NUM_ERR) {
        char d[256];
        s21_itoa(errnum, d);
        char f[256] = "Unknown error: ";
        s21_strcat(f, d);
        Error_[errnum] = f;
    }
    return (char *)Error_[errnum];
}

void s21_itoa(int a, char s[]) {
    int i = 0;
    int sign = a;

    if (sign < 0) {
        a = -a;
    }
    i = 0;

    do {
        s[i++] = a % 10 + '0';
    } while ((a /= 10) > 0);
    if (sign < 0) {
        s[i] = '-';
        s[i + 1] = '\0';
    } else {
        s[i] = '\0';
    }
    s21_reverse(s);
}

void s21_reverse(char *s) {
    int i, j;
    for (i  = 0, j = s21_strlen(s) - 1; i < j; i++, j--) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

// Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest.
char *s21_strcat(char *dest, const char *src) {
    char *destmem = dest;
    while (*dest != 0) dest++;
    while (*src != 0) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = *src;
    return destmem;
}
