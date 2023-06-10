#include "s21_string.h"
#include <stdio.h>

//buf - откуда брать штуки
//format - какие штуки брать
//... - куда пихать штуки

int s21_sscanf(char *buf, char *format, ...) {
    
    return 0;
}

int main() {
    char* buf = "23 e hello";
    char* format = "%d %c %s";
    int num;
    char ch;
    char str[1024];
    
    sscanf(buf, format, num, ch, str);
    printf("ori: [%d], [%c], [%s]", num, ch, str);

    s21_sscanf(buf, format, num, ch, str);
    printf("s21: [%d], [%c], [%s]", num, ch, str);
    return 0;
}