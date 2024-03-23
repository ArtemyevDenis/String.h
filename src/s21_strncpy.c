
#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  int k = 0;
  if (n > s21_strlen(src)) n = s21_strlen(src);
  for (s21_size_t i = 0; i < n; i++) {
    k++;
    dest[i] = src[i];
  }
  dest[k] = '\0';
  return dest;
}