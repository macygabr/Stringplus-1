#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"


int s21_sprintf(char *buf, char *format, ...) {
  write_in_buf output = {0};
  va_start(output.argptr, format);
  buf[0] = '\0';
  int format_len = strlen(format);
  for (output.format_index = 0; output.format_index < format_len && output.res != -1;
       output.format_index++) {
    output.flag_plus = 0;
    output.flag_space = 0;
    output.flag_minus = 0;
    output.flag_zero = 0;
    output.space = 0;
    output.str_long = 0;
    output.flag_add_space = 0;
    output.flag_h = 0;
    output.flag_l = 0;
    output.flag_L = 0;
    output.flag_g = 0;
    output.flag_e = 0;
    output.flag_x = 0;
    output.flag_o = 0;
    output.flag_u = 0;
    output.flag_dot = 0;
    output.flag_negative = 0;
    output.flag_accuracy = 0;
    output.accuracy = 6;
    if (format[output.format_index] == '%') {
      output.format_index++;
      sellect_flags(buf, &output, format);
      if (output.flag_minus) add_space(&output, buf);
    } else{
      buf[output.index_buf_mass++] = format[output.format_index];
      output.res ++;
    }
    buf[output.index_buf_mass + 1] = '\0';
    
  }
  va_end(output.argptr);
  return output.res;
}

void sellect_flags(char *buf, write_in_buf *output, char *format) {
  switch (format[output->format_index]) {
    case '-':
      output->flag_minus = 1;
      output->format_index++;
      //sellect_width(buf, output, format);
      sellect_flags(buf, output, format);
      break;
    case '+':
      output->flag_plus = 1;
      output->format_index++;
      //sellect_width(buf, output, format);
       sellect_flags(buf, output, format);
      break;
    case ' ':
      output->flag_space = 1;
      output->format_index++;
      //sellect_width(buf, output, format);
       sellect_flags(buf, output, format);
      break;
    case '0':
      output->flag_zero = 1;
      output->format_index++;
      //sellect_width(buf, output, format);
       sellect_flags(buf, output, format);
      break;
    case '#':
      output->flag_zero = 1;
      output->format_index++;
      //sellect_width(buf, output, format);
       sellect_flags(buf, output, format);
      break;
    default:
      sellect_width(buf, output, format);
      break;
  }
}
void sellect_width(char *buf, write_in_buf *output, char *format) {
  switch (format[output->format_index]) {
    case '0' ... '9':
      count_space(output, format);
      sellect_accuracy(buf, output, format);
      break;
    case '*':
      output->space = va_arg(output->argptr, int);
      if (output->space < 0) {
        output->flag_minus = 1;
        output->space *= -1;
      }
      output->format_index++;
      sellect_accuracy(buf, output, format);
      break;
    default:
      sellect_accuracy(buf, output, format);
      break;
  }
}
void sellect_accuracy(char *buf, write_in_buf *output, char *format) {
  int rub_flag = 0;
  if(format[output->format_index] == '.'){
    output->format_index++;
    output->flag_accuracy = 1;
    switch (format[output->format_index])
    {
    case '*':
        output->accuracy = va_arg(output->argptr, int);
        output->format_index++;
        sellect_modifier(buf, output, format);
      break;
    case '0' ... '9':
        rub_flag = output->space;
        count_space(output, format);
        output->accuracy = output->space;
        output->space = rub_flag;
        sellect_modifier(buf, output, format);
      break;
    default:
        output->flag_dot =1;
        sellect_modifier(buf, output, format);
      break;
    }
  }
  else sellect_modifier(buf, output, format);
}

void sellect_modifier(char *buf, write_in_buf *output, char *format) {
  switch (format[output->format_index]) {
    case 'h':
      output->format_index++;
      output->flag_h = 1;
      sellect_type(buf, output, format);
      break;
    case 'l':
      output->format_index++;
      output->flag_l = 1;
      sellect_type(buf, output, format);
      break;
    case 'L':
      output->format_index++;
      output->flag_L = 1;
      sellect_type(buf, output, format);
      break;
    default:
      sellect_type(buf, output, format);
      break;
  }
}

