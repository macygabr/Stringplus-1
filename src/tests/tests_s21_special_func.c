#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(toUp_0) {
  char str1[] = "abcdefghijklmnopqrstuvwxyz";
  char *str2 = malloc(sizeof(str1));
  str2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *res = s21_to_upper(str1);
  ck_assert_pstr_eq(res, str2);
  free(res);
}
END_TEST

START_TEST(toUp_1) {
  char str1[] = "abcDEFGHIJklmnopqrstuvwxyz";
  char *str2 = malloc(sizeof(str1));
  str2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *res = s21_to_upper(str1);
  ck_assert_pstr_eq(res, str2);
  free(res);
}
END_TEST

START_TEST(toUp_2) {
  char str1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *str2 = malloc(sizeof(str1));
  str2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *res = s21_to_upper(str1);
  ck_assert_pstr_eq(res, str2);
  free(res);
}
END_TEST

START_TEST(toUp_3) {
  char str1[] = "\t123(&@#)";
  char *str2 = malloc(sizeof(str1));
  str2 = "\t123(&@#)";
  char *res = s21_to_upper(str1);
  ck_assert_pstr_eq(res, str2);
  free(res);
}
END_TEST

START_TEST(toUp_4) {
  char *str1 = NULL;
  char *str2 = NULL;
  char *res = s21_to_upper(str1);
  ck_assert_pstr_eq(res, str2);
}
END_TEST
//----------------------------------------------------------------------------------------------------------
START_TEST(toLow_0) {
  char str1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *str2 = malloc(sizeof(str1));
  str2 = "abcdefghijklmnopqrstuvwxyz";
  char *res = s21_to_lower(str1);
  ck_assert_pstr_eq(res, str2);
  free(res);
}
END_TEST

START_TEST(toLow_1) {
  char str1[] = "abcDEFGHIJklmnopqrstuvwxyz";
  char *str2 = malloc(sizeof(str1));
  str2 = "abcdefghijklmnopqrstuvwxyz";
  char *res = s21_to_lower(str1);
  ck_assert_pstr_eq(res, str2);
  free(res);
}
END_TEST

START_TEST(toLow_2) {
  char str1[] = "abcdefghijklmnopqrstuvwxyz";
  char *str2 = malloc(sizeof(str1));
  str2 = "abcdefghijklmnopqrstuvwxyz";
  char *res = s21_to_lower(str1);
  ck_assert_pstr_eq(res, str2);
  free(res);
}
END_TEST

START_TEST(toLow_3) {
  char str1[] = "\t123(&@#)";
  char *str2 = malloc(sizeof(str1));
  str2 = "\t123(&@#)";
  char *res = s21_to_lower(str1);
  ck_assert_pstr_eq(res, str2);
  free(res);
}
END_TEST

START_TEST(toLow_4) {
  char *str1 = NULL;
  char *str2 = NULL;
  char *res = s21_to_lower(str1);
  ck_assert_pstr_eq(res, str2);
}
END_TEST
//----------------------------------------------------------------------------------------------------------
START_TEST(trim_0) {
  char *str1 = NULL;
  char *str2 = NULL;
  char *res1 = s21_trim(str1, str2);
  char *res2 = NULL;
  ck_assert_pstr_eq(res1, res2);
}
END_TEST

START_TEST(trim_1) {
  char str1[] = "   4567   ";
  char *str2 = NULL;
  char *res1 = s21_trim(str1, str2);
  char res2[] = "4567";
  ck_assert_pstr_eq(res1, res2);
}
END_TEST

START_TEST(trim_2) {
  char str1[] = "11223344551";
  char str2[] = "12";
  char *res1 = s21_trim(str1, str2);
  char res2[] = "334455";
  ck_assert_pstr_eq(res1, res2);
}
END_TEST

START_TEST(trim_3) {
  char str1[] = "11223344551";
  char str2[] = "12";
  char *res1 = s21_trim(str2, str1);
  char *res2 = NULL;
  ck_assert_pstr_eq(res1, res2);
}
END_TEST

START_TEST(trim_4) {
  char *str1 = NULL;
  char str2[] = "12";
  char *res1 = s21_trim(str1, str2);
  char *res2 = NULL;
  ck_assert_pstr_eq(res1, res2);
}
END_TEST

START_TEST(trim_5) {
  char str1[] = "12";
  char str2[] = "34";
  char *res1 = s21_trim(str1, str2);
  char res2[] = "12";
  ck_assert_pstr_eq(res1, res2);
}
END_TEST

START_TEST(insert_0) {
  char str1[] = "0123456789";
  char str2[] = "__";
  char *res1 = s21_insert(str1, str2, 0);
  char res2[] = "0123456789__";
  ck_assert_pstr_eq(res1, res2);
}
END_TEST

