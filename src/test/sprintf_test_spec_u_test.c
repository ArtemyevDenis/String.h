#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(spec_u_1) {
  char res1[500], res2[500];
  char *pattern = "HELLO %u HELLO %u |||| %u _____ %u";
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

START_TEST(spec_u_2) {
  char res1[500], res2[500];
  char *pattern = "HELLO %20u HELLO %-20u |||| % 20u _____ %+20u";
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

START_TEST(spec_u_3) {
  char res1[500], res2[500];
  char *pattern = "HELLO %+020u HELLO %-020u |||| % 20.40u _____ %+- 020.20u";
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

START_TEST(spec_u_4) {
  char res1[500], res2[500];
  char *pattern =
      "HELLO % +-020.40u HELLO %-020lu |||| % 20.40llu _____ %+- 020.20u";
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

START_TEST(spec_u_5) {
  char res1[500], res2[500];
  char *pattern =
      "HELLO % +-020.40u HELLO %-020lu |||| % 20.40llu _____ %+- 020.20u";
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

START_TEST(spec_u_6) {
  char res1[500], res2[500];
  char *pattern =
      "HELLO % +-020.40u HELLO %-020lu |||| % 20.40llu _____ %+- 020.20u";
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

Suite *S21SprintfSpecUSuiteTestCreate(void) {
  Suite *suite = suite_create("s21_printf_spec_u tests");
  TCase *tcaseCore = tcase_create("Core of example");
  tcase_add_test(tcaseCore, spec_u_1);
  tcase_add_test(tcaseCore, spec_u_2);
  tcase_add_test(tcaseCore, spec_u_3);
  tcase_add_test(tcaseCore, spec_u_4);
  tcase_add_test(tcaseCore, spec_u_5);
  tcase_add_test(tcaseCore, spec_u_6);

  suite_add_tcase(suite, tcaseCore);

  return suite;
}

int main(void) {
  Suite *suite = S21SprintfSpecUSuiteTestCreate();
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