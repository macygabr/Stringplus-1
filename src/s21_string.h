#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include <math.h>

typedef struct {
int index_buf_mass; 
int format_index;
int str_long;
va_list argptr;

} write_in_buf;

int s21_sprintf(char* buf, char* format, ...);
void itoa(long double n, char s[], int itsFloat);
void add_spase(char* buf, write_in_buf* output, char* format);
double simple_pow(int base,int exp);
void sellect_arg(char* buf, write_in_buf* output, char format);
#endif