#include "test_s21_string.h"
#include "../s21_string.h"

START_TEST(test_d) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *flags[100];
  int str3[100];
  int str4[100];
  flags[0] = "N%d";
  flags[1] = "Nu% d";
  flags[2] = "Nur%-d";
  flags[3] = "Nurl%+d";
  flags[4] = "Nurla%#d";
  flags[5] = "Nurlan%0d";
  flags[6] = "Nurlan %6d";
  flags[7] = "Nurlan %.4d ";
  flags[8] = "Nurlan %hd T";
  flags[9] = "Nurlan %ld Tu";
  flags[10] = "Nurlan %.*d Tur";
  flags[11] = "Nurlan %*d Turs";

  str3[0] = 1;
  str3[1] = 123.4567;
  str3[2] = 1234567;
  str3[3] = -1234567;
  str3[4] = 0;

  str4[0] = 12;
  str4[1] = -12;
  str4[2] = 0;
  str4[3] = 1;
  str4[4] = -1;

  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j <= 4; j++) {
      ck_assert_int_eq(sprintf(str1, flags[i], str3[j]),
                   s21_sprintf(str2, flags[i], str3[j]));
      ck_assert_pstr_eq(str1, str2);
    }
  }
  for (int i = 10; i <= 11; i++) 
    for (int j = 0; j <= 4; j++) 
          for(int k =0; k<=4; k++){
      ck_assert_int_eq(sprintf(str1, flags[i], str4[k], str3[j]),
                   s21_sprintf(str2, flags[i], str4[k], str3[j]));
      ck_assert_pstr_eq(str1, str2);
    }
}
END_TEST

START_TEST(test_c) {
    char str1[1024] = "";
  char str2[1024] = "";
  char *flags[100];
  char str3[100];
  int str4[100];
  flags[0] = "N%c";
  flags[1] = "Nu% c";
  flags[2] = "Nur%-c";
  flags[3] = "Nurl%+c";
  flags[4] = "Nurla%#c";
  flags[5] = "Nurlan%0c";
  flags[6] = "Nurlan %6c";
  flags[7] = "Nurlan %.4c ";
  flags[8] = "Nurlan %hc T";
  flags[9] = "Nurlan %lc Tu";
  flags[10] = "Nurlan %.*c Tur";
  flags[11] = "Nurlan %*c Turs";

  str3[0] = 'b';
  str3[1] = 'b';
  str3[2] = 'b';
  str3[3] = 'b';
  str3[4] = 'b';

  str4[0] = 12;
  str4[1] = -12;
  str4[2] = 0;
  str4[3] = 1;
  str4[4] = -1;

  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j <= 4; j++) {
      ck_assert_int_eq(sprintf(str1, flags[i], str3[j]),
                   s21_sprintf(str2, flags[i], str3[j]));
      ck_assert_pstr_eq(str1, str2);
    }
  }
  for (int i = 10; i <= 11; i++) 
    for (int j = 0; j <= 4; j++) 
          for(int k =0; k<=4; k++){
      ck_assert_int_eq(sprintf(str1, flags[i], str4[k], str3[j]),
                   s21_sprintf(str2, flags[i], str4[k], str3[j]));
      ck_assert_pstr_eq(str1, str2);
    }
}
END_TEST

START_TEST(test_f) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *flags[100];
  double str3[100];
  int str4[100];
  flags[0] = "N%f";
  flags[1] = "Nu% f";
  flags[2] = "Nur%-f";
  flags[3] = "Nurl%+f";
  flags[4] = "Nurla%#f";
  flags[5] = "Nurlan%0f";
  flags[6] = "Nurlan %6f";
  flags[7] = "Nurlan %.4f ";
  flags[8] = "Nurlan %hf T";
  flags[9] = "Nurlan %lf Tu";

  flags[10] = "Nurlan %.*f Tur";
  flags[11] = "Nurlan %*f Turs";
  flags[12] = "Nurlan %Lf Turs";

  str3[0] = 1.0;
  str3[1] = 123.4567;
  str3[2] = 0.1234567;
  str3[3] = -123.4567;
  str3[4] = -0.1234567;

  str4[0] = 12;
  str4[1] = -12;
  str4[2] = 0;
  str4[3] = 1;
  str4[4] = -1;
  long double long_double = 0.1234567;
  for (int i = 0; i <= 9; i++)
    for (int j = 0; j <= 4; j++) {
      ck_assert_int_eq(sprintf(str1, flags[i], str3[j]),
                   s21_sprintf(str2, flags[i], str3[j]));
      ck_assert_pstr_eq(str1, str2);
    }

