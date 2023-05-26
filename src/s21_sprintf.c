#include "s21_string.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_arg(va_list argptr, char mas_format) {
    switch (mas_format) {
        case 'd':
            printf("%d", va_arg(argptr, int));
            break;
        case 'c':
            printf("%c", va_arg(argptr, int));
            break;
        case 's':
            printf("%s", va_arg(argptr, char*));
            break;
        default:
            break;
    }
}
// c, d, i, e, E, f, g, G, o, s, u, x, X, p, n, %
// 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0

int s21_sprintf(char* buf, char* format, ...)
{
    char mas_format[100];
    buf = buf;
    va_list argptr;
    va_start(argptr, format);
    int k=0;

    for(int i=0; format[i] != '\0'; i++)
        if(format[i] != '%' && format[i] != ' ')
            mas_format[k++] = format[i];

    int mas_format_len = strlen(mas_format);
    for(int i=0; i<mas_format_len; i++) {
        print_arg(argptr, mas_format[i]);
    }
    printf("\n");
    va_end(argptr);
    return 0;
}