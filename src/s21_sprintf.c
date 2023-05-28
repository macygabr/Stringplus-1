#include "s21_string.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* itoa:  convert n to characters in s */
void itoa(int n, char s[])
{
    int i, j, sign;
    char c;
    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    int sLen = strlen(s)-1;
    for (i = 0, j = sLen; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
} 

void sellect_arg(char* buf,int *index, va_list argptr, char mas_format) {
    switch (mas_format) {
        case 'd':
            // buf[(*index)++] = va_arg(argptr, int);
            char str1[20];
            itoa(va_arg(argptr, int), str1);
            buf = strcat(buf, str1);
            (*index) +=strlen(str1);
            break;
        case 'c':
            buf[(*index)++] = va_arg(argptr, int);
            break;
        case 's':
            char* str2 = va_arg(argptr,  char*);
            buf = strcat(buf, str2);
            (*index) +=strlen(str2);
            break;
        default:
            // error
            break;
    }
}
// c, d, i, e, E, f, g, G, o, s, u, x, X, p, n, %
// 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0

int s21_sprintf(char* buf, char* format, ...)
{
    buf[0] = '\0';
    va_list argptr;
    va_start(argptr, format);
    int index = 0;

    int format_len = strlen(format);
    for(int i=1; i<=format_len; i++) {
        if(format[i-1] == '%')
            sellect_arg(buf, &index, argptr, format[i]);
        else if(format[i] != '%')
            buf[(index)++] = format[i];
    }
    va_end(argptr);
    return 0;
}