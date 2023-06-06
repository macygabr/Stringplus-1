#include <stdio.h>
#include "s21_string.h"

int main() {
  char bas[200];
  int val = 72;
  int *ptr = &val;
  s21_sprintf(bas, "%5.2s %c % 5.*hd %5u %% %011f %*d %hd %ld %g %.5G %e %E %x %X %o %p",
                    "one",'8', 3,4, 11, +12.1, -2,3, 3276999, 21474836479, 13.43056, 14.1234, 0.00123456, 16.123456, 40563, -14067, -16, (void*)ptr);
  printf("pice of shit = \"%s\"\n", bas);
  sprintf(bas, "%5.2s %c % 5.*hd %5u %% %011f %*d %hd %ld %g %.5G %e %E %x %X %o %p",
                 "one",'8', 3,4, 11, +12.1, -2,3, 3276999, 21474836479, 13.43056, 14.1234, 0.00123456, 16.123456, 40563, -14067, -16, (void*)ptr);
  printf("origin       = \"%s\"\n", bas);
  return 0;
}