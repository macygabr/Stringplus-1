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

int reduction(int arr1, int arr2, int length) {
        int res1 = memcmp(arr1, arr2, length);
        res1 = res1 > 0 ? 1 : res1 == 0 ? 0 : -1;
        return res1;
}
START_TEST(test_s21_memcmp) {
    s21_size_t len0 = 0;
    s21_size_t len1 = 1;
    s21_size_t len2 = 2;
    s21_size_t len6 = 6;
    s21_size_t len11 = 11;
    s21_size_t len13 = 13;
    s21_size_t len53 = 53;
    // Сравнение массива из символов
    char arr1 = "Hola, amigo!";
    char arr2 = "Hola, amigo!";
    ck_assert_ptr_eq(reduction(arr1, arr2, len13), s21_memcmp(arr1, arr2, len13));
    ck_assert_ptr_eq(reduction(arr1, arr2, len6), s21_memcmp(arr1, arr2, len6));
    ck_assert_ptr_eq(reduction(arr1, arr2, len0), s21_memcmp(arr1, arr2, len0));
    // Сравнение массива из чисел
    char arr3 = "4815162342";
    char arr4 = "4815162342";
    ck_assert_ptr_eq(reduction(arr3, arr4, len11), s21_memcmp(arr3, arr4, len11));
    ck_assert_ptr_eq(reduction(arr3, arr4, len6), s21_memcmp(arr3, arr4, len6));
    ck_assert_ptr_eq(reduction(arr3, arr4, len0), s21_memcmp(arr3, arr4, len0));
    // Сравнение массива из фразы
    char arr5 = "The sign of the result is the sign of the difference";
    char arr6 = "The sign of the result is the sign of the difference";
    ck_assert_ptr_eq(reduction(arr5, arr6, len53), s21_memcmp(arr5, arr6, len53));
    ck_assert_ptr_eq(reduction(arr5, arr6,len13), s21_memcmp(arr5, arr6, len13));
    ck_assert_ptr_eq(reduction(arr5, arr6, len0), s21_memcmp(arr5, arr6, len0));
    // Сравнение пустой строки с пробелом
    char arr7 = " ";
    char arr8 = " ";
    ck_assert_ptr_eq(reduction(arr7, arr8, len2), s21_memcmp(arr7, arr8, len2));
    // Сравнение пустой строки
    char arr9 = "";
    char arr10 = "";
    ck_assert_ptr_eq(reduction(arr9, arr10, len1), s21_memcmp(arr9, arr10, len1));
}
END_TEST