#ifndef FIFTH_H
#define FIFTH_H

typedef long unsigned s21_size_t;
// rodd
char *s21_strerror(int errnum);
// rodd
void s21_delete(char *trim_deleted, int p);

char *s21_strcat(char *dest, const char *src);
// rodd
void s21_itoa(int a, char *result);

char *s21_strncpy(char *dest, const char *src, s21_size_t n);

s21_size_t s21_strlen(const char *str)
    // rodd
    void *s21_to_lower(const char *str);
// rodd
void *s21_to_upper(const char *str);
// rodd
void *s21_trim(const char *src, const char *trim_chars);
// rodd
void *s21_insert(const char *src, const char *str, s21_size_t start_index);

#endif