for(int i = 10; i<=11; i++)
  for (int j = 0; j <= 4; j++) 
        for(int k =0; k<=4; k++){
      ck_assert_int_eq(sprintf(str1, flags[i], str4[k], str3[j]),
                   s21_sprintf(str2, flags[i], str4[k], str3[j]));
      ck_assert_pstr_eq(str1, str2);
    }

  ck_assert_int_eq(sprintf(str1, flags[12], long_double),
                   s21_sprintf(str2, flags[12], long_double));
      ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *flags[100];
  char* str3[100];
  int str4[100];
  flags[0] = "N%s";
  flags[1] = "Nu% s";
  flags[2] = "Nur%-s";
  flags[3] = "Nurl%+s";
  flags[4] = "Nurla%#s";
  flags[5] = "Nurlan%0s";
  flags[6] = "Nurlan %6s";
  flags[7] = "Nurlan %.4s ";
  flags[8] = "Nurlan %hs T";
  flags[9] = "Nurlan %ls Tu";

  flags[10] = "Nurlan %.*s Tur";
  flags[11] = "Nurlan %*s Turs";

  str3[0] = "be";
  str3[1] = "bes";
  str3[2] = "best";
  str3[3] = "TrEyEqO";
  str3[4] = "14356Ty";

  str4[0] = 12;
  str4[1] = -12;
  str4[2] = 0;
  str4[3] = 1;
  str4[4] = -1;

  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j <= 2; j++) {
      ck_assert_int_eq(sprintf(str1, flags[i], str3[j]),
                   s21_sprintf(str2, flags[i], str3[j]));
      ck_assert_pstr_eq(str1, str2);
    }
  }
for(int i = 10; i<=10; i++)
  for (int j = 0; j <= 0; j++) 
        for(int k =0; k<=1; k++){
      ck_assert_int_eq(sprintf(str1, flags[i], str4[k], str3[j]),
                   s21_sprintf(str2, flags[i], str4[k], str3[j]));
      ck_assert_pstr_eq(str1, str2);
    }
}
END_TEST

START_TEST(test_u) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *flags[100];
  int str3[100];
  int str4[100];
  flags[0] = "N%u";
  flags[1] = "Nu% u";
  flags[2] = "Nur%-u";
  flags[3] = "Nurl%+u";
  flags[4] = "Nurla%#u";
  flags[5] = "Nurlan%0u";
  flags[6] = "Nurlan %6u";
  flags[7] = "Nurlan %.4u ";
  flags[8] = "Nurlan %hu T";
  flags[9] = "Nurlan %lu Tu";
  flags[10] = "Nurlan %.*u Tur";
  flags[11] = "Nurlan %*u Turs";

  str3[0] = 1;
  str3[1] = 123.4567;
  str3[2] = 1234567;
  str3[3] = -1234567;
  str3[4] = 0;

  str4[0] = 12;
  str4[1] = -12;
  str4[2] = 0;
  str4[3] = 1;
  str4[4] = -1;

  for (int i = 0; i <= 9; i++) 
    for (int j = 0; j <= 4; j++) {
      ck_assert_int_eq(sprintf(str1, flags[i], str3[j]),
                   s21_sprintf(str2, flags[i], str3[j]));
      ck_assert_pstr_eq(str1, str2);
    }

  for (int i = 10; i <= 11; i++) 
    for (int j = 0; j <= 4; j++) 
          for(int k =0; k<=4; k++){
      ck_assert_int_eq(sprintf(str1, flags[i], str4[k], str3[j]),
                   s21_sprintf(str2, flags[i], str4[k], str3[j]));
      ck_assert_pstr_eq(str1, str2);
    }
}
END_TEST

START_TEST(test_g) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *flags[100];
  double str3[100];
  int str4[100];
  flags[0] = "N%g";
  flags[1] = "Nu% g";
  flags[2] = "Nur%-g";
  flags[3] = "Nurl%+g";
  flags[4] = "Nurla%#g";
  flags[5] = "Nurlan%0g";
  flags[6] = "Nurlan %6g";
  flags[7] = "Nurlan %.4g ";
  flags[8] = "Nurlan %hg T";
  flags[9] = "Nurlan %lg Tu";
  flags[10] = "Nurlan %.*g Tur";
  flags[11] = "Nurlan %*g Turs";

  str3[0] = 1.0;
  str3[1] = 123.4567;
  str3[2] = 1234567;
  str3[3] = -1234567;
  str3[4] = 0;

  str4[0] = 12;
  str4[1] = -12;
  str4[2] = 0;
  str4[3] = 1;
  str4[4] = -1;

  for (int i = 0; i <= 9; i++) 
    for (int j = 0; j <= 4; j++) {
            sprintf(str1, flags[i], str3[j]);
      s21_sprintf(str2, flags[i], str3[j]);
      printf("[%s] =[%s], %s, %f\n",str1,str2, flags[i], str3[j]);
      // ck_assert_int_eq(sprintf(str1, flags[i], str3[j]),
      //              s21_sprintf(str2, flags[i], str3[j]));
      // ck_assert_pstr_eq(str1, str2);
    }

  for (int i = 10; i <= 11; i++) 
    for (int j = 0; j <= 4; j++) 
          for(int k =0; k<=4; k++){
      // ck_assert_int_eq(sprintf(str1, flags[i], str4[k], str3[j]),
      //              s21_sprintf(str2, flags[i], str4[k], str3[j]));
      // ck_assert_pstr_eq(str1, str2);
    }
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
  tcase_add_test(tcase, test_s);
  tcase_add_test(tcase, test_u);
  tcase_add_test(tcase, test_g);

 srunner_run_all(srunner, CK_NORMAL);
  val = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  return val == 0 ? 0 : 1;
}

