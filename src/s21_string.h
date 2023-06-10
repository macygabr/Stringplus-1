#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <limits.h>
#include <stdarg.h>

typedef struct {
  int index_buf_mass;
  int format_index;
  int str_long;
  int space;
  int flag_plus;
  int flag_minus;
  int flag_space;
  int flag_zero;
  int flag_add_space;
  int accuracy;
  int flag_h;
  int flag_l;
  int flag_L;
  int flag_g;
  int flag_e;
  int flag_x;
  int flag_o;
  int flag_u;
  int flag_negative;
  int flag_dot;
  char e_exp[256];
  int flag_accuracy;
  int accuracy_g;
  int res;

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
long double sel_num(write_in_buf* output, long double n);
void scientific_notation(write_in_buf* output, char s[], long double n);
void hexadecimal(write_in_buf* output, char s[], long int n);

void flag_d(char* buf, write_in_buf* output);
void flag_c(char* buf, write_in_buf* output);
void flag_s(char* buf, write_in_buf* output);
void flag_f(char* buf, write_in_buf* output);
void flag_u(char* buf, write_in_buf* output);
void flag_g(char* buf, write_in_buf* output);
void flag_e(char* buf, write_in_buf* output);
void flag_x(char* buf, write_in_buf* output);
void flag_p(char* buf, write_in_buf* output);

int s21_sscanf(char *buf, char *format, ...);
#endif