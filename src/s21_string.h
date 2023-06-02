#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int index_buf_mass;
  int format_index;
  int str_long;
  double space;
  int flag_plus;
  int flag_minus;
  int flag_space;
  int flag_zero;
  int flag_add_space;
  int accuracy;
  int error;
  int flag_h;
  int flag_l;
  int flag_accuracy;
  va_list argptr;

} write_in_buf;

int s21_sprintf(char* buf, char* format, ...);
void itoa(write_in_buf* output, long double n, char s[], int itsFloat);
void count_space(write_in_buf* output, char* format);
double simple_pow(int base, int exp);
void add_space(write_in_buf* output, char* buf);
void sellect_flags(char* buf, write_in_buf* output, char* format);
void sellect_width(char* buf, write_in_buf* output, char* format);
void sellect_accuracy(char* buf, write_in_buf* output, char* format);
void sellect_modifier(char* buf, write_in_buf* output, char* format);
void sellect_type(char* buf, write_in_buf* output, char* format);
void cat_str(write_in_buf* output, long double n, char s[]);
#endif