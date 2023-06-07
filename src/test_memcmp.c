#include <check.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "s21_string.h"

//сравнение массивов

START_TEST(test_s21_memcmp) {
char arr1 = "Hola, amigo!";
char arr2 = "Hola, amigo!";
char arr3 = "123456789";
char arr4 = "123456789";
char arr5 = "The sign of the result is the sign of the difference";
char arr6 = "The sign of the result is the sign of the difference";
char arr7 = " ";
char arr8 = " ";
char arr9 = "";
char arr10 = "";
s21_size_t len1 = 0;
s21_size_t len2 = 6;
s21_size_t len3 = 13;
s21_size_t len4 = 10;
s21_size_t len5 = 53;
s21_size_t len6 = 1;
s21_size_t len7 = 2;
// Сравнение всей длины массива из символов
ck_assert_ptr_eq(memcmp(arr1, arr2, len3), s21_memcmp(arr1, arr2, len3));
// Сравнение половины длины массива из символов
ck_assert_ptr_eq(memcmp(arr1, arr2, len2), s21_memcmp(arr1, arr2, len2));
// Сравнение 0 длины массива из символов
ck_assert_ptr_eq(memcmp(arr1, arr2, len1), s21_memcmp(arr1, arr2, len1));
// Сравнение всей длины массива из чисел
ck_assert_ptr_eq(memcmp(arr3, arr4, len4), s21_memcmp(arr3, arr4, len4));
// Сравнение части длины массива из чисел
ck_assert_ptr_eq(memcmp(arr3, arr4, len2), s21_memcmp(arr3, arr4, len2));
// Сравнение 0 длины массива из чисел
ck_assert_ptr_eq(memcmp(arr3, arr4, len1), s21_memcmp(arr3, arr4, len1));
// Сравнение всей длины массива из фразы
ck_assert_ptr_eq(memcmp(arr5, arr6, len5), s21_memcmp(arr5, arr6, len5));
// Сравнение части длины массива из фразы
ck_assert_ptr_eq(memcmp(arr5, arr6,len3), s21_memcmp(arr5, arr6, len3));
// Сравнение 0 длины массива из фразы
ck_assert_ptr_eq(memcmp(arr5, arr6, len1), s21_memcmp(arr5, arr6, len1));
// Сравнение пустой строки с пробелом
ck_assert_ptr_eq(memcmp(arr7, arr8, len6), s21_memcmp(arr7, arr8, len6));
// Сравнение пустой строки
ck_assert_ptr_eq(memcmp(arr9, arr10, len7), s21_memcmp(arr9, arr10, len7));
}
END_TEST

int main() {
    Suite *test_memcmp(void) {
    Suite *s = suite_create("\033[45m-=S21_MEMCMP=-\033[0m");
    TCase *tc = tcase_create("memcmp_tc");
    tcase_add_test(tc, test_s21_memcmp);
    suite_add_tcase(s, tc);
    return s;
    }
}