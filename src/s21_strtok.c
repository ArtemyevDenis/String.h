#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *nextToken = s21_NULL;

  if (str != s21_NULL) {
    nextToken = str;
  } else if (nextToken == s21_NULL) {
    return s21_NULL;
  }

  char *start = nextToken;
  char *end = nextToken;

  while (*end != '\0') {
    const char *d = delim;
    while (*d != '\0') {
      if (*end == *d) {
        if (start == end) {
          start++;
        } else {
          *end = '\0';
          nextToken = end + 1;
          return start;
        }
      }
      d++;
    }
    end++;
  }

  if (start == end) {
    nextToken = s21_NULL;
    return s21_NULL;
  } else {
    nextToken = end;
    return start;
  }
}