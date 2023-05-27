#include "s21_string.h"
#include <stdio.h>

int main ()
{
    char bas[80];
    //sprintf(bas, "%c %c %d", '1', 2, '3');
    s21_sprintf(bas, "%s %c %d", "one", 'N', 304);
    printf("%s\n", bas);
    return 0;
}