#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

int s21_string();
int s21_sprintf(char* buf, char* format, ...);
//void print_arg(va_list argptr, base_mass str);

typedef struct {
    char mas_format[100];
    int mas_format_len;
    int type;
} base_mass;

#endif