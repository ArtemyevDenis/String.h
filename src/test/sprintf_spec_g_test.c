#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(spec_g_1) {
  char res1[500], res2[500];
  char *pattern = "HELLO %g HELLO %g |||| %g _____ %g";
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

START_TEST(spec_g_2) {
  char res1[500], res2[500];
  char *pattern = "HELLO %20G HELLO %-11g |||| %50G _____ %123G";
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
START_TEST(spec_g_3) {
  char res1[500], res2[500];
  char *pattern = "HELLO %20G HELLO %-20G |||| %.10g _____ %+10g";
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

START_TEST(spec_g_4) {
  char res1[500], res2[500];
  char *pattern = "HELLO %-20G HELLO %- +20G |||| %+#.10G _____ %010G";
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

START_TEST(spec_g_5) {
  char res1[500], res2[500];
  char *pattern = "HELLO %-20G HELLO %- +20G |||| %+#.10g _____ %010g";
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

START_TEST(spec_g_6) {
  char res1[500], res2[500];
  char *pattern = "HELLO %-20.G HELLO %- +20.0G |||| %+#.10g _____ %010g";
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

Suite *S21SprintfSpecgSuiteTestCreate(void) {
  Suite *suite = suite_create("s21_printf_spec_g tests");
  TCase *tcaseCore = tcase_create("Core of example");
  tcase_add_test(tcaseCore, spec_g_1);
  tcase_add_test(tcaseCore, spec_g_2);
  tcase_add_test(tcaseCore, spec_g_3);
  tcase_add_test(tcaseCore, spec_g_4);
  tcase_add_test(tcaseCore, spec_g_5);
  tcase_add_test(tcaseCore, spec_g_6);

  suite_add_tcase(suite, tcaseCore);

  return suite;
}

int main(void) {
  Suite *suite = S21SprintfSpecgSuiteTestCreate();
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