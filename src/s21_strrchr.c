#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *last = NULL;
  while (*str != '\0') {
    if (*str == c) {
      last = str;
    }
    str++;
  }
  return (char *)last;
}
