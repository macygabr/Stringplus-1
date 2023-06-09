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

START_TEST(sprintf_1_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = 76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%25.18g TEST\n%.6g TEST\n";
  double num = 838.65400000;
  double num1 = 640.783289182;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%.2g TEST\n%.3g TEST\n";
  double num = 838.65400000;
  double num1 = 640.783289182;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %#5.10g!";
  double num = 0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %#5.10g!";
  double num = -0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = 573429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.0g TEST %4.2g TEST %4.g TEST %5.10g!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_g) {
  char str1[200];
  char str2[200];
  char *str3 = "test: %15.1g\ntest: %16.2g\ntest: %18.3g!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_g) {
  char str1[200];
  char str2[200];
  char *str3 = "test: %10.4g\ntest: %25.5g!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-#15.g\ntest: %-26.1g\ntest: %-18.0g!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %#-10.g\ntest: %-+25.g!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%6g TEST %.2g TEST %4.5g TEST %4.3g TEST %5.10g!";
  double num = -0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = 573429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lg\n%.Lg!";
  long double num_long = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num_long, num_long),
                   s21_sprintf(str2, str3, num_long, num_long));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%20.10g\n%20.15g\n%-20.5g!";
  double num = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lg\n%.Lg\n%+-#Lg\n%+#.Lg\n%-#.Lg!";
  long double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13g!\ntest: %26.15g!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7g!\ntest: %10.15g!\ntest: %25.15g!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13g!\ntest: %26.15g!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_21_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7g!\ntest: %10.15g!\ntest: %25.15g!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_22_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %020g!\ntest: %-020g!\ntest: %+025g!";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_23_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-+ 025.5g!\ntest: %- 020.4g!";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_24_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %020g!\ntest: %-020g!\ntest: %+025g!";
  double num = -837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_25_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-+ 025.5g!\ntest: %- 020.4g!";
  double num = -837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_26_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %015g!\ntest: %-026g!\ntest: %+018g!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_27_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+- 010.2g!\ntest: %- 025.7g!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_28_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15.1Lg!\ntest: % -26.15Lg!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_29_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %- 30.15Lg!\ntest: %+ 50.15Lg!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_30_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % +40.15Lg\ntest: % +-25.15Lg!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_31_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15.1Lg!\ntest: % -26.15Lg!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_32_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %- 30.13Lg!\ntest: %+ 50.15Lg!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_33_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % +40.15Lg!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_34_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lg!\ntest: %.2Lg!\ntest: %.3Lg!";
  long double num = 9999.999999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_35_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.6Lg!\ntest: %.Lg!";
  long double num = 9999.999999;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_36_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.g!\ntest: %.2g!\ntest: %.3g!";
  double num = 0;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_37_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.10g!\ntest: %.6g!\ntest: %.g!";
  double num = 0;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_38_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-20.13g!\ntest: %-25.7g!";
  double num = -4353.235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_39_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-.15g!\ntest: %-16g!\ntest: %- 13.5g!";
  double num = -4353.235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_40_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+20.13g!\ntest: %+25.7g!";
  double num = 0.00000235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_41_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+.15g!\ntest: %+16g!\ntest: %+ 13.5g!";
  double num = 0.00000235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_42_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.Lg!\ntest: %.2Lg!\ntest: %.3Lg!";
  long double num = 8236310759735201795485858585858447757573.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_43_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.12Lg!\ntest: %.6Lg!\ntest: %.9Lg!";
  long double num = 8236310759735201795485858585858447757573.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_44_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %Lg!\n";
  long double num = INFINITY;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_45_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %Lg!\ntest: %Lg!\n";
  long double num = NAN;
  long double num1 = 1.;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_1_hex) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %x Test";
  int val = 0x32;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three hex parameters
