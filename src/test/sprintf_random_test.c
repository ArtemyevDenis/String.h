#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(rand_1) {
  char res1[500], res2[500];
  char *pattern = "HELLO %c HELLO %u |||| %f _____ %i";
  char a = 1;
  unsigned int b = 4012437;
  float c = 400.46;
  int d = -2340;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(rand_2) {
  char res1[500], res2[500];
  char *pattern = "HELLO %20c HELLO %-40u |||| %20.12f _____ %123.i";
  char a = 1;
  unsigned int b = 4012437;
  float c = 400.46;
  int d = -2340;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(rand_3) {
  char res1[500], res2[500];
  char *pattern = "HELLO %20c HELLO %+ -40u |||| % +-20.12f _____ % 0123.i";
  char a = 1;
  unsigned int b = 4012437;
  float c = 400.46;
  int d = -2340;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(rand_4) {
  char res1[500], res2[500];
  char *pattern = "HELLO %*c HELLO %+ -40u |||| % +-20.*f _____ % 0123.i";
  char a = 1;
  unsigned int b = 4012437;
  float c = 400.46;
  int d = -2340;
  int str = sprintf(res1, pattern, 20, a, b, 12, c, d);
  int s21 = s21_sprintf(res2, pattern, 20, a, b, 12, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(rand_5) {
  char res1[500], res2[500];
  char *pattern = "HELLO %*c HELLO %+ -40u |||| % +-20.*f _____ % 0123.i";
  char a = 1;
  unsigned int b = 4012437;
  float c = 400.46;
  int d = -2340;
  int str = sprintf(res1, pattern, -20, a, b, 0, c, d);
  int s21 = s21_sprintf(res2, pattern, -20, a, b, 0, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(rand_6) {
  char res1[500], res2[500];
  char *pattern = "HELLO %*x HELLO %+ -40o |||| % +-20.*f _____ % 0123.i";
  unsigned int a = 1;
  unsigned int b = 4012437;
  float c = 400.46;
  int d = -2340;
  int str = sprintf(res1, pattern, -20, a, b, 0, c, d);
  int s21 = s21_sprintf(res2, pattern, -20, a, b, 0, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(rand_7) {
  char res1[500], res2[500];
  char *pattern = "HELLO %#*X HELLO %#+ -40o |||| %# +-20.*f _____ %# 0123.i";
  unsigned int a = 1;
  unsigned int b = 4012437;
  float c = 400.46;
  int d = -2340;
  int str = sprintf(res1, pattern, -20, a, b, 0, c, d);
  int s21 = s21_sprintf(res2, pattern, -20, a, b, 0, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

Suite *S21SprintfRandSuiteTestCreate(void) {
  Suite *suite = suite_create("s21_printf_rand tests");
  TCase *tcaseCore = tcase_create("Core of eoample");
  tcase_add_test(tcaseCore, rand_1);
  tcase_add_test(tcaseCore, rand_2);
  tcase_add_test(tcaseCore, rand_3);
  tcase_add_test(tcaseCore, rand_4);
  tcase_add_test(tcaseCore, rand_5);
  tcase_add_test(tcaseCore, rand_6);
  tcase_add_test(tcaseCore, rand_7);

  suite_add_tcase(suite, tcaseCore);

  return suite;
}

int main(void) {
  Suite *suite = S21SprintfRandSuiteTestCreate();
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