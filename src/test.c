#include "s21_string.h"
#include <stdio.h>

int main(void) {
    char array[7] = "1234567";
    char *sym = 0;
    printf("%s\n", array);
    sym = memchr(array, '4', 5);
    if (sym != NULL) {
        sym[0] = 'A';
    }
    printf("new array is: %s\n", array);
    return 0;
}