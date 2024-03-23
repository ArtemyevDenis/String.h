#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(spec_p_1) {
  char res1[500], res2[500];
  char *pattern = "HELLO %p HELLO %p |||| %p _____ %p";
  unsigned int a = 1;
  unsigned int b = 4012437;
  unsigned int c = 400123;
  unsigned int d = 0;
  int str = sprintf(res1, pattern, &a, &b, &c, &d);
  int s21 = s21_sprintf(res2, pattern, &a, &b, &c, &d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_p_2) {
  char res1[500], res2[500];
  char *pattern = "HELLO %+20p HELLO %-20p |||| % 20p _____ %+20p";
  int a = 1;
  int b = 4012437;
  int c = 400123;
  int d = 0;
  int str = sprintf(res1, pattern, &a, &b, &c, &d);
  int s21 = s21_sprintf(res2, pattern, &a, &b, &c, &d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_p_3) {
  char res1[500], res2[500];
  char *pattern = "HELLO %+020p HELLO %-020p |||| % 20.40p _____ %+- 020.20p";
  float a = 1;
  float b = 4012437;
  float c = 400123;
  float d = 0;
  int str = sprintf(res1, pattern, &a, &b, &c, &d);
  int s21 = s21_sprintf(res2, pattern, &a, &b, &c, &d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_p_4) {
  char res1[500], res2[500];
  char *pattern =
      "HELLO % +-020.40p HELLO %-020p |||| % 20.40p _____ %+- 020.20p";
  char a = 1;
  char b = 250;
  char c = 50;
  char d = 0;
  int str = sprintf(res1, pattern, &a, &b, &c, &d);
  int s21 = s21_sprintf(res2, pattern, &a, &b, &c, &d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_p_5) {
  char res1[500], res2[500];
  char *pattern =
      "HELLO %# +-020.40p HELLO %#-020p |||| % 20.40p _____ %#+- 020.20p";
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

START_TEST(spec_p_6) {
  char res1[500], res2[500];
  char *pattern =
      "HELLO % +-020.40p HELLO %-020p |||| % 20.40p _____ %+- 020.20p";
  char *a = "Hello";
  char *b = "World";
  char *c = "AHAHAH";
  unsigned int d = 0;
  int str = sprintf(res1, pattern, a, b, c, &d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, &d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_p_7) {
  char res1[500], res2[500];
  char *pattern =
      "HELLO % +-020.40p HELLO %-#020p |||| % #20.40p _____ %+- 020.20p";
  char *a = NULL;
  char *b = NULL;
  char *c = NULL;
  char *d = NULL;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

Suite *S21SprintfSpecPSuiteTestCreate(void) {
  Suite *suite = suite_create("s21_printf_spec_p tests");
  TCase *tcaseCore = tcase_create("Core of eoample");
  tcase_add_test(tcaseCore, spec_p_1);
  tcase_add_test(tcaseCore, spec_p_2);
  tcase_add_test(tcaseCore, spec_p_3);
  tcase_add_test(tcaseCore, spec_p_4);
  tcase_add_test(tcaseCore, spec_p_5);
  tcase_add_test(tcaseCore, spec_p_6);
  tcase_add_test(tcaseCore, spec_p_7);

  suite_add_tcase(suite, tcaseCore);

  return suite;
}

int main(void) {
  Suite *suite = S21SprintfSpecPSuiteTestCreate();
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