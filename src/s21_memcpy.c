#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t count) {
  const unsigned char *copy_src = (unsigned char *)src;
  unsigned char *copy_dest = (unsigned char *)dest;
  for (s21_size_t i = 0; i < count; i++) {
    copy_dest[i] = copy_src[i];
  }
  return dest;
}