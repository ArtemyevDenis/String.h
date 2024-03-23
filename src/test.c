#include <string.h>
#include "s21_string.h"

int main(){
  char res1[500], res2[500];
  char *pattern = "HELLO %g HELLO %g |||| %g _____ %g";
  float a = 1.234;
  float b = -40.12437;
  float c = 40000.0;
  float d = 0.00123;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
}