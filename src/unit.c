#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_d) {
  char str1[1024] = "";
  char str2[1024] = "";
  int val = 14;
  char *str3 =
      "%d , % d, %-d, %+d, %#d, %0d, %6d,    %*d, %.3d,  %.*d, %hd, %ld, %Ld = "
      "%-.3hd + %+.*ld";
  int res1 = s21_sprintf(str1, str3, val, val, val, val, val, val, val, -8, val,
                         val, -10, val, val, val, val, val, -12, val);
  int res2 = sprintf(str2, str3, val, val, val, val, val, val, val, -8, val,
                     val, -10, val, val, val, val, val, -12, val);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_c) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 =
      "%c , % c, %-c, %+c, %#c, %0c, %4c,    %*c, %.3c,  %.*c, %hc, %lc, %Lc = "
      "%-.3hc + %+.*lc";
  char val = 'N';
  int res1 = s21_sprintf(str1, str3, val, val, val, val, val, val, val, -8, val,
                         val, -10, val, val, val, val, val, -12, val);
  int res2 = sprintf(str2, str3, val, val, val, val, val, val, val, -8, val,
                     val, -10, val, val, val, val, val, -12, val);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_f) {
  char str1[1024] = "";
  char str2[1024] = "";

  char *flags[100];
  long double str3[100];
  double str4[100];
  flags[0] = "%f";
  flags[1] = "% f";
  flags[2] = "%-f";
  flags[3] = "%+f";
  flags[4] = "%#f";
  flags[5] = "%0f";
  flags[6] = "%6f";
  flags[7] = "%.4f";
  flags[8] = "%hf";
  flags[9] = "%lf";
  flags[10] = "%Lf";

  // flags[9] = "%.*f";
  // flags[7] = "%*f";
  str3[0] = 1.0;

  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j < 1; j++) {
      ck_assert_int_eq(sprintf(str1, flags[i], str3[j]),
                       s21_sprintf(str2, flags[i], str3[j]));
      // sprintf(str1, flags[i],str3[j]);
      // s21_sprintf(str2, flags[i], str3[j]);
      // int n = s21_sprintf(str2, "%Lf",str3[0]);
      // printf("%s = %s\n",str1,str2);
      // ck_assert_int_eq(b, n);
      ck_assert_pstr_eq(str1, str2);
    }
  }
}
END_TEST

