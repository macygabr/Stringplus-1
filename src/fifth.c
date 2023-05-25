#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Возвращает копию строки (str), преобразованной в верхний регистр. В случае
// какой-либо ошибки следует вернуть значение NULL
void *s21_to_upper(const char *str);

// Возвращает копию строки (str), преобразованной в нижний регистр. В случае
// какой-либо ошибки следует вернуть значение NULL
void *s21_to_lower(const char *str);

// Возвращает новую строку, в которой указанная строка (str) вставлена в
// указанную позицию (start_index) в данной строке (src). В случае какой-либо
// ошибки следует вернуть значение NULL
void *s21_insert(const char *src, const char *str, size_t start_index);

// Возвращает новую строку, в которой удаляются все начальные и конечные
// вхождения набора заданных символов (trim_chars) из данной строки (src). В
// случае какой-либо ошибки следует вернуть значение NULL
void *s21_trim(const char *src, const char *trim_chars);

int main() {
  char *buff = NULL;
  char *b1 = "AB\tCD";
  char *b3 = "AbC";
  char *buff1 = "1a1bcd1";
  char *b11 = "1ABC1D1";
  char *b31;

  //   printf("%s to low %s\n", buff, s21_to_lower(buff));
  //   printf("%s to low %s\n", b1, s21_to_lower(b1));
  //   printf("%s to low %s\n", b3, s21_to_lower(b3));
  //   printf("%s to low %s\n", buff1, s21_to_lower(buff1));
  //   printf("%s to low %s\n", b11, s21_to_lower(b11));
  //   printf("%s to low %s\n\n", b31, s21_to_lower(b31));
  //   printf("%s to up %s\n", buff, s21_to_upper(buff));
  //   printf("%s to up %s\n", b1, s21_to_upper(b1));
  //   printf("%s to up %s\n", b3, s21_to_upper(b3));
  //   printf("%s to up %s\n", buff1, s21_to_upper(buff1));
  //   printf("%s to up %s\n", b11, s21_to_upper(b11));
  //   printf("%s to up %s\n", b31, s21_to_upper(b31));

  printf("%s in %s from 1 %s", b3, buff1, s21_insert(b3, buff1, 1));
  printf("%s in %s from 0 %s", b3, buff1, s21_insert(b3, buff1, 0));
  printf("%s in %s from 20 %s", b3, buff1, s21_insert(b3, buff1, 20));
  printf("%s in %s from 1 %s", b31, buff1, s21_insert(b31, buff1, 1));
  printf("%s in %s from 0 %s", b3, b31, s21_insert(b3, b31, 0));
  printf("%s in %s from 20 %s", b31, b31, s21_insert(b31, b31, 20));
  return 0;
}
// нужно исправить сегу и нормально обработать ошибки по длине
void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *rezult;
  if (strlen(str) >= start_index && str != NULL && src != NULL) {
    int len_str = strlen(str);
    int len_src = strlen(src);
    int len_all = len_str + len_src;
    rezult = malloc(sizeof(str) + sizeof(src));
    for (int i = 0, t = 0; i < len_all; i++, t++) {
      if (i == start_index) {
        for (int j = 0; j < len_src; j++, i++) rezult[i] = src[j];
      }
      rezult[i] = str[t];
    }
  } else if (str != NULL && src == NULL) {
    rezult = malloc(sizeof(str));
    strcpy(rezult, str);
  } else if (str == NULL && src != NULL) {
    rezult = malloc(sizeof(src));
    strcpy(rezult, src);
  } else
    rezult = NULL;
  return rezult;
}

void *s21_to_lower(const char *str) {
  char *rezult;
  if (str != NULL) {
    rezult = malloc(sizeof(str));
    strcpy(rezult, str);
    register size_t i = (size_t)-1;
    while (rezult[++i])
      if (rezult[i] >= 'A' && rezult[i] <= 'Z') rezult[i] += 'a' - 'A';
  } else
    rezult = NULL;
  return rezult;
}

void *s21_to_upper(const char *str) {
  char *rezult;
  if (str != NULL) {
    rezult = malloc(sizeof(str));
    strcpy(rezult, str);
    register size_t i = (size_t)-1;
    while (rezult[++i])
      if (rezult[i] >= 'a' && rezult[i] <= 'z') rezult[i] += 'A' - 'a';
  } else
    rezult = NULL;
  return rezult;
}