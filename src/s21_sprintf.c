#include "s21_string.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
} 

void sellect_arg(char* buf,int *index, va_list argptr, char format) {
    
    switch (format) {
        case 'd':
            char str1[20];
            itoa(va_arg(argptr, int), str1);
            buf = strcat(buf,str1);
            (*index) +=strlen(str1);
            break;
        case 'c':
            buf[(*index)++] = va_arg(argptr, int);
            break;
        case 's':
            char* str2 = va_arg(argptr,  char*);
            buf = strcat(buf,str2);
            (*index) +=strlen(str2);
            break;
        default:
            // char out[512] = "grep: ";
            // strcat(out, optarg);
            // perror(out);
            break;
    }
}
// c, d, i, e, E, f, g, G, o, s, u, x, X, p, n, %
// 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0

int s21_sprintf(char* buf, char* format, ...)
{
    va_list argptr;
    va_start(argptr, format);
    int index = 0;
    buf[0] = '\0';
    int format_len = strlen(format);
    for(int i=0; i<format_len; i++) {
        if(format[i] == '%')
        sellect_arg(buf,&index, argptr, format[++i]);
        else
        buf[(index)++] = format[i];
    }
    va_end(argptr);
    return 0;
}