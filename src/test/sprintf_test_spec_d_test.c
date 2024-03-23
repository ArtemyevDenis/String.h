#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(spec_d_1) {
  char res1[500], res2[500];
  char *pattern = "HELLO %d HELLO %d |||| %d _____ %d";
  int a = 40;
  int b = -40;
  int c = 40000;
  int d = 3475862;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_d_2) {
  char res1[500], res2[500];
  char *pattern = "HELLO %20d HELLO %-20d |||| % d _____ %+-40d";
  int a = 40;
  int b = -40;
  int c = 40000;
  int d = 3475862;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_d_3) {
  char res1[500], res2[500];
  char *pattern = "HELLO %+ 20d HELLO %-020d |||| % .60d _____ %0-40.20d";
  int a = 40;
  int b = -40;
  int c = 40000;
  int d = 3475862;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_d_4) {
  char res1[500], res2[500];
  char *pattern = "HELLO %+ 020.40d HELLO %-020d |||| % .60d _____ %0-40.20d";
  int a = 40;
  int b = -40;
  int c = 40000;
  int d = 3475862;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_d_5) {
  char res1[500], res2[500];
  char *pattern = "HELLO %+ 0*.40d HELLO %-020d |||| % .*d _____ %0-40.20d";
  int a = 40;
  int b = -40;
  int c = 40000;
  int d = 3475862;
  int str = sprintf(res1, pattern, 20, 60, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, 20, 60, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_d_6) {
  char res1[500], res2[500];
  char *pattern = "HELLO %+ 0.40hd HELLO %-020d |||| % .0ld _____ %0-40.20lld";
  short a = 32767;
  int b = -2147483647;
  long int c = 223372036854775807;
  long long int d = -9223372036854775807;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_d_7) {
  char res1[500], res2[500];
  char *pattern = "HELLO %+ 0.40hd HELLO %-020d |||| % .0ld _____ %0-40.20lld";
  int a = 327;
  int b = -2183647;
  long int c = 807;
  long long int d = -9;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_d_8) {
  char res1[500], res2[500];
  char *pattern = "HELLO %+ 0.40hd HELLO %-020d |||| % .0ld _____ %0-40.20lld";
  int a = 33000;
  long b = -2247483647;
  long long int c = 223382036854775807;
  long long int d = 9223372036854775807;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_d_9) {
  char res1[500], res2[500];
  char *pattern =
      "HELLO %+ 20.40hd HELLO %-020d |||| % 02.0ld _____ %0-40.20lld";
  int a = 33000;
  long b = -2247483647;
  long long int c = 223382036854775807;
  long long int d = 9223372036854775807;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_d_10) {
  char res1[500], res2[500];
  char *pattern = "HELLO %+ 0.40hd HELLO %-020d |||| % .0ld _____ %0-40.20lld";
  int a = 0;
  long b = 0;
  long long int c = 0;
  long long int d = 0;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

Suite *S21SprintfSpecDSuiteTestCreate(void) {
  Suite *suite = suite_create("s21_printf_spec_d tests");
  TCase *tcaseCore = tcase_create("Core of example");
  tcase_add_test(tcaseCore, spec_d_1);
  tcase_add_test(tcaseCore, spec_d_2);
  tcase_add_test(tcaseCore, spec_d_3);
  tcase_add_test(tcaseCore, spec_d_4);
  tcase_add_test(tcaseCore, spec_d_5);
  tcase_add_test(tcaseCore, spec_d_6);
  tcase_add_test(tcaseCore, spec_d_7);
  tcase_add_test(tcaseCore, spec_d_8);
  tcase_add_test(tcaseCore, spec_d_9);
  tcase_add_test(tcaseCore, spec_d_10);

  suite_add_tcase(suite, tcaseCore);

  return suite;
}

int main(void) {
  Suite *suite = S21SprintfSpecDSuiteTestCreate();
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