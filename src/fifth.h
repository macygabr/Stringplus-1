#ifndef FIFTH_H
#define FIFTH_H

typedef long unsigned s21_size_t;

s21_size_t s21_strlen(const char *str);

void *s21_insert(const char *src, const char *str, s21_size_t start_index);

void s21_itoa(int a, char *result);

char *s21_strcat(char *dest, const char *src);

char *s21_strncpy(char *dest, const char *src, s21_size_t n);

char *s21_strerror(int errnum);

void *s21_to_upper(const char *str);

void *s21_to_lower(const char *str);

void *s21_trim(const char *src, const char *trim_chars);

#endif
