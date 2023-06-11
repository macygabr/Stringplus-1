#include "s21_string.h"
#include <stdio.h>

int main() {
    char str1[200];
    char str2[200];
    char *str3 = "%.6Lf!";
    long double num = -635293201236310753.6495633;
    sprintf(str1, str3, num);
    s21_sprintf(str2, str3, num);
     printf("[%s]\n[%s]\n\n", str1, str2);
    return 0;
}