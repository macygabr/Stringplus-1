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
  str3[1] = 123;
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
            // sprintf(str1, flags[i], str3[j]);
            //        s21_sprintf(str2, flags[i],  str3[j]);
            //        printf("[%s] = [%s] %s %d\n", str1, str2, flags[i], str3[j]);
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
      // sprintf(str1, flags[i],str3[j]);
      //              s21_sprintf(str2, flags[i], str3[j]);
      //     printf("%s\n%s\n", str1, str2);
      ck_assert_int_eq(sprintf(str1, flags[i], str3[j]),
                   s21_sprintf(str2, flags[i], str3[j]));
      ck_assert_pstr_eq(str1, str2);
    }

for(int i = 10; i<=11; i++)
  for (int j = 0; j <= 4; j++) 
        for(int k =0; k<=4; k++){
          // sprintf(str1, flags[i], str4[k], str3[j]);
          //          s21_sprintf(str2, flags[i], str4[k], str3[j]);
          // printf("%s\n%s\n%d %f\n\n", str1, str2, str4[k], str3[j]);
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
      // sprintf(str1, flags[i], str3[j]);
      //  s21_sprintf(str2, flags[i], str3[j]);
      //  printf("[%s] = [%s] %s %s\n",str1, str2,flags[i], str3[j]);
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
      //       sprintf(str1, flags[i], str3[j]);
      // s21_sprintf(str2, flags[i], str3[j]);
      // printf("[%s] =[%s], %s, %f\n",str1,str2, flags[i], str3[j]);
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


START_TEST(sprintf_1_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = 9;
  int b = 10;
  int c = 17;
  int d = 66;
  int e = 124;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = -6;
  int b = -10;
  int c = -17;
  int d = -66;
  int e = -124;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = 60;
  int b = 50;
  int c = 1744;
  int d = 386;
  int e = 257;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = 60;
  int b = 50;
  int c = 1744;
  int d = 386;
  int e = 257;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  char a = 0;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%05c Test % 5c Test %lc Test";
  int a = 70;
  unsigned long int b = 70;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b),
                   s21_sprintf(str2, str3, a, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%-010c Test % -10c Test %-lc";
  int a = 74;
  unsigned long int b = 74;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b),
                   s21_sprintf(str2, str3, a, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%+010.5c Test % +10.5c Test %-10lc Test %-10lc Test %+10lc";
  char a = 92;
  unsigned long int b = 92;
  unsigned long int c = 92;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   s21_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%6.4c Test %-6.4c Test %4.10lc Test %-4.10lc Test %-0lc";
  int a = 10;
  unsigned long int b = 10;
  unsigned long int c = 10;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   s21_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%6.4c Test %-6.4c Test %4.10lc Test %-4.10lc Test %-0lc";
  int a = -10;
  unsigned long int b = 10;
  unsigned long int c = 10;
  
  sprintf(str1, str3, a, a, b, c, c);
  // s21_sprintf(str2, str3, a, a, b, c, c);
  // printf("%s\n%s\n\n", str1,str2);
  
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   s21_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%#c Test %#c Test %#c Test %#c Test %#c";
  ck_assert_int_eq(sprintf(str1, str3, ' ', 'n', '5', '%', '\\'),
                   s21_sprintf(str2, str3, ' ', 'n', '5', '%', '\\'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  ck_assert_int_eq(sprintf(str1, str3, '\n', '\0', '\0', '\0', 'c'),
                   s21_sprintf(str2, str3, '\n', '\0', '\0', '\0', 'c'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  ck_assert_int_eq(sprintf(str1, str3, 'b', '4', '#', '@', '\0'),
                   s21_sprintf(str2, str3, 'b', '4', '#', '@', '\0'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  ck_assert_int_eq(sprintf(str1, str3, 'Y', 'G', 123, '\0', 'J'),
                   s21_sprintf(str2, str3, 'Y', 'G', 123, '\0', 'J'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%.7c Test %-7c Test %-50c Test % 54c Test %0188c";
  int a = 112;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%.7c Test % -.7c Test %- 050c Test %- 54c Test %-0188c";
  int a = 45;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%70c Test %-90c Test %080c Test %-065c Test %- 60c";
  int a = 255;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%70c Test %-90c Test %080c Test %-065c Test %- 60c";
  int a = 255;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_c) {
  char str1[100];
  char str2[100];  //%lc Test %llc Test %hc Test %hhc
  char *str3 = "%c Test %lc Test %hc";
  int a = 3;
  unsigned long int b = 103;
  unsigned short e = 255;
  ck_assert_int_eq(sprintf(str1, str3, a, b, e),
                   s21_sprintf(str2, str3, a, b, e));
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
  char *str3 = "(%d) Test (%3.d) Test (%5.7d) TEST %10d %#d %-d %+d %.d % .d";
  int val = 0;

//  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
//       s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val,
//                   val);
//   printf("[%s]\n[%s]\n\n", str1, str2);

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

START_TEST(sprintf_1_f) {
  char str1[200];
  char str2[200];
  char *str3 = "%f TEST %.f TEST %4f TEST %4.f TEST %5.10f!";
  double num = 76.756589367;
      // sprintf(str1, str3, num, num, num, num, num);
      // s21_sprintf(str2, str3, num, num, num, num, num);
       
      //  printf("[%s] = [%s]\n",str1, str2);
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_f) {
  char str1[200];
  char str2[200];
  char *str3 = "%f TEST %.f TEST %3f TEST %4.f TEST %5.10f!";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_f) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lf\n%.Lf!";
  long double num_long = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num_long, num_long),
                   s21_sprintf(str2, str3, num_long, num_long));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_f) {
  char str1[400];
  char str2[400];
  char *str3 = "%20.10f\n%20.15f\n%-20.5f!";
  double num = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_f) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lf %.Lf %+-#Lf %+#.Lf %-#.Lf!";
  long double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %5f\ntest: %6.1f\ntest: %8.2f!";
  double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %10.5f\ntest: %12.4f!";
  double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.1f\ntest: %16.2f\ntest: %18.3f!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %10.4f\ntest: %25.5f!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+15.f\ntest: %+#16.f\ntest: %+#18.0f!";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 18.0f\ntest: %+10.f\ntest: %+25.f!";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-26.1f\ntest: %-18.0f\ntest: %#-10.f!";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-#15.f\ntest: %-+25.f!";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-15.4f!\ntest: %-26.1f!\ntest: %-18.0f!";
  double num = -365289.3462865487;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %#-10.9f! test: %-+25.12f!";
  double num = -365289.3462865487;

      //   sprintf(str1, str3, num, num);
      // s21_sprintf(str2, str3, num, num);
      //  printf("[%s]\n[%s]\n",str1, str2);
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.12f!\ntest: %26.12f!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7f!\ntest: %10.12f!\ntest: %25.12f!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.11f!\ntest: %26.12f!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7f!\ntest: %10.12f!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %- 23.10f!\ntest: %+ 25.12f!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_21_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15f!\ntest: % -26f!\ntest: %- 18f!";
  double num = -365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_22_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+- 14f!\ntest: %+ 10f!\ntest: % +25f!";
  double num = -365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_23_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 14f!\ntest: % -27f!\ntest: %- 19f!";
  double num = 365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_24_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+- 16f!\ntest: %+ 44f!\ntest: % +35f!";
  double num = 365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_25_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %26Lf! test: %18Lf! test: %60Lf!";
  long double num = -37527658396.34;
  // sprintf(str1, str3, num, num, num);
  //                  s21_sprintf(str2, str3, num, num, num);
  //     printf("[%s]\n[%s]\n\n", str1, str2);
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_26_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15Lf!test: %100Lf!";
  long double num = -37527658396.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_27_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %- 26Lf!\ntest: %+- 18Lf!\ntest: %60Lf!";
  long double num = 37527658396.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_28_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % +15Lf!test: %100Lf!";
  long double num = 37527658396.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_30_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %020f! test: %-020f! test: %+025f!";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_31_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-+ 025.5f! test: %- 020.4f test: %+ 016.6f!";
  double num = 837564.47533;
      //   sprintf(str1, str3, num, num, num);
      //              s21_sprintf(str2, str3, num, num, num);
      // printf("[%s]\n[%s]\n\n", str1, str2);
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_32_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %015f!\ntest: %-026f!\ntest: %+018f!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_33_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+- 010.2f!\ntest: %- 025.7f\ntest: %+- 18.4f!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_34_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15.1Lf!\ntest: % -26.15Lf!\ntest: %- 30.15Lf!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_35_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 50.15Lf!\ntest: % +40.15Lf!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_36_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15.1Lf!\ntest: % -26.13Lf!\ntest: %- 30.8Lf!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_37_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 50.14Lf!\ntest: % +40.14Lf!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_38_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = -9999.99999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_39_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.10Lf!\ntest: %.6Lf!\ntest: %.Lf!";
  long double num = -9999.99999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_40_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf! test: %.2Lf! test: %.3Lf!";
  long double num = 000000000000000.00000000000;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_41_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.6Lf! test: %.1Lf test: %+ 0Lf!!";
  long double num = 000000000000000.00000000000;
    
        sprintf(str1, str3, num, num, num);
                   s21_sprintf(str2, str3, num, num, num);
      printf("[%s]\n[%s]\n\n", str1, str2);

  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_42_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = -635293201236310753.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_43_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 0Lf!\ntest: %.6Lf!\ntest: %.15Lf!";
  long double num = -635293201236310753.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_44_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = -236310753.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_45_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 0Lf!\ntest: %.6Lf!\ntest: %.15Lf!";
  long double num = -236310753.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_46_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = -9325781235683689988.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_47_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 0Lf!\ntest: %.6Lf!\ntest: %.15Lf!";
  long double num = -9325781235683689988.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_48_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = 823631075973858585858447757573.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_49_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 0Lf!\ntest: %.6Lf!\ntest: %.15Lf!";
  long double num = 823631075973858585858447757573.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_50_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %25.5Lf!\ntest: %Lf!\ntest: %-50Lf!";
  long double num = -9325781235683689988.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_51_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 0Lf!\ntest: %060Lf!\ntest: %.15Lf!";
  long double num = -9325781235683689988.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_52_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-+.1Lf!\ntest: %- .2Lf!\ntest: %-0.3Lf!";
  long double num = -0.999999;

    // sprintf(str1, str3, num, num, num);
    //                s21_sprintf(str2, str3, num, num, num);
    //   printf("[%s]\n[%s]\n\n", str1, str2);

  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_54_f) {
  char str1[400];
  char str2[400];
  char *str3 = "fshgkaljck% 10.12f hgsakul";
  double num = 0.235300;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
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
  tcase_add_test(tcase, test_s);
  tcase_add_test(tcase, test_u);
  // tcase_add_test(tcase, test_g);
//c
  tcase_add_test(tcase, sprintf_1_c);
  tcase_add_test(tcase, sprintf_2_c);
  tcase_add_test(tcase, sprintf_3_c);
  tcase_add_test(tcase, sprintf_4_c);
  tcase_add_test(tcase, sprintf_5_c);
  tcase_add_test(tcase, sprintf_6_c);
  tcase_add_test(tcase, sprintf_7_c);
  tcase_add_test(tcase, sprintf_8_c);
  tcase_add_test(tcase, sprintf_9_c);
  tcase_add_test(tcase, sprintf_10_c);
  tcase_add_test(tcase, sprintf_11_c);
  tcase_add_test(tcase, sprintf_12_c);
  tcase_add_test(tcase, sprintf_13_c);
  tcase_add_test(tcase, sprintf_14_c);
  tcase_add_test(tcase, sprintf_15_c);
  tcase_add_test(tcase, sprintf_16_c);
  tcase_add_test(tcase, sprintf_17_c);
  tcase_add_test(tcase, sprintf_18_c);
  tcase_add_test(tcase, sprintf_19_c);
// d
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

//f
  tcase_add_test(tcase, sprintf_1_f);
  tcase_add_test(tcase, sprintf_2_f);
  tcase_add_test(tcase, sprintf_3_f);
  tcase_add_test(tcase, sprintf_4_f);
  tcase_add_test(tcase, sprintf_5_f);
  tcase_add_test(tcase, sprintf_6_f);
  tcase_add_test(tcase, sprintf_7_f);
  tcase_add_test(tcase, sprintf_8_f);
  tcase_add_test(tcase, sprintf_9_f);
  tcase_add_test(tcase, sprintf_10_f);
  tcase_add_test(tcase, sprintf_11_f);
  tcase_add_test(tcase, sprintf_12_f);
  tcase_add_test(tcase, sprintf_13_f);
  tcase_add_test(tcase, sprintf_14_f);
  tcase_add_test(tcase, sprintf_15_f); // 15 степень
  tcase_add_test(tcase, sprintf_16_f);
  tcase_add_test(tcase, sprintf_17_f);
  tcase_add_test(tcase, sprintf_18_f);
  tcase_add_test(tcase, sprintf_19_f);
  tcase_add_test(tcase, sprintf_20_f);
  tcase_add_test(tcase, sprintf_21_f);
  tcase_add_test(tcase, sprintf_22_f);
  tcase_add_test(tcase, sprintf_23_f);
  tcase_add_test(tcase, sprintf_24_f);
  tcase_add_test(tcase, sprintf_25_f);
  tcase_add_test(tcase, sprintf_26_f);
  tcase_add_test(tcase, sprintf_27_f);
  tcase_add_test(tcase, sprintf_28_f);
  tcase_add_test(tcase, sprintf_30_f);
  tcase_add_test(tcase, sprintf_31_f);
  tcase_add_test(tcase, sprintf_32_f);
  tcase_add_test(tcase, sprintf_33_f);
  tcase_add_test(tcase, sprintf_34_f);
  tcase_add_test(tcase, sprintf_35_f);
  tcase_add_test(tcase, sprintf_36_f);
  tcase_add_test(tcase, sprintf_37_f);
  tcase_add_test(tcase, sprintf_38_f);
  tcase_add_test(tcase, sprintf_39_f);
  tcase_add_test(tcase, sprintf_40_f);
  tcase_add_test(tcase, sprintf_41_f);
  // tcase_add_test(tcase, sprintf_42_f);
  // tcase_add_test(tcase, sprintf_43_f);
  // tcase_add_test(tcase, sprintf_44_f);
  // tcase_add_test(tcase, sprintf_45_f);
  // tcase_add_test(tcase, sprintf_46_f);
  // tcase_add_test(tcase, sprintf_47_f);
  // tcase_add_test(tcase, sprintf_48_f);
  // tcase_add_test(tcase, sprintf_49_f);
  // tcase_add_test(tcase, sprintf_50_f);
  // tcase_add_test(tcase, sprintf_51_f);
  // tcase_add_test(tcase, sprintf_52_f);
  // tcase_add_test(tcase, sprintf_54_f);

 srunner_run_all(srunner, CK_NORMAL);
  val = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  return val == 0 ? 0 : 1;
}

