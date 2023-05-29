#include "s21_string.h"

int s21_sprintf(char* buf, char* format, ...)
{
    write_in_buf output = {0};
    
    va_start(output.argptr, format);
    buf[0] = '\0';

    int format_len = strlen(format);
    for(output.format_index=0; output.format_index<format_len; output.format_index++) {
        output.flag_plus =0;
        output.space = 0;
        output.str_long =0;
        if(format[output.format_index] == '%')
        {
            switch (format[output.format_index+1])
            {
            case '-':
                add_spase(&output, format);
                sellect_arg(buf ,&output, format[output.format_index]);  
                for(int j=0; j<(int)(output.space) - output.str_long; j++) buf[output.index_buf_mass++] = ' ';
                break;
             case '+':
                output.flag_plus =1;
                add_spase(&output, format);
                sellect_arg(buf ,&output, format[output.format_index]);  
                break;
             case ' ':
                output.flag_plus =1;
                add_spase(&output, format);
                sellect_arg(buf ,&output, format[output.format_index]);  
                break;
            default:
                sellect_arg(buf ,&output, format[++output.format_index]);  
                break;
            }
        }
        else buf[output.index_buf_mass++] = format[output.format_index];
        buf[output.index_buf_mass] = '\0';
    }
    va_end(output.argptr);
    return 0;
}

void sellect_arg(char* buf, write_in_buf* output, char format) {

    switch (format) {
        case 'd':
            char str1[20];
            itoa(output,va_arg(output->argptr, int), str1, 0);
            output->str_long = strlen(str1);
            for(int j=0;output->flag_plus && j<(int)(output->space) - output->str_long; j++) 
                buf[output->index_buf_mass++] = ' ';
            buf = strcat(buf,str1);
            output->index_buf_mass +=strlen(str1);
            break;
        case 'c':
            buf[output->index_buf_mass++] = va_arg(output->argptr, int);
            break;
        case 's':
            char* str2 = va_arg(output->argptr,  char*);
            buf = strcat(buf,str2);
            (output->index_buf_mass) +=strlen(str2);
            break;
        case 'f':
            char str3[20];
            itoa(output,va_arg(output->argptr, double), str3, 1);
            output->str_long = strlen(str3);
            for(int j=0;output->flag_plus && j<(int)(output->space) - output->str_long; j++) 
                buf[output->index_buf_mass++] = ' ';
            buf = strcat(buf,str3);
            (output->index_buf_mass) +=strlen(str3);
            break;
        case 'u':
            char str4[20];
            itoa(output,va_arg(output->argptr, unsigned int), str4, 0);
            buf = strcat(buf,str4);
            (output->index_buf_mass) +=strlen(str4);
            break;
        case '%':
            buf[output->index_buf_mass++] = '%';
            buf[output->index_buf_mass + 1] = '\0';
            break;       
        default:
            char out[50];
            s21_sprintf(out, "Флага %c нет", format);
            perror(out);
            break;
    }
}
// c, d, i, e, E, f, g, G, o, s, u, x, X, p, n, %
// 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0
void itoa(write_in_buf* output,long double n, char s[], int itsFloat)
 {
    
    long int i, j, sign, notWhole = -1;
    char c;
    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    if(itsFloat)
    {
        for(notWhole = 0; notWhole < 7; notWhole++) 
            n*=10;
    n = (long int)n;
    if ((long int)n % 10 >= 5) {
            n /= 10;
            n++;
    } else n /= 10;
    notWhole--;
    }
    i = 0;
    n = (long int)n;
    do {
        if(notWhole != i)
            s[i++] = (long int)n % 10 + '0';
        else {
            s[i++] = '.';
            s[i++] = (long int)n % 10 + '0';
        }
    } while ((long int)(n /= 10) > 0);
    if (sign < 0) s[i++] = '-';
    if(sign >= 0 && output->flag_plus) s[i++] = '+';
    s[i] = '\0';
    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void add_spase(write_in_buf* output, char* format)
{
    output->format_index += 2;
    output->space = 0;
    int i = 0;
    for(i = 0; format[output->format_index]<='9' && format[output->format_index]>='0';i++)
    {
        output->space += (format[output->format_index] - '0')/simple_pow(10,i);
        output->format_index++;
    } 
    output->space *= simple_pow(10,i-1);
}

// void add_sign(char* buf, write_in_buf* output, char* format)
// {

// }
double simple_pow(int base,int exp)
{
    if( exp ==0) return 1;
    for(int i =1; i<exp; i++) base*= base;
    return base;
}