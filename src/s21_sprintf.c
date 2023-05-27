#include "s21_string.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sellect_arg(char* buf,int *index, va_list argptr, char mas_format) {
    switch (mas_format) {
        case 'd':
            buf[(*index)++] = va_arg(argptr, int);
            break;
        case 'c':
            buf[(*index)++] = va_arg(argptr, int);
            break;
        case 's':
            char* str1 = va_arg(argptr,  char*);
            buf = strcat(buf,str1);
            (*index) +=strlen(str1);
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
    char mas_format[100];
    va_list argptr;
    va_start(argptr, format);
    int k=0;
    int index = 0;

    for(int i=0; format[i] != '\0'; i++)
        if(format[i] != '%')
            mas_format[k++] = format[i];

    int mas_format_len = strlen(mas_format);
    for(int i=1; i<=mas_format_len; i++) {
        if(mas_format[i-1] == '%')
        sellect_arg(buf,&index, argptr, mas_format[i]);
        else
        buf[(index)++] = mas_format[i];
    }
    va_end(argptr);
    return 0;
}