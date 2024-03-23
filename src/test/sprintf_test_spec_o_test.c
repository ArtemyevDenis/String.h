#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(spec_o_1) {
  char res1[500], res2[500];
  char *pattern = "HELLO %o HELLO %o |||| %o _____ %o";
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

START_TEST(spec_o_2) {
  char res1[500], res2[500];
  char *pattern = "HELLO %+20o HELLO %-20o |||| % 20o _____ %+20o";
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

START_TEST(spec_o_3) {
  char res1[500], res2[500];
  char *pattern = "HELLO %+020o HELLO %-020o |||| % 20.40o _____ %+- 020.20o";
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

START_TEST(spec_o_4) {
  char res1[500], res2[500];
  char *pattern =
      "HELLO % +-020.40o HELLO %-020lo |||| % 20.40llo _____ %+- 020.20o";
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

START_TEST(spec_o_5) {
  char res1[500], res2[500];
  char *pattern =
      "HELLO % +-020.40o HELLO %-020lo |||| % 20.40llo _____ %+- 020.20o";
  unsigned int a = -1;
  unsigned long int b = 4012437;
  unsigned long long int c = 400123;
  unsigned int d = 0;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_o_6) {
  char res1[500], res2[500];
  char *pattern =
      "HELLO % +-020.40o HELLO %-020lo |||| % 20.40llo _____ %+- 020.20o";
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

START_TEST(spec_o_7) {
  char res1[500], res2[500];
  char *pattern =
      "HELLO % +-020.40o HELLO %-#020lo |||| % #20.40llo _____ %+- 020.20o";
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

START_TEST(spec_o_8) {
  char res1[500], res2[500];
  char *pattern =
      "HELLO %# +-020.40o HELLO %#-020lo |||| %# 20.40llo _____ %+- 020.20o";
  unsigned int a = -1;
  unsigned long int b = 4012437;
  unsigned long long int c = 400123;
  unsigned int d = 0;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_o_9) {
  char res1[500], res2[500];
  char *pattern =
      "HELLO %# +-020.40o HELLO %#-020lo |||| % 20.40llo _____ %#+- 020.20o";
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

Suite *S21SprintfSpecOSuiteTestCreate(void) {
  Suite *suite = suite_create("s21_printf_spec_o tests");
  TCase *tcaseCore = tcase_create("Core of eoample");
  tcase_add_test(tcaseCore, spec_o_1);
  tcase_add_test(tcaseCore, spec_o_2);
  tcase_add_test(tcaseCore, spec_o_3);
  tcase_add_test(tcaseCore, spec_o_4);
  tcase_add_test(tcaseCore, spec_o_5);
  tcase_add_test(tcaseCore, spec_o_6);
  tcase_add_test(tcaseCore, spec_o_7);
  tcase_add_test(tcaseCore, spec_o_8);
  tcase_add_test(tcaseCore, spec_o_9);

  suite_add_tcase(suite, tcaseCore);

  return suite;
}

int main(void) {
  Suite *suite = S21SprintfSpecOSuiteTestCreate();
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