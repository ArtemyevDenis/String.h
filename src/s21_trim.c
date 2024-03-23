#include "s21_string.h"

void WorkingWithTrimChars(char chars[512], const char* trim_chars) {
  if (trim_chars[0] == '\0') {
    chars[0] = ' ';
    chars[1] = '\t';
    chars[2] = '\0';
  } else {
    int k = 0;
    for (s21_size_t i = 0; i < s21_strlen(trim_chars); i++) {
      chars[i] = trim_chars[i];
      k++;
    }
    chars[k] = '\0';
  }
}

void CheckTrimCHars(const char* src, char chars[512], int* k, int* l) {
  int p = *k, flag = 0;
  while (src[p] != '\0' && flag == 0) {
    for (s21_size_t z = 0; z < s21_strlen(chars); z++) {
      if (src[p] == chars[z]) (*k)++;
    }
    if ((*k) == p) flag = 1;
    p++;
  }
  flag = 0;
  int q = *l;
  while (q >= 0 && flag == 0) {
    for (s21_size_t z = 0; z < s21_strlen(chars); z++) {
      if (src[q] == chars[z]) (*l)--;
    }
    if ((*l) == q) flag = 1;
    q--;
  }
}

void* s21_trim(const char* src, const char* trim_chars) {
  char* new_str = NULL;
  char chars[512];
  if (src && trim_chars)
    new_str = (char*)malloc((s21_strlen(src) + 1) * sizeof(char));
  if (new_str && trim_chars && src) {
    WorkingWithTrimChars(chars, trim_chars);
    int l = s21_strlen(src) - 1, k = 0, d = 0;
    CheckTrimCHars(src, chars, &k, &l);
    for (s21_size_t i = k; (int)i <= l; i++) {
      new_str[d] = src[i];
      d++;
    }
    new_str[d] = '\0';
  }
  return new_str;
}