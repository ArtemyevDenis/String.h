#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *new_str = NULL;
  if (src && str && start_index <= s21_strlen(src)) {
    new_str =
        (char *)malloc((s21_strlen(src) + s21_strlen(str) + 2) * sizeof(char));
  }
  if (new_str && start_index <= s21_strlen(src)) {
    s21_size_t i = 0;
    while (i < start_index && src[i] != '\0') {
      new_str[i] = src[i];
      i++;
    }
    s21_size_t k = 0;
    while (k < s21_strlen(str)) {
      new_str[i + k] = str[k];
      k++;
    }
    while (src[i] != '\0') {
      new_str[i + k] = src[i];
      i++;
    }
    new_str[i + k] = '\0';
  }
  return new_str;
}