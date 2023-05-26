#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

void *memchr(const void *str, int c, size_t n);
int memcmp(const void *str1, const void *str2, size_t n);
char *strchr(const char *str, int c)
int s21_sprintf(char* buf, char* format, ...);
//void print_arg(va_list argptr, base_mass str);

typedef struct {
    char mas_format[100];
    int mas_format_len;
    int type;
} base_mass;

#endif