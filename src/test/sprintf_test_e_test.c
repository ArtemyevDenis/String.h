#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(spec_e_1) {
  char res1[500], res2[500];
  char *pattern = "HELLO %e HELLO %E |||| %E _____ %e";
  float a = 1.234;
  float b = -40.12437;
  float c = 40000.0;
  float d = 0.00123;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_e_2) {
  char res1[500], res2[500];
  char *pattern = "HELLO %20E HELLO %-11E |||| %50e _____ %123E";
  float a = 1.234;
  float b = -40.12437;
  float c = 40000.0;
  float d = 0.00123;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST
START_TEST(spec_e_3) {
  char res1[500], res2[500];
  char *pattern = "HELLO %20e HELLO %-20e |||| %.10e _____ %+10e";
  float a = 1124567.234;
  float b = -40.12437;
  float c = 40000.0;
  float d = 0.00123;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_e_4) {
  char res1[500], res2[500];
  char *pattern = "HELLO %-20e HELLO %- +20e |||| %+#.10e _____ %010e";
  float a = 1124567.234;
  float b = -40.12437;
  float c = 400;
  float d = 0.0102340123;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_e_5) {
  char res1[500], res2[500];
  char *pattern = "HELLO %-20e HELLO %- +20e |||| %+#.10e _____ %010e";
  float a = 1124567.234;
  float b = -40.12437;
  float c = 40000;
  float d = 0.0102340123;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

Suite *S21SprintfSpecESuiteTestCreate(void) {
  Suite *suite = suite_create("s21_printf_spec_e tests");
  TCase *tcaseCore = tcase_create("Core of example");
  tcase_add_test(tcaseCore, spec_e_1);
  tcase_add_test(tcaseCore, spec_e_2);
  tcase_add_test(tcaseCore, spec_e_3);
  tcase_add_test(tcaseCore, spec_e_4);
  tcase_add_test(tcaseCore, spec_e_5);

  suite_add_tcase(suite, tcaseCore);

  return suite;
}

int main(void) {
  Suite *suite = S21SprintfSpecESuiteTestCreate();
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