#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(spec_x_1) {
  char res1[500], res2[500];
  char *pattern = "HELLO %x HELLO %x |||| %x _____ %x";
  unsigned int a = 1;
  unsigned int b = 4012437;
  unsigned int c = 400123;
  unsigned int d = 0;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_x_2) {
  char res1[500], res2[500];
  char *pattern = "HELLO %+20x HELLO %-20x |||| % 20x _____ %+20x";
  unsigned int a = 1;
  unsigned int b = 4012437;
  unsigned int c = 400123;
  unsigned int d = 0;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_x_3) {
  char res1[500], res2[500];
  char *pattern = "HELLO %+020x HELLO %-020x |||| % 20.40x _____ %+- 020.20x";
  unsigned int a = 1;
  unsigned int b = 4012437;
  unsigned int c = 400123;
  unsigned int d = 0;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_x_4) {
  char res1[500], res2[500];
  char *pattern =
      "HELLO % +-020.40x HELLO %-020lX |||| % 20.40llx _____ %+- 020.20X";
  unsigned int a = 1;
  unsigned long int b = 4012437;
  unsigned long long int c = 400123;
  unsigned int d = 0;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_x_5) {
  char res1[500], res2[500];
  char *pattern =
      "HELLO % +-020.40X HELLO %-020lX |||| % 20.40llx _____ %+- 020.20x";
  unsigned int a = -1;
  unsigned long int b = 4012437;
  unsigned long long int c = -400123;
  unsigned int d = 0;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_x_6) {
  char res1[500], res2[500];
  char *pattern =
      "HELLO % +-020.40X HELLO %-020lx |||| % 20.40llX _____ %+- 020.20X";
  unsigned int a = 65536;
  unsigned long int b = 9223372036854775807;
  unsigned long long int c = 400123;
  unsigned int d = 0;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_x_7) {
  char res1[500], res2[500];
  char *pattern =
      "HELLO % +-020.40x HELLO %-#020lX |||| % #20.40llx _____ %+- 020.20X";
  unsigned int a = 1;
  unsigned long int b = 4012437;
  unsigned long long int c = 400123;
  unsigned int d = 0;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_x_8) {
  char res1[500], res2[500];
  char *pattern =
      "HELLO %# +-020.40X HELLO %#-020lX |||| %# 20.40llx _____ %+- 020.20x";
  unsigned int a = -1;
  unsigned long int b = 4012437;
  unsigned long long int c = -400123;
  unsigned int d = 0;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_x_9) {
  char res1[500], res2[500];
  char *pattern =
      "HELLO %# +-020.40X HELLO %#-020lx |||| % 20.40llX _____ %#+- 020.20X";
  unsigned int a = 65536;
  unsigned long int b = 9223372036854775807;
  unsigned long long int c = 400123;
  unsigned int d = 0;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

Suite *S21SprintfSpecXSuiteTestCreate(void) {
  Suite *suite = suite_create("s21_printf_spec_x tests");
  TCase *tcaseCore = tcase_create("Core of example");
  tcase_add_test(tcaseCore, spec_x_1);
  tcase_add_test(tcaseCore, spec_x_2);
  tcase_add_test(tcaseCore, spec_x_3);
  tcase_add_test(tcaseCore, spec_x_4);
  tcase_add_test(tcaseCore, spec_x_5);
  tcase_add_test(tcaseCore, spec_x_6);
  tcase_add_test(tcaseCore, spec_x_7);
  tcase_add_test(tcaseCore, spec_x_8);
  tcase_add_test(tcaseCore, spec_x_9);

  suite_add_tcase(suite, tcaseCore);

  return suite;
}

int main(void) {
  Suite *suite = S21SprintfSpecXSuiteTestCreate();
  SRunner *suiteRunner = srunner_create(suite);
  int failedCount = 0;

  srunner_run_all(suiteRunner, CK_NORMAL);
  failedCount = srunner_ntests_failed(suiteRunner);
  srunner_free(suiteRunner);

  if (failedCount != 0) {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}