#include <check.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "s21_string.h"

START_TEST(tests_memchr) {
static char str1 = "Lorem ipsum dolor sit amet.";
static char str2 = "12345";
int sym1 = 115;
int sym2 = 120;
int sym3 = 'd';
int sym4 = 111;
int sym5 = ' ';
int sym6 = '4';
int sym7 = '9';
s21_size_t len1 = strlen(str1);
s21_size_t len2 = strlen(str2);
s21_size_t len5 = 5;
ck_assert_ptr_eq(memchr(str1, sym1, len1), s21_memchr(str1, sym1, len1)); // поиск символа в полной строке
ck_assert_ptr_eq(memchr(str2, sym6, len2), s21_memchr(str2, sym6, len2));
ck_assert_ptr_eq(memchr(str1, sym2, len1), s21_memchr(str1, sym2, len1)); // поиск несуществующего символа в строке
ck_assert_ptr_eq(memchr(str2, sym7, len2), s21_memchr(str2, sym7, len2));
ck_assert_ptr_eq(memchr(str1, sym1, len5), s21_memchr(str1, sym1, len5)); // поиск существующего символ, но он находится за пределами сравнения
ck_assert_ptr_eq(memchr(str1, sym3, len1), s21_memchr(str1, sym3, len1)); // поиск char символа, входящего в строку
ck_assert_ptr_eq(memchr(str2, sym3, len2), s21_memchr(str2, sym3, len2));
ck_assert_ptr_eq(memchr(str1, sym3, len1), s21_memchr(str1, sym3, len1)); // проверка на символ, который несколько раз встречается в строке
ck_assert_ptr_eq(memchr(str1, sym5, len1), s21_memchr(str1, sym5, len1)); // проверка на символ "пробел"
}
END_TEST

START_TEST(tests_memcpy) {
  char src1[] = "hard";
  s21_size_t len0 = 0;
  s21_size_t len1 = 1;
  s21_size_t len4 = 1;
  s21_size_t len10 = 10;
  // выше записы часто использующие переменные

  char dest1[] = "No pain, no gain!";
  char dest11[] = "No pain, no gain!";
  ck_assert_ptr_eq(memcpy(dest1, src1, len4), s21_memcpy(dest11, src4, len1));
  // копирование полного слова в непустой массив
  char dest2[] = "No pain, no gain!";
  char dest22[] = "No pain, no gain!";
  ck_assert_ptr_eq(memcpy(dest2, src1, len0), s21_memcpy(dest22, src1, len0));
  // копирование 0 символов
  char src3[] = "\0";
  char dest3[] = "No pain, no gain!";
  char dest33[] = "No pain, no gain!";
  ck_assert_ptr_eq(memcpy(dest3, src3, len1), s21_memcpy(dest33, src3, len1));
  // копирование символа конца строки. ожидание: пустая строка
  char dest4[] = "No pain, no gain!";
  char dest44[] = "No pain, no gain!";
  ck_assert_ptr_eq(memcpy(dest4, src1, len10), s21_memcpy(dest44, src1, len10));
  // копирование большего числа битов чем в копируемой строке
  char src5[] = "";
  char dest5[] = "No pain, no gain!";
  char dest55[] = "No pain, no gain!";
  ck_assert_ptr_eq(memcpy(dest5, src5, len10), s21_memcpy(dest55, src5, len10));
  // копирование пустой строки
  char dest6[] = "";
  char dest66[] = "";
  // копирование в пустую строку полную строку
  ck_assert_ptr_eq(memcpy(dest6, src1, len10), s21_memcpy(dest66, src1, len10));
  char dest7[] = "No pain, no gain!";
  char dest77[] = "No pain, no gain!";
  ck_assert_ptr_eq(memcpy(dest7, src1, len1), s21_memcpy(dest77, src1, len1));
  // копирование в пустую строку неполную строку
  char sr8[] = " ";
  char dest8[] = "No pain, no gain!";
  char dest88[] = "No pain, no gain!";
  ck_assert_ptr_eq(memcpy(dest88, src8, len1), s21_memcpy(dest77, src1, len1));
  // копирование пробела
}
END_TEST


