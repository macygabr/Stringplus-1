
#include "fifth.h"

#include <stdio.h>
#include <stdlib.h>
#ifdef __linux__
char *s21_strerror(int errnum) {
#define MAX_NUM_ERR 134
  static const char *Error_[MAX_NUM_ERR] = {
      "Success",
      "Operation not permitted",
      "No such file or directory",
      "No such process",
      "Interrupted system call",
      "Input/output error",
      "No such device or address",
      "Argument list too long",
      "Exec format error",
      "Bad file descriptor",
      "No child processes",
      "Resource temporarily unavailable",
      "Cannot allocate memory",
      "Permission denied",
      "Bad address",
      "Block device required",
      "Device or resource busy",
      "File exists",
      "Invalid cross-device link",
      "No such device",
      "Not a directory",
      "Is a directory",
      "Invalid argument",
      "Too many open files in system",
      "Too many open files",
      "Inappropriate ioctl for device",
      "Text file busy",
      "File too large",
      "No space left on device",
      "Illegal seek",
      "Read-only file system",
      "Too many links",
      "Broken pipe",
      "Numerical argument out of domain",
      "Numerical result out of range",
      "Resource deadlock avoided",
      "File name too long",
      "No locks available",
      "Function not implemented",
      "Directory not empty",
      "Too many levels of symbolic links",
      "Unknown error 41",
      "No message of desired type",
      "Identifier removed",
      "Channel number out of range",
      "Level 2 not synchronized",
      "Level 3 halted",
      "Level 3 reset",
      "Link number out of range",
      "Protocol driver not attached",
      "No CSI structure available",
      "Level 2 halted",
      "Invalid exchange",
      "Invalid request descriptor",
      "Exchange full",
      "No anode",
      "Invalid request code",
      "Invalid slot",
      "Unknown error 58",
      "Bad font file format",
      "Device not a stream",
      "No data available",
      "Timer expired",
      "Out of streams resources",
      "Machine is not on the network",
      "Package not installed",
      "Object is remote",
      "Link has been severed",
      "Advertise error",
      "Srmount error",
      "Communication error on send",
      "Protocol error",
      "Multihop attempted",
      "RFS specific error",
      "Bad message",
      "Value too large for defined data type",
      "Name not unique on network",
      "File descriptor in bad state",
      "Remote address changed",
      "Can not access a needed shared library",
      "Accessing a corrupted shared library",
      ".lib section in a.out corrupted",  //
      "Attempting to link in too many shared libraries",
      "Cannot exec a shared library directly",
      "Invalid or incomplete multibyte or wide character",
      "Interrupted system call should be restarted",
      "Streams pipe error",
      "Too many users",
      "Socket operation on non-socket",
      "Destination address required",
      "Message too long",
      "Protocol wrong type for socket",
      "Protocol not available",
      "Protocol not supported",
      "Socket type not supported",
      "Operation not supported",
      "Protocol family not supported",
      "Address family not supported by protocol",
      "Address already in use",
      "Cannot assign requested address",
      "Network is down",
      "Network is unreachable",
      "Network dropped connection on reset",
      "Software caused connection abort",
      "Connection reset by peer",
      "No buffer space available",
      "Transport endpoint is already connected",
      "Transport endpoint is not connected",
      "Cannot send after transport endpoint shutdown",
      "Too many references: cannot splice",
      "Connection timed out",
      "Connection refused",
      "Host is down",
      "No route to host",
      "Operation already in progress",
      "Operation now in progress",
      "Stale file handle",
      "Structure needs cleaning",
      "Not a XENIX named type file",
      "No XENIX semaphores available",
      "Is a named type file",
      "Remote I/O error",
      "Disk quota exceeded",
      "No medium found",
      "Wrong medium type",
      "Operation canceled",
      "Required key not available",
      "Key has expired",
      "Key has been revoked",
      "Key was rejected by service",
      "Owner died",
      "State not recoverable",
      "Operation not possible due to RF-kill",
      "Memory page has hardware error"};
  char *result = malloc(256 * sizeof(char));
  if (errnum < 0 || errnum >= MAX_NUM_ERR) {
    char *f = "Unknown error: ";
    char d[256];
    s21_itoa(errnum, d);
    s21_strcat(result, f);
    s21_strcat(result, d);
  } else
    s21_strcat(result, Error_[errnum]);
  return (char *)result;
}
#else
char *s21_strerror(int errnum) {
#define MAX_NUM_ERR 107
  static const char *Error_[MAX_NUM_ERR] = {
      "Undefined error: 0",
      "Operation not permitted",
      "No such file or directory",
      "No such process",
      "Interrupted system call",
      "Input/output error",
      "Device not configured",
      "Argument list too long",
      "Exec format error",
      "Bad file descriptor",
      "No child processes",
      "Resource deadlock avoided",
      "Cannot allocate memory",
      "Permission denied",
      "Bad address",
      "Block device required",
      "Resource busy",
      "File exists",
      "Cross-device link",
      "Operation not supported by device",
      "Not a directory",
      "Is a directory",
      "Invalid argument",
      "Too many open files in system",
      "Too many open files",
      "Inappropriate ioctl for device",
      "Text file busy",
      "File too large",
      "No space left on device",
      "Illegal seek",
      "Read-only file system",
      "Too many links",
      "Broken pipe",
      "Numerical argument out of domain",
      "Result too large",
      "Resource temporarily unavailable",
      "Operation now in progress",
      "Operation already in progress",
      "Socket operation on non-socket",
      "Destination address required",
      "Message too long",
      "Protocol wrong type for socket",
      "Protocol not available",
      "Protocol not supported",
      "Socket type not supported",
      "Operation not supported",
      "Protocol family not supported",
      "Address family not supported by protocol family",
      "Address already in use",
      "Can't assign requested address",
      "Network is down",
      "Network is unreachable",
      "Network dropped connection on reset",
      "Software caused connection abort",
      "Connection reset by peer",
      "No buffer space available",
      "Socket is already connected",
      "Socket is not connected",
      "Can't send after socket shutdown",
      "Too many references: can't splice",
      "Operation timed out",
      "Connection refused",
      "Too many levels of symbolic links",
      "File name too long",
      "Host is down",
      "No route to host",
      "Directory not empty",
      "Too many processes",
      "Too many users",
      "Disc quota exceeded",
      "Stale NFS file handle",
      "Too many levels of remote in path",
      "RPC struct is bad",
      "RPC version wrong",
      "RPC prog. not avail",
      "Program version wrong",
      "Bad procedure for program",
      "No locks available",
      "Function not implemented",
      "Inappropriate file type or format",
      "Authentication error",
      "Need authenticator",
      "Device power is off",
      "Device error",
      "Value too large to be stored in data type",
      "Bad executable (or shared library)",
      "Bad CPU type in executable",
      "Shared library version mismatch",
      "Malformed Mach-o file",
      "Operation canceled",
      "Identifier removed",
      "No message of desired type",
      "Illegal byte sequence",
      "Attribute not found",
      "Bad message",
      "EMULTIHOP (Reserved)",
      "No message available on STREAM",
      "ENOLINK (Reserved)",
      "No STREAM resources",
      "Not a STREAM",
      "Protocol error",
      "STREAM ioctl timeout",
      "Operation not supported on socket",
      "Policy not found",
      "State not recoverable",
      "Previous owner died",
      "Interface output queue is full"};
  char *result = malloc(256 * sizeof(char));
  if (errnum < 0 || errnum >= MAX_NUM_ERR) {
    char *f = "Unknown error: ";
    char d[256];
    s21_itoa(errnum, d);
    s21_strcat(result, f);
    s21_strcat(result, d);
  } else
    s21_strcat(result, Error_[errnum]);
  return (char *)result;
}
#endif