void sellect_type(char *buf, write_in_buf *output, char *format) {
  switch (format[output->format_index]) {
    case 'd':
      flag_d(buf, output);
      break;
    case 'c':
      flag_c(buf, output);
      break;
    case 's':
      flag_s(buf, output);
      break;
    case 'f':
      flag_f(buf, output);
      break;
    case 'u':
      output->flag_u = 1;
      flag_u(buf, output);
      break;
    case 'g':
      flag_g(buf, output);
      break;
    case 'G':
      flag_g(buf, output);
      break;
    case 'e':
      output->flag_e = 1;
      flag_e(buf, output);
      break;
    case 'E':
      flag_e(buf, output);
      break;
    case 'x':
      output->flag_x = 1;
      flag_x(buf, output);
      break;
    case 'X':
      flag_x(buf, output);
      break;
    case 'o':
      output->flag_o = 1;
      flag_x(buf, output);
      break;
    case 'p':
      flag_p(buf, output);
      break;
    case '%':
      buf[output->index_buf_mass++] = '%';
      buf[output->index_buf_mass + 1] = '\0';
      break;
    default:
      // output->error++;
      break;
  }
}

void itoa(write_in_buf *output, long double n, char s[], int itsFloat) {
  s[0] = '\0';
  long int i = 0, j = 0, sign = n, notWhole = -1;
  long double origin_n_doub = n;
  long int origin_n_int =n;
  char c;
  if ((n) < 0) n *= -1;
  if (itsFloat) {
    if(output->accuracy<0) output->accuracy=6;
    for (notWhole = 0; notWhole < output->accuracy + 1; notWhole++) n *= 10;
    n = (long int)n;
    if ((long int)n % 10 >= 5) {
      n /= 10;
      n++;
    } else
      n /= 10;
    notWhole--;
  }
  i = 0;
  if (output->flag_g) {
    while ((long int)n % 10 == 0 && n!=0) {
      n /= 10;
      notWhole--;
    }
    if(n == origin_n_int) notWhole--;
    printf("{%Lf}\n", n);
  }
  do {
    if (notWhole == i && output->accuracy != 0) s[i++] = '.';
    int n_positiv = (long int)n % 10;
    if(n_positiv <0) n_positiv *= -1;
    s[i++] = n_positiv + '0';
  } while ((long int)(n /= 10) > 0);
  if(((origin_n_doub < 1 && origin_n_doub > 0) || (origin_n_doub > -1 && origin_n_doub < 0)) && output->accuracy != 0){
   s[i++] = '.';
   s[i++] = '0';
  }
  s[i] = '\0';
  while (output->flag_accuracy == 1 && !output->flag_g && !output->flag_dot && (int)strlen(s) < output->accuracy) {
    s[i++] = '0';
    s[i] = '\0';
  }
  if(output->flag_dot && sign == 0) {
    sign = 1;
    i=0;
    }
  if (origin_n_doub >= 0 && output->flag_space && !output->flag_plus && !output->flag_u) s[i++] = ' ';
  if (origin_n_doub < 0 && !output->flag_zero && !output->flag_u) s[i++] = '-';
  if(origin_n_doub < 0 && output->flag_zero) output->flag_negative =1;
  if (origin_n_doub >= 0 && output->flag_plus && !output->flag_u) s[i++] = '+';
  s[i] = '\0';
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
  if(output->accuracy == 0 && origin_n_int == 0 && !itsFloat) s[0] = '\0';
  
  if(output->accuracy == 0 && origin_n_int == 0 && itsFloat) {
    s[0] = origin_n_int +'0';
    s[1] = '\0';
  }
}

