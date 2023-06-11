#include <check.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "s21_string.h"
// 1
START_TEST(tests_memchr) {
    static char str1[28] = "Lorem ipsum dolor sit amet.";
    static char str2[6] = "12345";
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
// 2
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
// 3
START_TEST(tests_memcpy) {
  char src1[] = "hard";
  char src4[] = "hard";
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
  // копирование символа конца строки.
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
  char src8[] = " ";
  char dest8[] = "No pain, no gain!";
  char dest88[] = "No pain, no gain!";
  ck_assert_ptr_eq(memcpy(dest88, src8, len1), s21_memcpy(dest77, src1, len1));
  // копирование пробела
}
END_TEST
// 4
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
// 5
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
// часто используемые переменные
  char str1 = "Hello ";
  char str11 = "Hello ";
  ck_assert_pstr_eq(strncat(str1, src4, len5), s21_strncat(str11, src4, len5));
  // добавить слово целиком
  char str2 = "Hello ";
  char str22 = "Hello ";
  ck_assert_pstr_eq(strncat(str2, src4, len2), s21_strncat(str22, src4, len2));
  // добавить слово НЕ целиком
  char str3 = "Hell ";
  char str33 = "Hell ";
  ck_assert_pstr_eq(strncat(str3, src4, len10), s21_strncat(str3, src4, len10));
  // добавить строку больше исходной
  char str4 = "Hell ";
  char str44 = "Hell ";
  ck_assert_pstr_eq(strncat(str4, src5, len1), s21_strncat(str4, src5, len1));
  // добавить символ
  char str5 = "Hi";
  char str55 = "Hi";
  ck_assert_pstr_eq(strncat(str5, src1, len1), s21_strncat(str55, src1, len1));
  // добавить пустую строку
  char str6 = "";
  char str66 = "";
  ck_assert_pstr_eq(strncat(str6, src4, len5), s21_strncat(str66, src4, len5));
  // добавить строку в пустую строку целиком
  char str7 = "";
  char str77 = "";
  ck_assert_pstr_eq(strncat(str7, src4, len1), s21_strncat(str77, src4, len1));
  // добавить строку в пустую строку НЕ целиком
  char str8 = "Hello";
  char str88 = "Hello";
  ck_assert_pstr_eq(strncat(str8, src4, len0), s21_strncat(str88, src4, len0));
  // добавить 0 символов
  char str9 = "Hello";
  char str99 = "Hello";
  ck_assert_pstr_eq(strncat(str9, src3, len2), s21_strncat(str99, src3, len2));
  // добавить символ конца строки "\0"
}
END_TEST
// 6
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
// 7
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
// 8
START_TEST(tests_strncpy) {
  char src1 = "";
  char src2 = "Life cycle";
  char src3 = "\0";
  int len0 = 0;
  int len1 = 1;
  int len4 = 4;
  int lenStr = s21_strlen(src2);
  char dest1 = "Eat Sleep Code Repeat";
  char dest11 = "Eat Sleep Code Repeat";
  ck_assert_pstr_eq(strncpy(dest1, src2, lenStr), s21_strncpy(dest11, src2, lenStr));
  // Скопировать полную строку
  char dest2 = "Eat Sleep Code Repeat";
  char dest22 = "Eat Sleep Code Repeat";
  ck_assert_pstr_eq(strncpy(dest2, src2, len4), s21_strncpy(dest22, src2, len4));
  // Первая строка короче копируемой
  char dest3 = "Eat Sleep Code Repeat";
  char dest33 = "Eat Sleep Code Repeat";
  ck_assert_pstr_eq(strncpy(dest3, src1, len4), s21_strncpy(dest33, src1, len4));
  // Копируемая строка пустая
  char dest4 = "";
  char dest44 = "";
  ck_assert_pstr_eq(strncpy(dest4, src2, len4), s21_strncpy(dest44, src2, len4));
  // Все строки пустые
  char dest5 = "Eat Sleep Code Repeat";
  char dest55 = "Eat Sleep Code Repeat";
  ck_assert_pstr_eq(strncpy(dest5, src3, len1), s21_strncpy(dest55, src3, len1));
  // Прибавить символ конца строки
  char dest6 = "Eat Sleep Code Repeat";
  char dest66 = "Eat Sleep Code Repeat";
  ck_assert_pstr_eq(strncpy(dest6, src2, len1), s21_strncpy(dest66, src2, len1));
  // Копирование 1 символа из копируемой строки
  char dest7 = "Eat Sleep Code Repeat";
  char dest77 = "Eat Sleep Code Repeat";
  ck_assert_pstr_eq(strncpy(dest7, src2, len0), s21_strncpy(dest77, src2, len0));
  // Копирование 0 символов из копируемой строки
}
END_TEST
// 9
START_TEST(tests_strspn) {
  char str1 = "In the end";
  char str11 = "In";
  ck_assert_int_eq(strspn(str1, str11), s21_strspn(str1, str11));
  // искомые символы находятся в начале строки
  char str22 = "nI";
  ck_assert_int_eq(strspn(str1, str22), s21_strspn(str1, str22));
  // искомые символы находятся в начале строки, но находятся в другой последовательности
  char str33 = "the";
  ck_assert_int_eq(strspn(str1, str33), s21_strspn(str1, str33));
  // искомые символы находятся в середине строки
  char str44 = "n";
  ck_assert_int_eq(strspn(str1, str44), s21_strspn(str1, str44));
  // один искомый символ
  char str55 = "";
  ck_assert_int_eq(strspn(str1, str55), s21_strspn(str1, str55));
  // искомый символ пустой
  char str66 = "\0";
  ck_assert_int_eq(strspn(str1, str66), s21_strspn(str1, str66));
  // искомый символ равен концу строки
  char str7 = "";
  char str77 = "";
  ck_assert_int_eq(strspn(str7, str11), s21_strspn(str7, str11));
  // первая строка пустая
  ck_assert_int_eq(strspn(str1, str77), s21_strspn(str1, str77));
  // вторая строка пустая
  ck_assert_int_eq(strspn(str7, str77), s21_strspn(str7, str77));
  // все строки пустые
  char str88 = "In the end";
  ck_assert_int_eq(strspn(str1, str88), s21_strspn(str1, str88));
  // строки одинаковые
}
END_TEST
// 10
START_TEST(error_0) {
  char *str1 = s21_strerror(1);
  char *str2 = strerror(1);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(error_1) {
  char *str1 = s21_strerror(200);
  char *str2 = strerror(200);
  ck_assert_pstr_eq(str1, str2);
}
// 11
START_TEST(tests_strlen) {
  char wich_length1[] = "Boys";
  char wich_length2[] = "1234567890";
  char wich_length3[] = "";
  char wich_length4[] = "\0";
  char wich_length5[] = "!";
  char wich_length6[] = "I hate doing tests, it's not funny at all!!!";
  char wich_length7[] = "\n\n\n";
  char wich_length8[] = "wtf \0 wtf";
  char wich_length9[] = "\0test";
  char wich_length10[] = "        Bless you   \0    .....";
  ck_assert_int_eq(strlen(wich_length1), s21_strlen(wich_length1));
  ck_assert_int_eq(strlen(wich_length2), s21_strlen(wich_length2));
  ck_assert_int_eq(strlen(wich_length3), s21_strlen(wich_length3));
  ck_assert_int_eq(strlen(wich_length4), s21_strlen(wich_length4));
  ck_assert_int_eq(strlen(wich_length5), s21_strlen(wich_length5));
  ck_assert_int_eq(strlen(wich_length6), s21_strlen(wich_length6));
  ck_assert_int_eq(strlen(wich_length7), s21_strlen(wich_length7));
  ck_assert_int_eq(strlen(wich_length8), s21_strlen(wich_length8));
  ck_assert_int_eq(strlen(wich_length9), s21_strlen(wich_length9));
  ck_assert_int_eq(strlen(wich_length10), s21_strlen(wich_length10));
}
END_TEST
// 12
START_TEST(tests_strpbrk) {
  char str1 = "Wow! This is horosho";
  char str11 = "!";
  char str77 = "";
  ck_assert_pstr_eq(strpbrk(str1, str11), s21_strpbrk(str1, str11));
  // проверка на наличие одного символа
  char str22 = "is";
  ck_assert_pstr_eq(strpbrk(str1, str22), s21_strpbrk(str1, str22));
  // проверка на наличие одного символа из множества символов
  char str33 = "o";
  ck_assert_pstr_eq(strpbrk(str1, str33), s21_strpbrk(str1, str33));
  // проверка на наличие несколько символов в строке
  char str44 = "k";
  ck_assert_pstr_eq(strpbrk(str1, str44), s21_strpbrk(str1, str44));
  // нет искомого символа в строке
  char str55 = "ky";
  ck_assert_pstr_eq(strpbrk(str1, str55), s21_strpbrk(str1, str55));
  // нет искомых символов в строке
  char str6 = "";
  char str66 = "";
  ck_assert_pstr_eq(strpbrk(str6, str33), s21_strpbrk(str6, str33));
  // поиск символа в пустой строке
  ck_assert_pstr_eq(strpbrk(str1, str77), s21_strpbrk(str1, str77));
  // пустое множество символов
  ck_assert_pstr_eq(strpbrk(str6, str66), s21_strpbrk(str6, str66));
  // 2 строки пустые
}
END_TEST
// 13
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
// 14
START_TEST(tests_strstr) {
  char str1[] = "Oh Oh Oh!";
  char str11[] = "Oh Oh Oh!";
  ck_assert_pstr_eq(strst(str1, str11), s21_strstr(str1, str11));
  //сравнить 2 одинаковые строки
  char str2[] = "";
  char str22[] = "";
  ck_assert_pstr_eq(strstr(str2, str22), s21_strstr(str2, str22));
  // сравнивать 2 пустые строки
  ck_assert_pstr_eq(strst(str2, str11), s21_strstr(str2, str11));
  // первая строка пуста
    ck_assert_pstr_eq(strst(str1, str11), s21_strstr(str1, str11));
  // вторая строка пуста
  char str33[] = "Ohh my god!";
  ck_assert_pstr_eq(strst(str1, str33), s21_strstr(str1, str33));
  // строка 2 совпадает неполностью со строкой 1
  char str44[] = "h";
  ck_assert_pstr_eq(strst(str1, str44), s21_strstr(str1, str44));
  // найти, имеющийся символ в строке
  char str55[] = "x";
  ck_assert_pstr_eq(strst(str1, str55), s21_strstr(str1, str55));
  // поиск несуществующего символа в строке
  char str66[] = "Oh";
  ck_assert_pstr_eq(strst(str1, str66), s21_strstr(str1, str66));
  // найти первое вхождение слова, которое встречается не 1 раз
  char str77[] = "\0";
  ck_assert_pstr_eq(strst(str1, str77), s21_strstr(str1, str77));
  // найти символ конца строки
}
END_TEST
// 15
START_TEST(tests_strtok) {
  char str1[] = "This is/my function";
  char str11[] = "This is/my function";
  char tok1[] = "/";
  ck_assert_pstr_eq(strtok(str1, tok1), s21_strtok(str11, tok1));
  // один разделитель
  char str2[] = "";
  char str22[] = "";
  char tok2[] = "";
  ck_assert_pstr_eq(strtok(str2, tok2), s21_strtok(str22, tok2));
  // все строки пустые
  char str3[] = "This is";
  char str33[] = "This is";
  char tok3[] = "\0";
  ck_assert_pstr_eq(strtok(str3, tok3), s21_strtok(str33, tok3));
  // разделитель равен концу строки "\0"
  char str4[] = "This is";
  char str44[] = "This is";
  char tok4[] = "";
  ck_assert_pstr_eq(strtok(str4, tok4), s21_strtok(str44, tok4));
  // разделитель пустой
  char str5[] = S21_NULL;
  char str55[] = S21_NULL;
  char tok5[] = "is";
  ck_assert_pstr_eq(strtok(str5, tok5), s21_strtok(str55, tok5));
  // строки нулы
  char str6[] = "wow-wow-wow";
  char str66[] = "wow-wow-wow";
  char tok6[] = "-";
  strtok(str6, tok6);
  strtok(NULL, tok6);
  s21_strtok(str66, tok6);
  s21_strtok(NULL, tok6);
  ck_assert_pstr_eq(str6, str66);
  // несколько одинаковых разделителей (цикл)
  char str7[] = "wow-wow!wow";
  char str77[] = "wow-wow!wow";
  char tok7[] = "-!";
  strtok(str7, tok7);
  strtok(NULL, tok7);
  s21_strtok(str77, tok7);
  s21_strtok(NULL, tok7);
  ck_assert_pstr_eq(str7, str77);
  // несколько разных разделителей (цикл)
  char str8[] = "wow-wow-wow";
  char str88[] = "wow-wow-wow";
  char tok8[] = "!sl/";
  strtok(str8, tok8);
  s21_strtok(str88, tok8);
  ck_assert_pstr_eq(str8, str88);
  // нет не одного разделителя
}
END_TEST
// void split_str_on_tokens(str0, str00, tok0) {
//   char *begin_str0 = strtok(str0, tok0);
//   char *begin_str00 = strtok(str00, tok0);
//   while (begin_str0 != S21_NULL && begin_str00 != S21_NULL) {
//     begin_str0 = strtok(S21_NULL, tok0);
//     begin_str00 = strtok(S21_NULL, tok0);
//     ck_assert_pstr_eq(begin_str0, begin_str00);
//   }
// }




Suite *test_memchr(void) {
  Suite *s = suite_create("\033[45m-=S21_MEMCHR=-\033[0m");
  TCase *tc = tcase_create("memchr_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, tests_memchr);
  tcase_add_test(tc, tests_memcmp);
  tcase_add_test(tc, tests_memcpy);
  tcase_add_test(tc, tests_memset);
  tcase_add_test(tc, tests_strncat);
  tcase_add_test(tc, tests_strchr);
  tcase_add_test(tc, tests_strncmp);
  tcase_add_test(tc, tests_strncpy);
  tcase_add_test(tc, tests_strspn);
  tcase_add_test(tc, tests_strlen);
  tcase_add_test(tc, tests_strpbrk);
  tcase_add_test(tc, tests_strrchr);
  tcase_add_test(tc, tests_strstr);
  tcase_add_test(tc, tests_strtok);
  suite_add_tcase(s, tc);
  return s;
}