void s21_delete(char *trim_deleted, int p) {
  for (int i = 0, j = 0; i < s21_strlen(trim_deleted); j++, i++) {
    if (i == p) i++;
    trim_deleted[j] = trim_deleted[i];
  }
  trim_deleted[s21_strlen(trim_deleted) - 1] = '\0';
}

char *s21_strcat(char *dest, const char *src) {
  char *destmem = dest;
  while (*dest != 0) dest++;
  while (*src != 0) {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = *src;
  return destmem;
}

void s21_itoa(int a, char *result) {
  int end = 0;
  int flag = 0;
  if (a < 0) {
    flag = 1;
    a = a * (-1);
  }
  while (a > 0) {
    int ost = a % 10;
    a = a / 10;
    for (int i = end + 1; i > 0; i--) result[i] = result[i - 1];
    result[0] = ost + '0';
    end++;
  }
  if (flag == 1) {
    for (int i = end + 1; i > 0; i--) result[i] = result[i - 1];
    result[0] = '-';
    end++;
  }
  result[end] = '\0';
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i;
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  if (i < n) {
    dest[i] = '\0';
  }
  return dest;
}

s21_size_t s21_strlen(const char *str) {
  int i;
  for (i = 0; str[i] != '\0'; i++)
    ;
  return i;
}

void *s21_to_lower(const char *str) {
  char *rezult;
  if (str != NULL) {
    rezult = malloc(sizeof(str));
    s21_strncpy(rezult, str, s21_strlen(str));
    for (int i = 0; i < (int)s21_strlen(str); i++)
      if (rezult[i] >= 'A' && rezult[i] <= 'Z') rezult[i] += 'a' - 'A';
  } else
    rezult = NULL;
  return (char *)rezult;
}

void *s21_to_upper(const char *str) {
  char *rezult;
  if (str != NULL) {
    rezult = malloc(sizeof(str));
    s21_strncpy(rezult, str, s21_strlen(str));
    for (int i = 0; i < (int)s21_strlen(str); i++)
      if (rezult[i] >= 'a' && rezult[i] <= 'z') rezult[i] += 'A' - 'a';
  } else
    rezult = NULL;
  return (char *)rezult;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *rezult;
  if (src == NULL)
    rezult = NULL;
  else {
    int len = s21_strlen(src);
    int trim_len = 0;
    if (trim_chars != NULL) trim_len = s21_strlen(trim_chars);
    int start = 0, end = len - 1;

    if (trim_chars == NULL) {
      int start = 0, end = len - 1;
      while (src[start] == ' ' || src[start] == '\t' || src[start] == '\n' ||
             src[start] == '\r')
        start++;
      while (src[end] == ' ' || src[end] == '\t' || src[end] == '\n' ||
             src[end] == '\r')
        end--;
      rezult = (char *)malloc(sizeof(char) * (end - start + 1));
      for (int i = start, j = 0; i <= end; j++, i++) {
        rezult[j] = src[i];
        rezult[j + 1] = '\0';
      }
    } else if (len == 0) {
      rezult = malloc(sizeof(char));
      rezult[0] = '\0';
    } else if (trim_len == 0) {
      rezult = malloc(sizeof(src));
      s21_strncpy(rezult, src, len);
    } else {
      char *trim_deleted = malloc(sizeof(trim_chars));
      s21_strncpy(trim_deleted, trim_chars, trim_len);
      for (int i = 0; i < trim_len; i++) {
        if (src[start] == trim_deleted[i]) {
          while (src[start] == trim_deleted[i]) start++;
          s21_delete(trim_deleted, i);
          i = -1;
          trim_len = trim_len - 1;
        }
      }
      trim_len = s21_strlen(trim_chars);
      s21_strncpy(trim_deleted, trim_chars, trim_len);
      for (int i = 0; i < trim_len; i++) {
        if (src[end] == trim_deleted[i]) {
          while (src[end] == trim_deleted[i]) end--;
          s21_delete(trim_deleted, i);
          i = -1;
          trim_len = trim_len - 1;
        }
      }
      rezult = malloc(sizeof(char) * (end - start + 1));
      int res_len = end - start + 1;
      for (int j = 0, i = start; i <= end, j < res_len; j++, i++) {
        rezult[j] = src[i];
      }
    }
  }
  return (char *)rezult;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *rezult;
  if (start_index > s21_strlen(src) || (src == NULL) || (str == NULL))
    rezult = NULL;
  else if (src != NULL && str != NULL) {
    rezult =
        (char *)malloc((s21_strlen(src) + s21_strlen(str) + 1) * sizeof(char));
    s21_strncpy(rezult, src, start_index);
    s21_strncpy(rezult + start_index, str, s21_strlen(str) - 1);
    s21_strncpy(rezult + start_index + s21_strlen(str) - 1, src + start_index,
                s21_strlen(src) - start_index + 1);
  } else if (str == NULL) {
    rezult = malloc(sizeof(src));
    s21_strncpy(rezult, src, s21_strlen(src));
  } else if (src == NULL && start_index == 0) {
    rezult = malloc(sizeof(str));
    s21_strncpy(rezult, str, s21_strlen(str));
  } else
    rezult = NULL;
  return (char *)rezult;
}