void count_space(write_in_buf *output, char *format) {
  output->space = 0;
  double rub = 0;
  int i = 0;
  for (i = 0; format[output->format_index] <= '9' && format[output->format_index] >= '0'; i++) {
    rub += (format[output->format_index] - '0') / simple_pow(10, i);
    output->format_index++;
  }
  rub *= simple_pow(10, i - 1);
  output->space = (int)rub;
  //printf("!!!%d!!!\n", output->space);
}

double simple_pow(int base, int exp) {
  long int res = base;
  if (exp == 0) return 1;
  for (int i = 1; i < exp; i++) res *= base;
  return res;
}

void add_space(write_in_buf *output, char *buf) {
  int j = 0;
  if(output->flag_zero && output->flag_negative) {
    buf[output->index_buf_mass++] = '-';
    output->res++;
    output->space--;
  }
  for (j = 0; j < output->space - output->str_long; j++)
    if (output->flag_zero && !output->flag_minus)
      buf[output->index_buf_mass++] = '0';
    else
      buf[output->index_buf_mass++] = ' ';
  buf[output->index_buf_mass] = '\0';
  output->res += j;
  //printf("%s\n", buf);
  //output->res += j;
}

long double sel_num(write_in_buf *output, long double n) {
  int i = 0;
  int j = 0;
  int int_n_num = (long int)n;
  for (j = 1; int_n_num /= 10; j++)
    ;
  int_n_num = j;
  output->accuracy_g = output->accuracy - int_n_num;
  output->accuracy = output->accuracy_g;
  for (i = 0; i < output->accuracy_g + 1; i++) n *= 10;
  n = (long int)n;
  if ((long int)n % 10 >= 5) {
    n /= 10;
    n = (long int)n;
    n++;
  } else {
    n /= 10;
    n = (long int)n;
  }
  n /= simple_pow(10, i - 1);
  return n;
}

void scientific_notation(write_in_buf *output, char s[], long double n) {
  int i = 0;
  long int copy_n_int = (long int)n;
  long double copy_n_doub = n;
  long double origin_n_save = n;
  if (n < 0) {
    copy_n_int = -copy_n_int;
    copy_n_doub = -copy_n_doub;
  }
  if (origin_n_save > 1) {
    for (i = 0; copy_n_int /= 10; i++)
      ;
    n /= simple_pow(10, i);
  } else {
    for (i = 0; (copy_n_doub *= 10) < 10; i++)
      ;
    n *= simple_pow(10, i);
  }
  itoa(output, n, s, 1);
  output->str_long = strlen(s);
  if (output->flag_e)
    s[output->str_long++] = 'e';
  else
    s[output->str_long++] = 'E';
  if (origin_n_save < 1)
    s[output->str_long++] = '-';
  else
    s[output->str_long++] = '+';
  if (i < 9) {
    s[output->str_long++] = '0';
    s[output->str_long++] = i + '0';
  } else {
    s[output->str_long++] = i / 10 + '0';
    s[output->str_long++] = i % 10 + '0';
  }
  s[output->str_long++] = '\0';
}

