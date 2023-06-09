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

int reduction(int arr1, int arr2, int length) {
        int res1 = memcmp(arr1, arr2, length);
        res1 = res1 > 0 ? 1 : res1 == 0 ? 0 : -1;
        return res1;
}
START_TEST(tests_memcmp) {
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

START_TEST(tests_memset) {
  s21_size_t len0 = 0;
  s21_size_t len5 = 5;
  int add_end = '\0';
  int add_digit = 7;
  int add_space = ' ';
  char string1[] = "";
  char string2[] = "";
  ck_assert_str_eq(memset(string1, add_end, len0), s21_memset(string2, add_end, len0));
  ck_assert_str_eq(memset(string1, add_digit, len5), s21_memset(string2, add_digit, len5));
  char string3[] = "Danke schon";
  char string4[] = "Danke schon";
  ck_assert_str_eq(memset(string3, add_end, len5), s21_memset(string4, add_end, len5));
  char string5[] = "123456789";
  char string6[] = "123456789";
  s21_size_t length = strlen(string5);
  ck_assert_str_eq(memset(string5, add_space, length), s21_memset(string6, add_space, length));
  char string7[] = "First things first";
  char string8[] = "First things first";
  ck_assert_str_eq(memset(string7, add_space, len0), s21_memset(string8, add_space, len0));
  char string9[] = "Oh my God!";
  char string10[] = "Oh my God!";
  ck_assert_str_eq(memset(string9, add_space, len5), s21_memset(string10, add_space, len5));
}
END_TEST

START_TEST(tests_strncat) {
  char src1[] = "";
  char src2[] = " ";
  char src3[] = "\0";
  char src4[] = "world";
  char src5[] = "a";
  int len0 = 0;
  int len1 = 1;
  int len2 = 2;
  int len5 = 5;
  int len10 = 10;

  str1 = "Hello ";
  str11 = "Hello ";
  ck_assert_pstr_eq(strncat(str1, src4, len5), s21_strncat(str11, src4, len5));
  // добавить слово целиком
  str2 = "Hello ";
  str22 = "Hello ";
  ck_assert_pstr_eq(strncat(str2, src4, len2), s21_strncat(str22, src4, len2));
  // добавить слово НЕ целиком
  str3 = "Hell ";
  str33 = "Hell ";
  ck_assert_pstr_eq(strncat(str3, src4, len10), s21_strncat(str3, src4, len10));
  // добавить строку больше исходной
  str4 = "Hell ";
  str44 = "Hell ";
  ck_assert_pstr_eq(strncat(str4, src5, len1), s21_strncat(str4, src5, len1));
  // добавить символ
  str5 = "Hi";
  str55 = "Hi";
  ck_assert_pstr_eq(strncat(str5, src1, len1), s21_strncat(str55, src1, len1));
  // добавить пустую строку
  str6 = "";
  str66 = "";
  ck_assert_pstr_eq(strncat(str6, src4, len5), s21_strncat(str66, src4, len5));
  // добавить строку в пустую строку целиком
  str7 = "";
  str77 = "";
  ck_assert_pstr_eq(strncat(str7, src4, len1), s21_strncat(str77, src4, len1));
  // добавить строку в пустую строку НЕ целиком
  str8 = "Hello";
  str88 = "Hello";
  ck_assert_pstr_eq(strncat(str8, src4, len0), s21_strncat(str88, src4, len0));
  // добавить 0 символов
  str9 = "Hello";
  str99 = "Hello";
  ck_assert_pstr_eq(strncat(str9, src3, len2), s21_strncat(str99, src3, len2));
  // добавить символ конца строки "\0"
}
END_TEST

START_TEST(tests_strchr) {
  int not_exist = 'A';
  int exist = 'K';
  int twice = 'e';
  int end = '\0';
  int digit = 42;
  int maybe_digit = '7';
  int sym = '!';
  char s1[] = "Keep calm and code on!";
  // Несуществующий символ
  ck_assert_pstr_eq(strchr(s1, not_exist), s21_strchr(s1, not_exist));
  // Существующий символ
  ck_assert_pstr_eq(strchr(s1, exist), s21_strchr(s1, exist));
  // Существующий символ, который встречается несколько раз
  ck_assert_pstr_eq(strchr(s1, twice), s21_strchr(s1, twice));
  // Конец строки
  ck_assert_pstr_eq(strchr(s1, end), s21_strchr(s1, end));
  // Символ
  ck_assert_pstr_eq(strchr(s1, sym), s21_strchr(s1, sym));
  // Число
  ck_assert_pstr_eq(strchr(s1, digit), s21_strchr(s1, digit));
  ck_assert_pstr_eq(strchr(s1, maybe_digit), s21_strchr(s1, maybe_digit));
}
END_TEST

START_TEST(tests_strrchr) {
  int not_exist = 'A';
  int exist = 'd';
  int twice = 'e';
  int end = '\0';
  int digit = 42;
  int maybe_digit = '7';
  int sym = ',';
  char yep[] = "Eat, code, love";
  ck_assert_pstr_eq(strrchr(yep, not_exist), s21_strrchr(yep, not_exist));
  ck_assert_pstr_eq(strrchr(yep, exist), s21_strrchr(yep, exist));
  ck_assert_pstr_eq(strrchr(yep, twice), s21_strrchr(yep, twice));
  ck_assert_pstr_eq(strrchr(yep, end), s21_strrchr(yep, end));
  ck_assert_pstr_eq(strrchr(yep, sym), s21_strrchr(yep, sym));
  ck_assert_pstr_eq(strrchr(yep, digit), s21_strrchr(yep, digit));
  ck_assert_pstr_eq(strrchr(yep, maybe_digit), s21_strrchr(yep, maybe_digit));
}
END_TEST

int reduction2(int arr1, int arr2, int length) {
        int ress = strncmp(arr1, arr2, length);
        ress = ress > 0 ? 1 : ress == 0 ? 0 : -1;
        return ress;
}

START_TEST(test_strncmp) {
    s21_size_t len0 = 0;
    s21_size_t len1 = 1;
    s21_size_t len2 = 2;
    s21_size_t len11 = 11;
    s21_size_t len21 = 21;
    s21_size_t len30 = 30;
    // Сравнение массива из символов
    char song1 = "Sweet dreams are made of this";
    char song2 = "Sweet dreams are made of this";
    ck_assert_ptr_eq(reduction2(song1, song2, len30), s21_strncmp(song1, song2, len30));
    ck_assert_ptr_eq(reduction2(song1, song2, len0), s21_strncmp(song1, song2, len0));
    // Сравнение массива разных фраз
    char song3 = "Who am I to disagree";
    char song4 = "Who am I to disagryy";
    ck_assert_ptr_eq(reduction2(song3, song4, len21), s21_strncmp(song3, song4, len21));
    // Сравнение массива из чисел
    char digit1 = "4815162342";
    char digit2 = "4815162342";
    ck_assert_ptr_eq(reduction2(digit1, digit2, len11), s21_strncmp(digit1, digit2, len11));
    ck_assert_ptr_eq(reduction2(digit1, digit2, len2), s21_strncmp(digit1, digit2, len2));
    ck_assert_ptr_eq(reduction2(digit1, digit2, len0), s21_strncmp(digit1, digit2, len0));
    // Сравнение пустой строки с пробелом
    char space_str1 = " ";
    char space_str2= " ";
    ck_assert_ptr_eq(reduction2(space_str1, space_str2, len2), s21_strncmp(space_str1, space_str2, len2));
    // Сравнение пустой строки
    char empty_str1 = "";
    char empty_str2 = "";
    char empty_str3 = "K";
    char empty_str4 = "";
    ck_assert_ptr_eq(reduction2(empty_str1, empty_str2, len1), s21_strncmp(empty_str1, empty_str2, len1));
    ck_assert_ptr_eq(reduction2(empty_str3, empty_str4, len1), s21_strncmp(empty_str3, empty_str4, len1));
}
END_TEST


Suite *test_memchr(void) {
  Suite *s = suite_create("\033[45m-=S21_MEMCHR=-\033[0m");
  TCase *tc = tcase_create("memchr_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, tests_memchr);
  tcase_add_test(tc, tests_memcpy);
  tcase_add_test(tc, tests_memcmp);
  tcase_add_test(tc, tests_memset);
  tcase_add_test(tc, tests_strchr);
  tcase_add_test(tc, tests_strrchr);
  tcase_add_test(tc, tests_strncat);
  suite_add_tcase(s, tc);
  return s;
}
