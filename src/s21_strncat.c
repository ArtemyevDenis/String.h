#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t start = s21_strlen(dest);
  if (n > s21_strlen(src)) n = s21_strlen(src);
  s21_size_t end = start + n;
  int k = 0;
  while (start < end) {
    dest[start] = src[k];
    k++;
    start++;
  }
  dest[start] = '\0';
  return dest;
}