void hexadecimal(write_in_buf *output, char s[], long int n) {
  long int remainder = 0;
  int digit = 16, k = 0;
  char c;
  if (output->flag_o) digit = 8;
  s[0] = '\0';
  if (n < 0) n = (4294967295 + 1 + n);
  do {
    remainder = n % digit;
    if (remainder > 9) {
      s[k] = 'A' + remainder - 10;
      if (output->flag_x) s[k] = 'a' + remainder - 10;
    } else
      s[k] = remainder + '0';
    s[k + 1] = '\0';
    k++;
  } while (n /= digit);

  for (int i = 0, j = k - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void flag_d(char *buf, write_in_buf *output) {
  char str[256];
  long int input_data;
  if (output->flag_l) input_data = va_arg(output->argptr, long int);
  else input_data = va_arg(output->argptr, int);
  if (output->flag_h) input_data = (short int)input_data;
  itoa(output, input_data, str, 0);
  output->str_long = strlen(str);
  if (!output->flag_minus) add_space(output, buf);
  buf = strcat(buf, str);
  output->index_buf_mass += strlen(str);
  output->res += strlen(str);
  //printf("{%s}\n", buf);
}

void flag_c(char *buf, write_in_buf *output) {
  output->str_long = 1;
  if (!output->flag_minus) add_space(output, buf);
  buf[output->index_buf_mass++] = va_arg(output->argptr, int);
  output->res++;
}

void flag_f(char *buf, write_in_buf *output) {
  char str[256];
  if(output->flag_L) itoa(output, va_arg(output->argptr, long double), str, 1);
  else itoa(output, va_arg(output->argptr, double), str, 1);
  output->str_long = strlen(str);
  if (!output->flag_minus) add_space(output, buf);
  buf = strcat(buf, str);
  output->index_buf_mass += strlen(str);
  output->res += strlen(str);
}

void flag_s(char *buf, write_in_buf *output) {
  char strn[256];
  char *str2;
  wchar_t* str_wchar;
  if(output->flag_l) str_wchar = va_arg(output->argptr, wchar_t*);
  else str2 = va_arg(output->argptr, char *);
  strn[256] = '\0';
  if (!output->flag_accuracy){
    strcpy(strn, str2);
  }
  else {
    if(output->accuracy < 0) output->accuracy = (int)strlen(str2);
    strncpy(strn, str2, output->accuracy);
    strn[output->accuracy] = '\0';
  }
  output->str_long = strlen(strn);
  if (!output->flag_minus) add_space(output, buf);
  if(output->flag_l) {
    strn[0] = '\0';
    output->res = -1;
    str_wchar = str_wchar;
  }
  output->index_buf_mass += strlen(strn);
  buf = strcat(buf, strn);
  output->res += strlen(strn);
}

void flag_u(char *buf, write_in_buf *output) {
  char str[256];
   unsigned int input_data;
  if (output->flag_l) input_data = va_arg(output->argptr, long int);
  else input_data = va_arg(output->argptr, unsigned int);
  if (output->flag_h) input_data = (unsigned short int)input_data;
  itoa(output, input_data, str, 0);
  output->str_long = strlen(str);
  if (!output->flag_minus) add_space(output, buf);
  buf = strcat(buf, str);
  output->index_buf_mass += strlen(str);
  output->res += strlen(str);
}

void flag_g(char *buf, write_in_buf *output) {
  char str[256];
  long double input_double;
  output->flag_g = 1;
  // if (output->flag_l) input_double = va_arg(output->argptr, long int);
  // else input_data = va_arg(output->argptr, unsigned int);
  // if (output->flag_h) input_data = (unsigned short int)input_data;
  input_double = va_arg(output->argptr, double);
  input_double = sel_num(output, input_double);

    if(strlen(input_double - (long int)input_double) >= 6)scientific_notation(output, str, input_double);
    else itoa(output, input_double, str, 1);
  output->str_long = strlen(str);
  if (!output->flag_minus) add_space(output, buf);
  buf = strcat(buf, str);
  output->index_buf_mass += strlen(str);
}

void flag_e(char *buf, write_in_buf *output) {
  char str[256];
  long double input_double;
  input_double = va_arg(output->argptr, double);
  scientific_notation(output, str, input_double);
  output->str_long = strlen(str);
  if (!output->flag_minus) add_space(output, buf);
  buf = strcat(buf, str);
  output->index_buf_mass += strlen(str);
}

void flag_x(char *buf, write_in_buf *output) {
  char str[256];
  long int input_data;
  input_data = va_arg(output->argptr, int);
  hexadecimal(output, str, input_data);
  if (!output->flag_minus) add_space(output, buf);
  buf = strcat(buf, str);
  output->index_buf_mass += strlen(str);
}

void flag_p(char *buf, write_in_buf *output) {
  buf = buf;
  output->accuracy = output->accuracy;
  // char str[256];
  //  char* input_data;
  //  input_data = va_arg(output->argptr, void*);
  //  printf("%c\n", input_data[0]);
}