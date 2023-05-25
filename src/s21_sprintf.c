#include "s21_string.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int s21_sprintf(char* buf, char* format, ...)
{
    char mas_format[100];
    buf =buf;
    va_list argptr;
    va_start(argptr, format);
    int k=0;

    for(int i=0; format[i] != '\0'; i++)
        if(format[i] != '%' && format[i] != ' ')
            mas_format[k++] = format[i];

    int mas_format_len = strlen(mas_format);
    for(int i=0; i<mas_format_len; i++)
    {
        int s = va_arg(argptr, int);
        if(mas_format[i] == 'd' && (int)s == s) printf("%d", s);
        if(mas_format[i] == 'c' && (char)s==s) printf("%d", s);
        //if(mas_format[i] == 's' && s==s) printf("%d", s);
    }
    printf("\n");
    va_end(argptr);
    return 0;
}