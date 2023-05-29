#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

/**
 * Searches for the first occurrence of the specified character in the array
 * @param str a pointer to an array to be searched
 * @param c the code of the desired character
 * @param n the size of the compared part of the array in bytes
 * 
 * @return A pointer to the found character, if the required character is found in the specified section of the array.
NULL - if the required character is not found
*/
void *memchr(const void *str, int c, size_t n);

/**
 * Array comparison
 * @param str1 a pointer to the arrays to be compared
 * @param str2 a pointer to the arrays to be compared
 * @param n the size of the compared part of the array in bytes
 * 
 * @return 0 - if the compared parts of the arrays are identical
*/
int memcmp(const void *str1, const void *str2, size_t n);

/**
 * Find the first occurrence of a character in a string
 * @param str pointer to the string to be searched
 * @param c the code of the desired character
 * 
 * @return Pointer to the character to search for, if found in str, NULL otherwise.
*/
char *strchr(const char *str, int c);

int s21_sprintf(char* buf, char* format, ...);
//void print_arg(va_list argptr, base_mass str);

typedef struct {
    char mas_format[100];
    int mas_format_len;
    int type;
} base_mass;

#endif