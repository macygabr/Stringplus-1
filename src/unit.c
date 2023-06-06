#include <check.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "s21_string.h"

START_TEST(test_d) {
  char str1[1024] = "";
  char str2[1024] = "";
            char *str3 = "%d , % d, %-d, %+d, %#d, %0d, %6d,    %*d, %.3d,  %.*d, %hd, %ld, %Ld = %-.3hd + %+.*ld";
  int val = 14;
  s21_sprintf(str1, str3, val, val, val, val, val, val, val, -8, val, val, 4, val, val, val, val, val, -12, val);
      sprintf(str2, str3, val, val, val, val, val, val, val, -8, val, val, 4, val, val, val, val, val, -12, val);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_c) {
  char str1[1024] = "";
  char str2[1024] = "";
            char *str3 = "%c , % c, %-c, %+c, %#c, %0c, %4c,    %*c, %.3c,  %.*c, %hc, %lc, %Lc =  %-.3hc + %+.*lc";
  char val = 'N';
  s21_sprintf(str1, str3, val, val, val, val, val, val, val, -8, val, val, -4, val, val, val, val);
      sprintf(str2, str3, val, val, val, val, val, val, val, -8, val, val, -4, val, val, val, val);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_f) {
  char str1[1024] = "";
  char str2[1024] = "";
            char *str3 = " %.*f";
  double val = -12.3456789;
  s21_sprintf(str1, str3,  -8, val);
      sprintf(str2, str3,  -8, val);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

int main(void) {
  Suite *suite = suite_create("UNITS");
  TCase *tcase = tcase_create("TESTS");
  SRunner *srunner = srunner_create(suite);
  int val = 0;

  suite_add_tcase(suite, tcase);
  tcase_add_test(tcase, test_d);
  tcase_add_test(tcase, test_c);
  tcase_add_test(tcase, test_f);

  srunner_run_all(srunner, CK_NORMAL);
  val = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  return val == 0 ? 0 : 1;
}