START_TEST(sprintf_2_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%x Test %x Test %x";
  int val = 0x7a4;
  int val2 = 0x91ba123f;
  int val3 = 0x3123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_3_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%x Test %x Test %x";
  int val = 0x3015;
  int val2 = 0x712;
  int val3 = 0x99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_4_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%lx Test %lx Test %hx GOD %hx";
  long int val = 3088675747373646;
  long val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_5_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%3x Test %5x Test %10x";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_6_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5x Test %.23x Test %3.x TEST %.x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_7_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5x Test %-.8x Test %-7x TEST %-.x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zeroes
START_TEST(sprintf_8_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%0x Test %0.x Test %0.0x TEST %0x GOD %.x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Pluses
START_TEST(sprintf_9_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%+x Test %+3.x Test %+5.7x TEST %+10x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zero vals
START_TEST(sprintf_10_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%x Test %3.x Test %5.7x TEST %10x %#x %-x %+x %.x % .x";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_11_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "% x Test % 3.x Test % 5.7x TEST % 10x GOD %.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Plus
START_TEST(sprintf_12_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%+x Test %+3.x Test %+5.7x TEST %+10x GOD %+.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Hash
START_TEST(sprintf_13_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%#x Test %#3x Test %#5.7x TEST %#.7x Oof %#.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_14_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%0x Test %06x Test %05.7x TEST %0.7x Oof %0.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Asterisk
START_TEST(sprintf_15_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%*x Test %-*x Test %*.*x TEST %.*x";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
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

START_TEST(sprintf_16_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%- x Test %- 15x sdasda %- 15x sdsad %- x";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "fdsdsds %lx";
  long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// One parameter HEX
START_TEST(sprintf_1_HEX) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %X Test";
  int val = 0X32;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three HEX parameters
START_TEST(sprintf_2_HEX) {
  char str1[100];
  char str2[100];
  char *str3 = "%X Test %X Test %X";
  int val = 0X7a4;
  int val2 = 0X9112312f;
  int val3 = 0X3123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_3_HEX) {
  char str1[100];
  char str2[100];
  char *str3 = "%X Test %X Test %X";
  int val = 0X3015;
  int val2 = 0X712;
  int val3 = 0X99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_4_HEX) {
  char str1[100];
  char str2[100];
  char *str3 = "%lX Test %lX Test %hX GOD %hX";
  unsigned long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_5_HEX) {
  char str1[100];
  char str2[100];
  char *str3 = "%3X Test %5X Test %10X";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_6_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5X Test %.23X Test %3.X TEST %.X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_7_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5X Test %-.8X Test %-7X TEST %-.X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zeroes
START_TEST(sprintf_8_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%0X Test %0.X Test %0.0X TEST %0X GOD %.X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Pluses
START_TEST(sprintf_9_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%+X Test %+3.X Test %+5.7X TEST %+10X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zero vals
START_TEST(sprintf_10_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%X Test %3.X Test %5.7X TEST %10X %#X %-X %+X %.X % .X";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_11_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "% X Test % 3.X Test % 5.7X TEST % 10X GOD %.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Plus
START_TEST(sprintf_12_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%+X Test %+3.X Test %+5.7X TEST %+10X GOD %+.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Hash
START_TEST(sprintf_13_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%#X Test %#3X Test %#5.7X TEST %#.7X Oof %#.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_14_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%0X Test %06X Test %05.7X TEST %0.7X Oof %0.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Asterisk
START_TEST(sprintf_15_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%*X Test %-*X Test %*.*X TEST %.*X";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
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

START_TEST(sprintf_16_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%- X Test %- 15X sdasda %- 15X sdsad %- X";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// One parameter signed_i
START_TEST(sprintf_1_signed_i) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %d Test";
  int val = -12;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three signed_i parameters
START_TEST(sprintf_2_signed_i) {
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
START_TEST(sprintf_3_signed_i) {
  char str1[100];
  char str2[100];
  char *str3 = "%i Test %i Test %i";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_4_signed_i) {
  char str1[100];
  char str2[100];
  char *str3 = "%li Test %li Test %hi GOD %hi";
  long int val = 3088675747373646;
  signed long val2 = -125;
  short int val3 = -22600;
  short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_5_signed_i) {
  char str1[100];
  char str2[100];
  char *str3 = "%3i Test %5i Test %10i";
  int val = -3015;
  int val2 = -11234;
  int val3 = -99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_6_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5i Test %.23i Test %3.i TEST %.i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_7_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5i Test %-.8i Test %-7i TEST %-.i";
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
START_TEST(sprintf_8_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%0i Test %0.i Test %0.0i TEST %0i GOD %.i";
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
START_TEST(sprintf_9_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%+i Test %+3.i Test %+5.7i TEST %+10i";
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
START_TEST(sprintf_10_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%i Test %3.i Test %5.7i TEST %10i %#i %-i %+i %.i % .i";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val,
                  val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_11_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "% i Test % 3.i Test % 5.7i TEST % 10i GOD %.i";
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
START_TEST(sprintf_12_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%+i Test %+3.i Test %+5.7i TEST %+10i GOD %+.i";
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
START_TEST(sprintf_13_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%#i Test %#3i Test %#5.7i TEST %#.7i Oof %#.i";
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
START_TEST(sprintf_14_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%0d Test %06i Test %05.7i TEST %0.7i Oof %0.i";
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
START_TEST(sprintf_15_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%*i Test %-*i Test %*.*i TEST %.*i";
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
START_TEST(sprintf_16_signed_i) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%i";
  int val = 12;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%- i Test %- 15i sdasda %- 15i sdsad %- i";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_1_n) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %n Test";
  int valn1 = 0, valn2 = 0;
  ck_assert_int_eq(sprintf(str1, str3, &valn1),
                   s21_sprintf(str2, str3, &valn2));
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(valn1, valn2);
}
END_TEST

START_TEST(sprintf_2_n) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %o T%nest %o%n";
  int val = 012;
  int val2 = 017;
  int valn1 = 0, valn2 = 0, valn3 = 0, valn4 = 0;
  ck_assert_int_eq(sprintf(str1, str3, val, &valn1, val2, &valn3),
                   s21_sprintf(str2, str3, val, &valn2, val2, &valn4));
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(valn1, valn2);
  ck_assert_int_eq(valn3, valn4);
}
END_TEST

// One parameter octal
START_TEST(sprintf_1_octal) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %o Test";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three octal parameters
START_TEST(sprintf_2_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Test %o";
  int val = 012;
  int val2 = 017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_3_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Test %o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_4_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%lo Test %lo Test %ho GOD %ho";
  long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_5_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%3o Test %5o Test %10o";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_6_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5o Test %.23o Test %3.o TEST %.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_7_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5o Test %-.8o Test %-7o TEST %-.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zeroes
START_TEST(sprintf_8_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o Test %0.o Test %0.0o TEST %0o GOD %.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Pluses
START_TEST(sprintf_9_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%+o Test %+3.o Test %+5.7o TEST %+10o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zero vals
START_TEST(sprintf_10_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%o Test %3.o Test %5.7o TEST %10o %#o %-o %+o %.o % .o";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_11_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "% o Test % 3.o Test % 5.7o TEST % 10o GOD %.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Plus
START_TEST(sprintf_12_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%+o Test %+3.o Test %+5.7o TEST %+10o GOD %+.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Hash
START_TEST(sprintf_13_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%#o Test %#3o Test %#5.7o TEST %#.7o Oof %#.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_14_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o Test %06o Test %05.7o TEST %0.7o Oof %0.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Asterisk
START_TEST(sprintf_15_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%*o Test %-*o Test %*.*o TEST %.*o";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
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
START_TEST(sprintf_16_octal) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%o";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%- o Test %- 15o sdasda %- 15o sdsad %- o";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "fdsdsds %lo";
  long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_1_percent) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%%Test %o Test";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_percent) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %o Tes%%%%t %o";
  int val = 012;
  int val2 = 017;
  ck_assert_int_eq(sprintf(str1, str3, val, val2),
                   s21_sprintf(str2, str3, val, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_percent) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Te%%st %o Test %o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
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
 // tcase_add_test(tcase, test_c);
  tcase_add_test(tcase, test_f);
 // tcase_add_test(tcase, test_s);
  tcase_add_test(tcase, test_u);
  // tcase_add_test(tcase, test_g);
//c
//   tcase_add_test(tcase, sprintf_1_c);
//   tcase_add_test(tcase, sprintf_2_c);
//   tcase_add_test(tcase, sprintf_3_c);
//   tcase_add_test(tcase, sprintf_4_c);
//   tcase_add_test(tcase, sprintf_5_c);
//   tcase_add_test(tcase, sprintf_6_c);
//   tcase_add_test(tcase, sprintf_7_c);
//   tcase_add_test(tcase, sprintf_8_c);
//   tcase_add_test(tcase, sprintf_9_c);
//   tcase_add_test(tcase, sprintf_10_c);
//   tcase_add_test(tcase, sprintf_11_c);
//   tcase_add_test(tcase, sprintf_12_c);
//   tcase_add_test(tcase, sprintf_13_c);
//   tcase_add_test(tcase, sprintf_14_c);
//   tcase_add_test(tcase, sprintf_15_c);
//   tcase_add_test(tcase, sprintf_16_c);
//   tcase_add_test(tcase, sprintf_17_c);
//   tcase_add_test(tcase, sprintf_18_c);
//   tcase_add_test(tcase, sprintf_19_c);
// // d
//   tcase_add_test(tcase, sprintf_1_signed);
//   tcase_add_test(tcase, sprintf_2_signed);
//   tcase_add_test(tcase, sprintf_3_signed);
//   tcase_add_test(tcase, sprintf_4_signed);
//   tcase_add_test(tcase, sprintf_5_signed);
//   tcase_add_test(tcase, sprintf_6_signed);
//   tcase_add_test(tcase, sprintf_7_signed);
//   tcase_add_test(tcase, sprintf_8_signed);
//   tcase_add_test(tcase, sprintf_9_signed);
//   tcase_add_test(tcase, sprintf_10_signed);
//   tcase_add_test(tcase, sprintf_11_signed);
//   tcase_add_test(tcase, sprintf_12_signed);
//   tcase_add_test(tcase, sprintf_13_signed);
//   tcase_add_test(tcase, sprintf_14_signed);
//   tcase_add_test(tcase, sprintf_15_signed);
//   tcase_add_test(tcase, sprintf_16_signed);
//   tcase_add_test(tcase, sprintf_17_signed);
//   tcase_add_test(tcase, sprintf_18_signed);
//   tcase_add_test(tcase, sprintf_19_signed);

// //f
//   tcase_add_test(tcase, sprintf_1_f);
//   tcase_add_test(tcase, sprintf_2_f);
//   tcase_add_test(tcase, sprintf_3_f);
//   tcase_add_test(tcase, sprintf_4_f);
//   tcase_add_test(tcase, sprintf_5_f);
//   tcase_add_test(tcase, sprintf_6_f);
//   tcase_add_test(tcase, sprintf_7_f);
//   tcase_add_test(tcase, sprintf_8_f);
//   tcase_add_test(tcase, sprintf_9_f);
//   tcase_add_test(tcase, sprintf_10_f);
//   tcase_add_test(tcase, sprintf_11_f);
//   tcase_add_test(tcase, sprintf_12_f);
//   tcase_add_test(tcase, sprintf_13_f);
//   tcase_add_test(tcase, sprintf_14_f);
//   tcase_add_test(tcase, sprintf_15_f); // 15 степень
//   tcase_add_test(tcase, sprintf_16_f);
//   tcase_add_test(tcase, sprintf_17_f);
//   tcase_add_test(tcase, sprintf_18_f);
//   tcase_add_test(tcase, sprintf_19_f);
//   tcase_add_test(tcase, sprintf_20_f);
//   tcase_add_test(tcase, sprintf_21_f);
//   tcase_add_test(tcase, sprintf_22_f);
//   tcase_add_test(tcase, sprintf_23_f);
//   tcase_add_test(tcase, sprintf_24_f);
//   tcase_add_test(tcase, sprintf_25_f);
//   tcase_add_test(tcase, sprintf_26_f);
//   tcase_add_test(tcase, sprintf_27_f);
//   tcase_add_test(tcase, sprintf_28_f);
//   tcase_add_test(tcase, sprintf_30_f);
//   tcase_add_test(tcase, sprintf_31_f);
//   tcase_add_test(tcase, sprintf_32_f);
//   tcase_add_test(tcase, sprintf_33_f);
//   tcase_add_test(tcase, sprintf_34_f);
//   tcase_add_test(tcase, sprintf_35_f);
//   tcase_add_test(tcase, sprintf_36_f);
//   tcase_add_test(tcase, sprintf_37_f);
//   tcase_add_test(tcase, sprintf_38_f);
//   tcase_add_test(tcase, sprintf_39_f);
//   tcase_add_test(tcase, sprintf_40_f);
  // tcase_add_test(tcase, sprintf_41_f);
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
//// g
  // tcase_add_test(tcase, sprintf_1_g);
  // tcase_add_test(tcase, sprintf_2_g);
  // tcase_add_test(tcase, sprintf_3_g);
  // tcase_add_test(tcase, sprintf_4_g);
  // tcase_add_test(tcase, sprintf_5_g);
  // tcase_add_test(tcase, sprintf_6_g);
  // tcase_add_test(tcase, sprintf_7_g);
  // tcase_add_test(tcase, sprintf_8_g);
  // tcase_add_test(tcase, sprintf_9_g);
  // tcase_add_test(tcase, sprintf_10_g);
  // tcase_add_test(tcase, sprintf_11_g);
  // tcase_add_test(tcase, sprintf_12_g);
  // tcase_add_test(tcase, sprintf_13_g);
  // tcase_add_test(tcase, sprintf_14_g);
  // tcase_add_test(tcase, sprintf_15_g);
  // tcase_add_test(tcase, sprintf_16_g);
  // tcase_add_test(tcase, sprintf_17_g);
  // tcase_add_test(tcase, sprintf_18_g);
  // tcase_add_test(tcase, sprintf_19_g);
  // tcase_add_test(tcase, sprintf_20_g);
  // tcase_add_test(tcase, sprintf_21_g);
  // tcase_add_test(tcase, sprintf_22_g);
  // tcase_add_test(tcase, sprintf_23_g);
  // tcase_add_test(tcase, sprintf_24_g);
  // tcase_add_test(tcase, sprintf_25_g);
  // tcase_add_test(tcase, sprintf_26_g);
  // tcase_add_test(tcase, sprintf_27_g);
  // tcase_add_test(tcase, sprintf_28_g);
  // tcase_add_test(tcase, sprintf_29_g);
  // tcase_add_test(tcase, sprintf_30_g);
  // tcase_add_test(tcase, sprintf_31_g);
  // tcase_add_test(tcase, sprintf_32_g);
  // tcase_add_test(tcase, sprintf_33_g);
  // tcase_add_test(tcase, sprintf_34_g);
  // tcase_add_test(tcase, sprintf_35_g);
  // tcase_add_test(tcase, sprintf_36_g);
  // tcase_add_test(tcase, sprintf_37_g);
  // tcase_add_test(tcase, sprintf_38_g);
  // tcase_add_test(tcase, sprintf_39_g);
  // tcase_add_test(tcase, sprintf_40_g);
  // tcase_add_test(tcase, sprintf_41_g);
  // tcase_add_test(tcase, sprintf_42_g);
  // tcase_add_test(tcase, sprintf_43_g);
  // tcase_add_test(tcase, sprintf_44_g);
  // tcase_add_test(tcase, sprintf_45_g);
////x
  // tcase_add_test(tcase, sprintf_1_hex);
  // tcase_add_test(tcase, sprintf_2_hex);
  // tcase_add_test(tcase, sprintf_3_hex);
  // tcase_add_test(tcase, sprintf_4_hex);
  // tcase_add_test(tcase, sprintf_5_hex);
  // tcase_add_test(tcase, sprintf_6_hex);
  // tcase_add_test(tcase, sprintf_7_hex);
  // tcase_add_test(tcase, sprintf_8_hex);
  // tcase_add_test(tcase, sprintf_9_hex);
  // tcase_add_test(tcase, sprintf_10_hex);
  // tcase_add_test(tcase, sprintf_11_hex);
  // tcase_add_test(tcase, sprintf_12_hex);
  // tcase_add_test(tcase, sprintf_13_hex);
  // tcase_add_test(tcase, sprintf_14_hex);
  // tcase_add_test(tcase, sprintf_15_hex);
  // tcase_add_test(tcase, sprintf_16_hex);
  // tcase_add_test(tcase, sprintf_17_hex);
  // tcase_add_test(tcase, sprintf_1_HEX);
  // tcase_add_test(tcase, sprintf_2_HEX);
  // tcase_add_test(tcase, sprintf_3_HEX);
  // tcase_add_test(tcase, sprintf_4_HEX);
  // tcase_add_test(tcase, sprintf_5_HEX);
  // tcase_add_test(tcase, sprintf_6_HEX);
  // tcase_add_test(tcase, sprintf_7_HEX);
  // tcase_add_test(tcase, sprintf_8_HEX);
  // tcase_add_test(tcase, sprintf_9_HEX);
  // tcase_add_test(tcase, sprintf_10_HEX);
  // tcase_add_test(tcase, sprintf_11_HEX);
  // tcase_add_test(tcase, sprintf_12_HEX);
  // tcase_add_test(tcase, sprintf_13_HEX);
  // tcase_add_test(tcase, sprintf_14_HEX);
  // tcase_add_test(tcase, sprintf_15_HEX);
  // tcase_add_test(tcase, sprintf_16_HEX);
  // tcase_add_test(tcase, sprintf_1_signed_i);
  // tcase_add_test(tcase, sprintf_2_signed_i);
  // tcase_add_test(tcase, sprintf_3_signed_i);
  // tcase_add_test(tcase, sprintf_4_signed_i);
  // tcase_add_test(tcase, sprintf_5_signed_i);
  // tcase_add_test(tcase, sprintf_6_signed_i);
  // tcase_add_test(tcase, sprintf_7_signed_i);
  // tcase_add_test(tcase, sprintf_8_signed_i);
  // tcase_add_test(tcase, sprintf_9_signed_i);
  // tcase_add_test(tcase, sprintf_10_signed_i);
  // tcase_add_test(tcase, sprintf_11_signed_i);
  // tcase_add_test(tcase, sprintf_12_signed_i);
  // tcase_add_test(tcase, sprintf_13_signed_i);
  // tcase_add_test(tcase, sprintf_14_signed_i);
  // tcase_add_test(tcase, sprintf_15_signed_i);
  // tcase_add_test(tcase, sprintf_16_signed_i);
  // tcase_add_test(tcase, sprintf_17_signed_i);
  // tcase_add_test(tcase, sprintf_1_n);
  // tcase_add_test(tcase, sprintf_2_n);
  // tcase_add_test(tcase, sprintf_1_octal);
  // tcase_add_test(tcase, sprintf_2_octal);
  // tcase_add_test(tcase, sprintf_3_octal);
  // tcase_add_test(tcase, sprintf_4_octal);
  // tcase_add_test(tcase, sprintf_5_octal);
  // tcase_add_test(tcase, sprintf_6_octal);
  // tcase_add_test(tcase, sprintf_7_octal);
  // tcase_add_test(tcase, sprintf_8_octal);
  // tcase_add_test(tcase, sprintf_9_octal);
  // tcase_add_test(tcase, sprintf_10_octal);
  // tcase_add_test(tcase, sprintf_11_octal);
  // tcase_add_test(tcase, sprintf_12_octal);
  // tcase_add_test(tcase, sprintf_13_octal);
  // tcase_add_test(tcase, sprintf_14_octal);
  // tcase_add_test(tcase, sprintf_15_octal);
  // tcase_add_test(tcase, sprintf_16_octal);
  // tcase_add_test(tcase, sprintf_17_octal);
  // tcase_add_test(tcase, sprintf_18_octal);
  // tcase_add_test(tcase, sprintf_1_percent);
  // tcase_add_test(tcase, sprintf_2_percent);
  // tcase_add_test(tcase, sprintf_3_percent);
 srunner_run_all(srunner, CK_NORMAL);
  val = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  return val == 0 ? 0 : 1;
}

