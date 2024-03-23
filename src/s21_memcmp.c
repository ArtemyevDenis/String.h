#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int char_compare_status = 0;
  if (str1 && str2) {
    const unsigned char *arr_1 = (unsigned char *)str1;
    const unsigned char *arr_2 = (unsigned char *)str2;
    s21_size_t flag = 1;
    if (arr_1 == arr_2) {
      flag = 0;
    }
    while (n > 0 && flag) {
      if (*arr_1 != *arr_2) {
        char_compare_status = *arr_1 - *arr_2;
        flag = 0;
      }
      n--;
      arr_1++;
      arr_2++;
    }
  }
  return char_compare_status;
}