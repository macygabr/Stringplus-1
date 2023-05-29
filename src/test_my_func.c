#include "s21_string.h"
#include <stdio.h>

int main ()
{
    char bas[200];
    s21_sprintf(bas, "%s %c %-12d %u %%", "one", '8', -10, 10);
    printf("pice of shit = \"%s\"\n", bas);
    sprintf(bas, "%s %c %-12d %u %%", "one", '8', -10, 10);
    printf("origin       = \"%s\"\n", bas);
    return 0;
}