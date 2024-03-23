#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t needle_len = s21_strlen(needle);
  if (needle_len == 0) {
    return (char *)haystack;
  }

  while (*haystack != '\0') {
    if (*haystack == *needle) {
      const char *p1 = haystack;
      const char *p2 = needle;
      s21_size_t matched = 0;
      while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) {
        matched++;
        p1++;
        p2++;
      }
      if (matched == needle_len) {
        return (char *)haystack;
      }
    }
    haystack++;
  }
  return NULL;
}