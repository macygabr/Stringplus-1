#include "s21_string.h"

int s21_sprintf(char* buf, char* format, ...) {
  write_in_buf output = {0};
  output.error = 0;
  va_start(output.argptr, format);
  buf[0] = '\0';
  int format_len = strlen(format);
  for (output.format_index = 0; output.format_index < format_len;
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
    output.flag_accuracy = 0;
    output.accuracy = 6;
    if (format[output.format_index] == '%') {
      sellect_flags(buf, &output, format);
    } else
      buf[output.index_buf_mass++] = format[output.format_index];
    buf[output.index_buf_mass + 1] = '\0';
  }
  va_end(output.argptr);
  return 0;
}

void sellect_flags(char* buf, write_in_buf* output, char* format) {
  switch (format[++output->format_index]) {
    case '-':
      output->format_index++;
      output->flag_minus = 1;
      sellect_width(buf, output, format);
      break;
    case '+':
      output->format_index++;
      output->flag_plus = 1;
      sellect_width(buf, output, format);
      break;
    case ' ':
      output->format_index++;
      output->flag_space = 1;
      sellect_width(buf, output, format);
      break;
    case '0':
      output->format_index++;
      output->flag_zero = 1;
      sellect_width(buf, output, format);
      break;
    case '#':
      output->format_index++;
      output->flag_zero = 1;
      sellect_width(buf, output, format);
      break;
    default:
      sellect_width(buf, output, format);
      break;
  }
  if(output->flag_minus) add_space(output, buf);
}
void sellect_width(char* buf, write_in_buf* output, char* format) {
  switch (format[output->format_index]) {
    case '0' ... '9':
      count_space(output, format);
      sellect_accuracy(buf, output, format);
      break;
    case '*':
      output->space = va_arg(output->argptr, int);
      if(output->space < 0) {
        output->flag_minus = 1;
        output->space = -output->space;
      }
      output->format_index++;
      sellect_accuracy(buf, output, format);
      break;
    default:
      sellect_accuracy(buf, output, format);
      break;
  }
}
void sellect_accuracy(char* buf, write_in_buf* output, char* format) {
  switch (format[output->format_index]) {
    case '.':  // до 16 знаков после запятой работает, после просто 0
      output->format_index++;
      output->flag_accuracy = 1;
      if(format[output->format_index] == '*'){
        output->accuracy = va_arg(output->argptr, int);
      output->format_index++;
      }
      else{// обработать только числа 0-9
      int rub_flag = output->space;
      count_space(output, format);
      output->accuracy = output->space;
      output->space = rub_flag;
      }
      sellect_modifier(buf, output, format);
      break;
    default:
      sellect_modifier(buf, output, format);
      break;
  }
}

void sellect_modifier(char* buf, write_in_buf* output, char* format) {
  switch (format[output->format_index]) {
    case 'h':
      output->format_index++;
      if (format[output->format_index] == 'd') {
        output->flag_h = 1;
        sellect_type(buf, output, format);
      } else
        output->error = 1;
      break;
    case 'l':
      output->format_index++;
      if (format[output->format_index] == 'd') {
        output->flag_l = 1;
        sellect_type(buf, output, format);
      } else
        output->error = 1;
      break;
    case 'L':
      output->format_index++;
      sellect_type(buf, output, format);
      break;
    default:
      sellect_type(buf, output, format);
      break;
  }
}

