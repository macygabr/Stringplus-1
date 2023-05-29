#include "s21_string.h"
#include <stdio.h>

int main ()
{
    char bas[200];
    s21_sprintf(bas, "%-4s %c %-10d %u %% %+11f % 2f", "one", '8', -10, 11, -12.1, -13.1);
    printf("pice of shit = \"%s\"\n", bas);
    sprintf(bas, "%-4s %c %-10d %u %% %+11f % 2f", "one", '8', -10, 11, -12.1, -13.1);
    printf("origin       = \"%s\"\n", bas);
    return 0;
}