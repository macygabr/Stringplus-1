#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include <math.h>

int s21_string();
int s21_sprintf(char* buf, char* format, ...);

typedef struct {
int index_buf_mass; 
int format_index;
int str_long;
va_list argptr;

} write_in_buf;

#endif