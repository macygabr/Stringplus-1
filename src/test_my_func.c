#include "s21_string.h"
#include <stdio.h>

int main ()
{
    char bas[80];
    s21_sprintf(bas, "%s %c %f", "one", '8', 10.11);
    //sprintf(bas, "%s %c %d %f", "one", 'N', 1, 10.1);
    printf("%s\n", bas);
    
    return 0;
}