START_TEST(test_s) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 =
      "%s    , % s     , %-s    ,  %+s   , %#s    ,  %10s     ,  %-14s   ,     "
      "     %*s, %.3s     ,      %.*s  , %Ls = %-.3hs + %+.*s";
  // wchar_t *s = L"Hi";
  // char val1[6] = "Nurlan";
  // long double val2 = 0.123;
  int res1 = s21_sprintf(str1, str3, "N", "Nu", "Nur", "Nurl", "Nurla",
                         "Nurlan", "Nurlan ", -8, "Nurlan", "Nurlan", 0,
                         "Nurlan", "Nurlan", "Nurlan", 12, "Nurlan");
  int res2 = sprintf(str2, str3, "N", "Nu", "Nur", "Nurl", "Nurla", "Nurlan",
                     "Nurlan ", -8, "Nurlan", "Nurlan", 0, "Nurlan", "Nurlan",
                     "Nurlan", 12, "Nurlan");
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_u) {
  char str1[1024] = "";
  char str2[1024] = "";
  double val1 = 12;
  long double val2 = -11;
  double val3 = -0.000003;
  char *str3 = "%d, % d, %-d, %+d, %#d , %0d,  %4d,      %*d, %.3d,      %.*d";
  int res1 =
      s21_sprintf(str1, str3, 12, 12, 12, 12, 12, 12, 12, -8, 12, 12, -14, 12);
  int res2 =
      sprintf(str2, str3, 12, 12, 12, 12, 12, 12, 12, -8, 12, 12, -14, 12);
  ck_assert_int_eq(res1, res2);
  // printf("[%s]\n", str1);
  // printf("[%s]\n", str2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_1_signed) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %d Test";
  int val = -12;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three signed parameters
START_TEST(sprintf_2_signed) {
  char str1[100];
  char str2[100];
  char *str3 = "%d Test %d Test %d";
  int val = 012;
  int val2 = -017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_3_signed) {
  char str1[100];
  char str2[100];
  char *str3 = "%d Test %d Test %d";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_4_signed) {
  char str1[100];
  char str2[100];
  char *str3 = "%ld Test %ld Test %hd GOD %hd";
  long int val = 3088675747373646;
  long val2 = 33030030303;
  short int val3 = 22600;
  short val4 = -120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_5_signed) {
  char str1[100];
  char str2[100];
  char *str3 = "%3d Test %5d Test %10d";
  int val = -3015;
  int val2 = -11234;
  int val3 = -99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_6_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5d Test %.23d Test %3.d TEST %.d %.6d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -38;
  int val5 = -100;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_7_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5d Test %-.8d Test %-7d TEST %-.d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zeroes
START_TEST(sprintf_8_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%0d Test %0.d Test %0.0d TEST %0d GOD %.d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  int val5 = -0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Pluses
START_TEST(sprintf_9_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%+d Test %+3.d Test %+5.7d TEST %+10d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zero vals
START_TEST(sprintf_10_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%d Test %3.d Test %5.7d TEST %10d %#d %-d %+d %.d % .d";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val,
                  val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_11_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "% d Test % 3.d Test % 5.7d TEST % 10d GOD %.d";
  int val = -32;
  int val2 = -8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Plus
START_TEST(sprintf_12_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%+d Test %+3.d Test %+5.7d TEST %+10d GOD %+.d";
  int val = -32;
  int val2 = -8899;
  int val3 = 91918;
  int val4 = -32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Hash
START_TEST(sprintf_13_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%#d Test %#3d Test %#5.7d TEST %#.7d Oof %#.d";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = 32311;
  int val5 = -8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_14_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%0d Test %06d Test %05.7d TEST %0.7d Oof %0.d";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Asterisk
START_TEST(sprintf_15_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%*d Test %-*d Test %*.*d TEST %.*d";
  int val = 32;
  int val2 = 8899;
  int val3 = -919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Simple extra test
START_TEST(sprintf_16_signed) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%d";
  int val = 12;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_17_signed) {
  char str1[1024] = "";
  char str2[1024] = "";
  int val = -75;
  sprintf(str1, "Hello %d %023d", val, val);  // нет нулей перед числом(бонус)
  s21_sprintf(str2, "Hello %d %023d", val, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_signed) {
  char str1[300];
  char str2[300];
  char *str3 = "%ld Test %ld Test %hd GOD %hd tt %d tt %d";
  long int val = LONG_MAX;
  long val2 = LONG_MIN;
  short int val3 = SHRT_MAX;
  short val4 = SHRT_MIN;
  int val5 = INT_MAX;
  int val6 = INT_MIN;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5, val6),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%- d Test %- 15d sdasda %- 15d sdsad %- d";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
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
  tcase_add_test(tcase, sprintf_1_signed);
  tcase_add_test(tcase, sprintf_2_signed);
  tcase_add_test(tcase, sprintf_3_signed);
  tcase_add_test(tcase, sprintf_4_signed);
  tcase_add_test(tcase, sprintf_5_signed);
  tcase_add_test(tcase, sprintf_6_signed);
  tcase_add_test(tcase, sprintf_7_signed);
  tcase_add_test(tcase, sprintf_8_signed);
  tcase_add_test(tcase, sprintf_9_signed);
  tcase_add_test(tcase, sprintf_10_signed);
  tcase_add_test(tcase, sprintf_11_signed);
  tcase_add_test(tcase, sprintf_12_signed);
  tcase_add_test(tcase, sprintf_13_signed);
  tcase_add_test(tcase, sprintf_14_signed);
  tcase_add_test(tcase, sprintf_15_signed);
  tcase_add_test(tcase, sprintf_16_signed);
  tcase_add_test(tcase, sprintf_17_signed);
  tcase_add_test(tcase, sprintf_18_signed);
  tcase_add_test(tcase, sprintf_19_signed);

  srunner_run_all(srunner, CK_NORMAL);
  val = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  return val == 0 ? 0 : 1;
}
