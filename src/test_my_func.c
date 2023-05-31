#include <stdio.h>

#include "s21_string.h"

int main() {
  char bas[200];
  s21_sprintf(bas, "%-5s %1c %-5.3hd %5u %% %+11f %.16f %hd %ld %g %G", "one",
              '8', -1, 11, +12.1, 13.1, 3276999, 21474836479, 14.123456,
              15.123456);
  printf("pice of shit = \"%s\"\n", bas);
  sprintf(bas, "%-5s %1c %-5.3hd %5u %% %+11f %.16f %hd %ld %g %G", "one", '8',
          -1, 11, +12.1, 13.1, 3276999, 21474836479, 14.12345, 15.12345);
  printf("origin       = \"%s\"\n", bas);
  return 0;
}