START_TEST(insert_1) {
  char str1[] = "0123456789";
  char str2[] = "__";
  char *res1 = s21_insert(str1, str2, 20);
  char *res2 = NULL;
  ck_assert_pstr_eq(res1, res2);
}
END_TEST

START_TEST(insert_2) {
  char str1[] = "0123456789";
  char str2[] = "__";
  char *res1 = s21_insert(str1, str2, 1);
  char res2[] = "_0123456789_";
  ck_assert_pstr_eq(res1, res2);
}
END_TEST

START_TEST(insert_3) {
  char str1[] = "0123456789";
  char str2[] = "__";
  char *res1 = s21_insert(str2, str1, 0);
  char res2[] = "__0123456789";
  ck_assert_pstr_eq(res1, res2);
}
END_TEST

START_TEST(insert_4) {
  char str1[] = "0123456789";
  char str2[] = "__";
  char *res1 = s21_insert(str2, str1, 20);
  char *res2 = NULL;
  ck_assert_pstr_eq(res1, res2);
}
END_TEST

START_TEST(insert_5) {
  char str1[] = "0123456789";
  char *res1 = s21_insert(str1, str1, 0);
  char res2[] = "01234567890123456789";
  ck_assert_pstr_eq(res1, res2);
}
END_TEST

START_TEST(insert_6) {
  char str1[] = "0123456789";
  char *str2 = NULL;
  char *res1 = s21_insert(str1, str2, 0);
  char res2[] = "0123456789";
  ck_assert_pstr_eq(res1, res2);
}
END_TEST

START_TEST(insert_7) {
  char str1[] = "0123456789";
  char *str2 = NULL;
  char *res1 = s21_insert(str2, str1, 0);
  char res2[] = "0123456789";
  ck_assert_pstr_eq(res1, res2);
}
END_TEST

START_TEST(insert_8) {
  char str1[] = "0123456789";
  char *str2 = NULL;
  char *res1 = s21_insert(str1, str2, 20);
  char *res2 = NULL;
  ck_assert_pstr_eq(res1, res2);
}
END_TEST

START_TEST(insert_9) {
  char str1[] = "0123456789";
  char *str2 = NULL;
  char *res1 = s21_insert(str2, str1, 20);
  char *res2 = NULL;
  ck_assert_pstr_eq(res1, res2);
}
END_TEST

START_TEST(insert_10) {
  char *str1 = NULL;
  char *str2 = NULL;
  char *res1 = s21_insert(str2, str1, 0);
  char *res2 = NULL;
  ck_assert_pstr_eq(res1, res2);
}
END_TEST

START_TEST(insert_11) {
  char *str1 = NULL;
  char *str2 = NULL;
  char *res1 = s21_insert(str2, str1, 20);
  char *res2 = NULL;
  ck_assert_pstr_eq(res1, res2);
}
END_TEST

// START_TEST(error_0) {
//   char *str1 = s21_strerror(1);
//   char *str2 = strerror(1);
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(error_1) {
//   char *str1 = s21_strerror(200);
//   char *str2 = strerror(200);
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

int main(void) {
  Suite *suite = suite_create("UNITS");
  TCase *tcase = tcase_create("TESTS");
  SRunner *srunner = srunner_create(suite);
  int val = 0;

  suite_add_tcase(suite, tcase);
  tcase_add_test(tcase, toUp_0);
  tcase_add_test(tcase, toUp_1);
  tcase_add_test(tcase, toUp_2);
  tcase_add_test(tcase, toUp_3);
  tcase_add_test(tcase, toUp_4);
  tcase_add_test(tcase, toLow_0);
  tcase_add_test(tcase, toLow_1);
  tcase_add_test(tcase, toLow_2);
  tcase_add_test(tcase, toLow_3);
  tcase_add_test(tcase, toLow_4);
  tcase_add_test(tcase, trim_0);
  tcase_add_test(tcase, trim_1);
  tcase_add_test(tcase, trim_2);
  tcase_add_test(tcase, trim_3);
  tcase_add_test(tcase, trim_4);
  tcase_add_test(tcase, trim_5);
  tcase_add_test(tcase, insert_0);
  tcase_add_test(tcase, insert_1);
  tcase_add_test(tcase, insert_2);
  tcase_add_test(tcase, insert_3);
  tcase_add_test(tcase, insert_4);
  tcase_add_test(tcase, insert_5);
  tcase_add_test(tcase, insert_6);
  tcase_add_test(tcase, insert_7);
  tcase_add_test(tcase, insert_8);
  tcase_add_test(tcase, insert_9);
  tcase_add_test(tcase, insert_10);
  tcase_add_test(tcase, insert_11);
  // tcase_add_test(tcase, error_0);
  // tcase_add_test(tcase, error_1);

  srunner_run_all(srunner, CK_NORMAL);
  val = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  return val == 0 ? 0 : 1;
}
