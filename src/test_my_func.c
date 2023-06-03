#include <stdio.h>

#include "s21_string.h"

int main() {
  char bas[200];
  s21_sprintf(bas, "%.2s %c % 5.*hd %5u %% %011f %*d %hd %ld %g %G %.4e %E",
                    "one",'8', 3,4, 11, +12.1, -2,3, 3276999, 21474836479, 13.43056, 14.123456, 15.123456, 16.123456);
  printf("pice of shit = \"%s\"\n", bas);
  sprintf(bas, "%.2s %c % 5.*hd %5u %% %011f %*d %hd %ld %g %G %.4e %E",
                 "one",'8', 3,4, 11, +12.1, -2,3, 3276999, 21474836479, 13.43056, 14.123456, 15.123456, 16.123456);
  printf("origin       = \"%s\"\n", bas);
  return 0;
}