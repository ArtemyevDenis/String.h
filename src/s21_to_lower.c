#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *new_str = NULL;
  int k = 0;
  if (str) new_str = (char *)malloc((s21_strlen(str) + 1) * sizeof(char));
  if (new_str) {
    if (str[0] == '\0')
      new_str[0] = '\0';
    else {
      for (s21_size_t i = 0; i < s21_strlen(str); i++) {
        k++;
        if (str[i] > 64 && str[i] < 91)
          new_str[i] = str[i] + 32;
        else
          new_str[i] = str[i];
      }
      new_str[k] = '\0';
    }
  }
  return new_str;
}