void sellect_type(char* buf, write_in_buf* output, char* format) {
  switch (format[output->format_index]) {
    case 'd':
      char str1[256];
      long int input_data = va_arg(output->argptr, long int);
      if (output->flag_h) input_data = (short int)input_data;
      if (output->flag_l)
        if (input_data == (int)input_data) output->error = 1;
      if (output->flag_h == 0 && output->flag_l == 0) {
        if (input_data != (int)input_data) output->error = 1;
        input_data = (int)input_data;
      }
      itoa(output, input_data, str1, 0);
      output->str_long = strlen(str1);
      if(!output->flag_minus)add_space(output, buf);
      buf = strcat(buf, str1);
      output->index_buf_mass += strlen(str1);
      break;
    case 'c':
      buf[output->index_buf_mass++] = va_arg(output->argptr, int);
      break;
    case 's':
      char* str2 = va_arg(output->argptr, char*);
      char strn[256];
      if(!output->flag_accuracy) strcpy(strn,str2);
      output->str_long = strlen(strn);
      strncpy(strn, str2, output->accuracy);
      if(!output->flag_minus) add_space(output, buf);
      buf = strcat(buf, strn);
      output->index_buf_mass += strlen(strn);
      break;
    case 'f':
      char str3[256];
      itoa(output, va_arg(output->argptr, double), str3, 1);
      output->str_long = strlen(str3);
      if(!output->flag_minus)add_space(output, buf);
      buf = strcat(buf, str3);
      (output->index_buf_mass) += strlen(str3);
      break;
    case 'u':
      char str4[256];
      itoa(output, va_arg(output->argptr, unsigned int), str4, 0);
      output->str_long = strlen(str4);
      if(!output->flag_minus)add_space(output, buf);
      buf = strcat(buf, str4);
      (output->index_buf_mass) += strlen(str4);
      break;
    case 'g':
      char str5[256];
      long double n = va_arg(output->argptr, double);
      itoa(output, n, str5, 1);
      output->str_long = strlen(str5);
      int i = 0;
      int n1 = n;
      for (i = 0; n1; i++)
       n1 /=10;
      output->accuracy = output->str_long - 1 - i;
      itoa(output, n, str5, 1);
      if(!output->flag_minus)add_space(output, buf);
      buf = strcat(buf, str5);
      (output->index_buf_mass) += strlen(str5);
      break;
    case 'G':
      break;
    case 'e':
      break;
    case 'E':
      break;
    case 'x':
      break;
    case 'X':
      break;
    case 'o':
      break;
    case 'p':
      break;
  
    case '%':
      buf[output->index_buf_mass++] = '%';
      buf[output->index_buf_mass + 1] = '\0';
      break;
    default:
      break;
  }
}

void itoa(write_in_buf* output, long double n, char s[], int itsFloat) {
  long int i, j, sign, notWhole = -1;
  char c;

  if ((sign = n) < 0) n = -n;
  if (itsFloat) {
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
  n = (long int)n;
  do {
    if (notWhole != i)
      s[i++] = (long int)n % 10 + '0';
    else {
      s[i++] = '.';
      s[i++] = (long int)n % 10 + '0';
    }
  } while((long int)(n /= 10) > 0);
  s[i] = '\0';
  while (output->flag_accuracy == 1 && (int)strlen(s) < output->accuracy)
  {
    s[i++] = '0';
    s[i] = '\0';
  }
  if( sign > 0 && output->flag_space && !output->flag_plus)  s[i++] = ' ';
  if (sign < 0) s[i++] = '-';
  if (sign >= 0 && output->flag_plus) s[i++] = '+';
  s[i] = '\0';
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}


// void cat_str(write_in_buf* output, long double n, char s[])
// {

  
// }

void count_space(write_in_buf* output, char* format) {
  output->space = 0;
  int i = 0;
  for (i = 0; format[output->format_index] <= '9' &&
              format[output->format_index] >= '0';
       i++) {
    output->space += (format[output->format_index] - '0') / simple_pow(10, i);
    output->format_index++;
  }
  output->space *= simple_pow(10, i - 1);
}

double simple_pow(int base, int exp) {
  if (exp == 0) return 1;
  for (int i = 1; i < exp; i++) base *= base;
  return base;
}
void add_space(write_in_buf* output, char* buf) {
    for (int j = 0; j < (int)(output->space) - output->str_long; j++)
      if(output->flag_zero && !output->flag_minus)
      buf[output->index_buf_mass++] = '0';
      else
      buf[output->index_buf_mass++] = ' ';
    
  buf[output->index_buf_mass] = '\0';
}