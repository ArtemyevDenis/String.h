#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(spec_c_1) {
  char res1[500], res2[500];
  char *pattern = "HELLO %c HELLO %c |||| %c _____ %c";
  int c = 40;
  int str = sprintf(res1, pattern, c, c, c, c);
  int s21 = s21_sprintf(res2, pattern, c, c, c, c);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_c_2) {
  char res1[500], res2[500];
  char *pattern = "HELLO %20c HELLO %-20c |||| %10c _____ %2c";
  int c = 40;
  int str = sprintf(res1, pattern, c, c, c, c);
  int s21 = s21_sprintf(res2, pattern, c, c, c, c);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_c_3) {
  char res1[500], res2[500];
  char *pattern = "HELLO %020c HELLO % -20c |||| %+10c _____ %.2c";
  int c = 40;
  int str = sprintf(res1, pattern, c, c, c, c);
  int s21 = s21_sprintf(res2, pattern, c, c, c, c);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_c_4) {
  char res1[500], res2[500];
  char *pattern = "HELLO %020c HELLO % -20c |||| %+10c _____ %.2c";
  int c = 0;
  int str = sprintf(res1, pattern, c, c, c, c);
  int s21 = s21_sprintf(res2, pattern, c, c, c, c);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_c_5) {
  char res1[500], res2[500];
  char *pattern = "HELLO %020c HELLO % -20c |||| %+10c _____ %.2c";
  int c = 200;
  int str = sprintf(res1, pattern, c, c, c, c);
  int s21 = s21_sprintf(res2, pattern, c, c, c, c);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_c_6) {
  char res1[500], res2[500];
  char *pattern = "HELLO %020c HELLO % -20c |||| %+10c _____ %.2c";
  int c = -1;
  int str = sprintf(res1, pattern, c, c, c, c);
  int s21 = s21_sprintf(res2, pattern, c, c, c, c);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

Suite *S21SprintfSpecCSuiteTestCreate(void) {
  Suite *suite = suite_create("s21_printf_spec_c tests");
  TCase *tcaseCore = tcase_create("Core of example");
  tcase_add_test(tcaseCore, spec_c_1);
  tcase_add_test(tcaseCore, spec_c_2);
  tcase_add_test(tcaseCore, spec_c_3);
  tcase_add_test(tcaseCore, spec_c_4);
  tcase_add_test(tcaseCore, spec_c_5);
  tcase_add_test(tcaseCore, spec_c_6);

  suite_add_tcase(suite, tcaseCore);

  return suite;
}

int main(void) {
  Suite *suite = S21SprintfSpecCSuiteTestCreate();
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