#include "s21_string.h"
#include <stdio.h>

int main(void) {
    char array[7] = "asdfghj";
    char *sym = 0;
    printf("%s\n", array);
    sym = memchr(array, '6', 5);
    sym[0] = 'A';
    printf("%s\n", array);
    return 0;
}

// int main() {
//     FILE *f;
//     f = fopen("e.txt", "r");
//     if (f == S21_NULL) {
//         printf("yes");
//     } else
//         printf("don't work");
//     return 0;
// }