#include "fifth.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long unsigned s21_size_t;

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  if (str == NULL)
    len = -1;
  else
    for (; str[len]; len++)
      ;
  return len + 1;
};

// Возвращает копию строки (str), преобразованной в верхний регистр. В случае
// какой-либо ошибки следует вернуть значение NULL
void *s21_to_upper(const char *str);

// Возвращает копию строки (str), преобразованной в нижний регистр. В случае
// какой-либо ошибки следует вернуть значение NULL
void *s21_to_lower(const char *str);

// Возвращает новую строку, в которой указанная строка (str) вставлена в
// указанную позицию (start_index) в данной строке (src). В случае какой-либо
// ошибки следует вернуть значение NULL
void *s21_insert(const char *src, const char *str, size_t start_index);

// Возвращает новую строку, в которой удаляются все начальные и конечные
// вхождения набора заданных символов (trim_chars) из данной строки (src). В
// случае какой-либо ошибки следует вернуть значение NULL
void *s21_trim(const char *src, const char *trim_chars);

int main() {
  char *buff = NULL;
  char *b1 = "ABCD";
  char *b3 = "abc";
  char *buff1 = "12";
  char *b11 = "1";
  char *b31;

  for (int i = 0; i < 300; i++) printf("%s\n", strerror(i));

  return 0;
}

// Возвращает новую строку, в которой удаляются все начальные и конечные
// вхождения набора заданных символов (trim_chars) из данной строки (src). В
// случае какой-либо ошибки следует вернуть значение NULL
void *s21_trim(const char *src, const char *trim_chars) {
  char *rezult;
  if (src == NULL)
    rezult = NULL;
  else {
    int null_flag;
    int len = strlen(src);
    if (trim_chars == NULL) {
      int start = 0, end = len - 1;
      while (src[start] == ' ' || src[start] == '\t' || src[start] == '\n' ||
             src[start] == '\r')
        start++;
      while (src[end] == ' ' || src[end] == '\t' || src[end] == '\n' ||
             src[end] == '\r')
        end--;
      rezult = (char *)malloc(sizeof(char) * (end - start));
      for (int i = start, j = 0; i <= end; j++, i++) rezult[j] = src[i];
    } else {
      int trim_len = strlen(trim_chars);
      int start = 0, end = len - 1;
      char *trim_deleted = malloc(sizeof(trim_chars));
      strcpy(trim_deleted, trim_chars);
      for (int i = 0; i < trim_len; i++) {
        while (src[start] == trim_deleted[i]) start++;
        while (src[end] == trim_deleted[i]) end--;
        char *buff = malloc(sizeof(trim_deleted) - sizeof(char));
        for (int k = 0, j = 0; j < trim_len; k++, j++) {
          if (j == i) j++;
          buff[k] = trim_deleted[j];
        }
        free(trim_deleted);
        trim_deleted = malloc(sizeof(buff));
        strcpy(trim_deleted, buff);
        free(buff);
        i = -1;
        trim_len = trim_len - 1;
      }
      free(trim_deleted);
      rezult = malloc(sizeof(char) * (end - start + 1));
      for (int j = 0, i = start; i <= end; j++, i++) {
        rezult[j] = src[i];
      }
    }
  }
  return rezult;
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *rezult;
  if (start_index < 0 || start_index > s21_strlen(str) ||
      (str == NULL && src == NULL))
    rezult = NULL;
  else if (str != NULL && src != NULL) {
    rezult =
        (char *)malloc((s21_strlen(str) + s21_strlen(src) + 1) * sizeof(char));
    strncpy(rezult, str, start_index);
    strcpy(rezult + start_index, src);
    strcpy(rezult + start_index + s21_strlen(src), str + start_index);
  } else if (src == NULL) {
    rezult = malloc(sizeof(str));
    strcpy(rezult, str);
  } else if (str == NULL && start_index == 0) {
    rezult = malloc(sizeof(src));
    strcpy(rezult, src);
  } else
    rezult = NULL;
  return rezult;
}

void *s21_to_lower(const char *str) {
  char *rezult;
  if (str != NULL) {
    rezult = malloc(sizeof(str));
    strcpy(rezult, str);
    for (int i = 0; i < s21_strlen(str); i++)
      if (rezult[i] >= 'A' && rezult[i] <= 'Z') rezult[i] += 'a' - 'A';
  } else
    rezult = NULL;
  return rezult;
}

void *s21_to_upper(const char *str) {
  char *rezult;
  if (str != NULL) {
    rezult = malloc(sizeof(str));
    strcpy(rezult, str);
    for (int i = 0; i < s21_strlen(str); i++)
      if (rezult[i] >= 'a' && rezult[i] <= 'z') rezult[i] += 'A' - 'a';
  } else
    rezult = NULL;
  return rezult;
}

// Undefined error: 0
// Operation not permitted
// No such file or directory
// No such process
// Interrupted system call
// Input/output error
// Device not configured
// Argument list too long
// Exec format error
// Bad file descriptor
// No child processes
// Resource deadlock avoided
// Cannot allocate memory
// Permission denied
// Bad address
// Block device required
// Resource busy
// File exists
// Cross-device link
// Operation not supported by device
// Not a directory
// Is a directory
// Invalid argument
// Too many open files in system
// Too many open files
// Inappropriate ioctl for device
// Text file busy
// File too large
// No space left on device
// Illegal seek
// Read-only file system
// Too many links
// Broken pipe
// Numerical argument out of domain
// Result too large
// Resource temporarily unavailable
// Operation now in progress
// Operation already in progress
// Socket operation on non-socket
// Destination address required
// Message too long
// Protocol wrong type for socket
// Protocol not available
// Protocol not supported
// Socket type not supported
// Operation not supported
// Protocol family not supported
// Address family not supported by protocol family
// Address already in use
// Can't assign requested address
// Network is down
// Network is unreachable
// Network dropped connection on reset
// Software caused connection abort
// Connection reset by peer
// No buffer space available
// Socket is already connected
// Socket is not connected
// Can't send after socket shutdown
// Too many references: can't splice
// Operation timed out
// Connection refused
// Too many levels of symbolic links
// File name too long
// Host is down
// No route to host
// Directory not empty
// Too many processes
// Too many users
// Disc quota exceeded
// Stale NFS file handle
// Too many levels of remote in path
// RPC struct is bad
// RPC version wrong
// RPC prog. not avail
// Program version wrong
// Bad procedure for program
// No locks available
// Function not implemented
// Inappropriate file type or format
// Authentication error
// Need authenticator
// Device power is off
// Device error
// Value too large to be stored in data type
// Bad executable (or shared library)
// Bad CPU type in executable
// Shared library version mismatch
// Malformed Mach-o file
// Operation canceled
// Identifier removed
// No message of desired type
// Illegal byte sequence
// Attribute not found
// Bad message
// EMULTIHOP (Reserved)
// No message available on STREAM
// ENOLINK (Reserved)
// No STREAM resources
// Not a STREAM
// Protocol error
// STREAM ioctl timeout
// Operation not supported on socket
// Policy not found
// State not recoverable
// Previous owner died
// Interface output queue is full
// Unknown error: 107