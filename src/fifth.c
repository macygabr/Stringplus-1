#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long unsigned s21_size_t;

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  if (str == NULL)
    len = -1;
  else
    for (; str[len]; len++)
      ;
  return len + 1;
};

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
  char *b1 = "ABCD";
  char *b3 = "abc";
  char *buff1 = "12";
  char *b11 = "1112221132221";
  char *b31;

  // printf("%s to low %s\n", buff, s21_to_lower(buff));
  // printf("%s to low %s\n", b1, s21_to_lower(b1));
  // printf("%s to low %s\n", b3, s21_to_lower(b3));
  // printf("%s to low %s\n", buff1, s21_to_lower(buff1));
  // printf("%s to low %s\n", b11, s21_to_lower(b11));
  // printf("%s to low %s\n\n", b31, s21_to_lower(b31));
  // printf("%s to up %s\n", buff, s21_to_upper(buff));
  // printf("%s to up %s\n", b1, s21_to_upper(b1));
  // printf("%s to up %s\n", b3, s21_to_upper(b3));
  // printf("%s to up %s\n", buff1, s21_to_upper(buff1));
  // printf("%s to up %s\n", b11, s21_to_upper(b11));
  // printf("%s to up %s\n\n", b31, s21_to_upper(b31));
  // char *rez = s21_insert(b3, buff1, 1);
  // printf("%s in %s from 1 %s\n", b3, buff1, rez);
  // rez = s21_insert(b3, buff1, 0);
  // printf("%s in %s from 0 %s\n", b3, buff1, rez);
  // rez = s21_insert(b3, buff1, 20);
  // printf("%s in %s from 20 %s\n", b3, buff1, rez);
  // rez = s21_insert(buff, buff1, 1);
  // printf("%s in %s from 1 %s\n", buff, buff1, rez);
  // rez = s21_insert(b3, buff, 0);
  // printf("%s in %s from 0 %s\n", b3, buff, rez);
  // rez = s21_insert(buff, buff, 20);
  // printf("%s in %s from 20 %s\n", buff, buff, rez);
  printf("%s.\n", s21_trim(b11, buff1));

  return 0;
}

// Возвращает новую строку, в которой удаляются все начальные и конечные
// вхождения набора заданных символов (trim_chars) из данной строки (src). В
// случае какой-либо ошибки следует вернуть значение NULL
void *s21_trim(const char *src, const char *trim_chars) {
  char *rezult;
  if (src == NULL)
    rezult = NULL;
  else {
    int null_flag;
    int len = strlen(src);
    if (trim_chars == NULL) {
      int start = 0, end = len - 1;
      while (src[start] == ' ' || src[start] == '\t' || src[start] == '\n' ||
             src[start] == '\r')
        start++;
      while (src[end] == ' ' || src[end] == '\t' || src[end] == '\n' ||
             src[end] == '\r')
        end--;
      rezult = (char *)malloc(sizeof(char) * (end - start));
      for (int i = start, j = 0; i <= end; j++, i++) rezult[j] = src[i];

      // 111222113  и шаблоном 12 должно получиться 113
    } else {
      int trim_len = strlen(trim_chars);
      int start = 0, end = len;
      char *trim_deleted = malloc(sizeof(trim_chars));
      strcpy(trim_deleted, trim_chars);
      for (int i = 0; i < trim_len; i++) {
        if (src[start] == trim_deleted[i]) {
          while (src[start] == trim_deleted[i]) start++;
          // удалить этот символ из trim_chars
          char *buff = malloc(sizeof(trim_deleted) - sizeof(char));
          for (int k = 0, j = 0; j < trim_len; k++, j++) {
            if (j == i) j++;
            buff[k] = trim_deleted[j];
          }
          free(trim_deleted);
          trim_deleted = malloc(sizeof(buff));
          strcpy(trim_deleted, buff);
          free(buff);

          i = -1;
          trim_len = trim_len - 1;
        }
      }
      free(trim_deleted);
      trim_deleted = malloc(sizeof(trim_chars));
      strcpy(trim_deleted, trim_chars);

      for (int i = 0; i < trim_len; i++) {
        if (src[end] == trim_deleted[i]) {
          while (src[end] == trim_deleted[i]) end--;
          // удалить этот символ из trim_chars
          char *buff = malloc(sizeof(trim_deleted) - sizeof(char));
          for (int k = 0, j = 0; j < trim_len; k++, j++) {
            if (j == i) j++;
            buff[k] = trim_deleted[j];
          }
          free(trim_deleted);
          trim_deleted = malloc(sizeof(buff));
          strcpy(trim_deleted, buff);
          free(buff);

          i = -1;
          trim_len = trim_len - 1;
        }
      }
      rezult = malloc(sizeof(char) * (end - start));
      for (int j = 0, i = start; i < end; j++, i++) {
        rezult[j] = src[i];
      }
    }
  }
  return rezult;
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *rezult;
  if (start_index < 0 || start_index > s21_strlen(str) ||
      (str == NULL && src == NULL))
    rezult = NULL;
  else if (str != NULL && src != NULL) {
    rezult =
        (char *)malloc((s21_strlen(str) + s21_strlen(src) + 1) * sizeof(char));
    strncpy(rezult, str, start_index);
    strcpy(rezult + start_index, src);
    strcpy(rezult + start_index + s21_strlen(src), str + start_index);
  } else if (src == NULL) {
    rezult = malloc(sizeof(str));
    strcpy(rezult, str);
  } else if (str == NULL && start_index == 0) {
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
    for (int i = 0; i < s21_strlen(str); i++)
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
    for (int i = 0; i < s21_strlen(str); i++)
      if (rezult[i] >= 'a' && rezult[i] <= 'z') rezult[i] += 'A' - 'a';
  } else
    rezult = NULL;
  return rezult;
}