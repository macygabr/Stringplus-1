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

