#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(spec_f_1) {
  char res1[500], res2[500];
  char *pattern = "HELLO %f HELLO %f |||| %f _____ %f";
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

START_TEST(spec_f_2) {
  char res1[500], res2[500];
  char *pattern = "HELLO %20f HELLO %-11f |||| %50f _____ %123f";
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

START_TEST(spec_f_3) {
  char res1[500], res2[500];
  char *pattern = "HELLO %+20f HELLO %-11f |||| % 50f _____ %0123f";
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

START_TEST(spec_f_4) {
  char res1[500], res2[500];
  char *pattern = "HELLO %+ 20f HELLO %-011f |||| % 50.12f _____ %0123.100f";
  float a = 1.234;
  float b = -40.12437;
  float c = 40000.0;
  float d = 23;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_f_5) {
  char res1[500], res2[500];
  char *pattern =
      "HELLO %+ 20.2f HELLO %-011.4f |||| % 050.12f _____ %+-0123.100f";
  float a = 1.234;
  float b = -40.12437;
  float c = 40000.0;
  float d = 123.0;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_f_6) {
  char res1[500], res2[500];
  char *pattern =
      "HELLO %#+ 20.2f HELLO %#-011.4f |||| %# 050.12f _____ %+#-0123.100f";
  float a = 1.234;
  float b = -40.12437;
  float c = 40000.0;
  float d = 123.0;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_f_7) {
  char res1[500], res2[500];
  char *pattern = "HELLO %#+ 20.f HELLO %#f |||| %#f _____ %+#-0123.100f";
  float a = 1.234;
  float b = -40.12437;
  float c = 40000.0;
  float d = 123;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_f_8) {
  char res1[2000], res2[2000];
  char *pattern =
      "HELLO %#+ 20.2f HELLO %#-011.4f |||| %# 050.12lf _____ %+#-0123f";
  float a = 1.999999;
  float b = -2345.1236999;
  double c = 1294738457.1239821354;
  double d = -1294738457.1239821354;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_f_9) {
  char res1[2000], res2[2000];
  char *pattern =
      "HELLO %#+ 20.2f HELLO %#-011.4f |||| %# 050.12lf _____ %+#-0123f";
  float a = 1;
  float b = -2345.36999;
  double c = 12.124;
  double d = -1.1239821354;
  int str = sprintf(res1, pattern, a, b, c, d);
  int s21 = s21_sprintf(res2, pattern, a, b, c, d);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

Suite *S21SprintfSpecFSuiteTestCreate(void) {
  Suite *suite = suite_create("s21_printf_spec_f tests");
  TCase *tcaseCore = tcase_create("Core of example");
  tcase_add_test(tcaseCore, spec_f_1);
  tcase_add_test(tcaseCore, spec_f_2);
  tcase_add_test(tcaseCore, spec_f_3);
  tcase_add_test(tcaseCore, spec_f_4);
  tcase_add_test(tcaseCore, spec_f_5);
  tcase_add_test(tcaseCore, spec_f_6);
  tcase_add_test(tcaseCore, spec_f_7);
  tcase_add_test(tcaseCore, spec_f_8);
  tcase_add_test(tcaseCore, spec_f_9);

  suite_add_tcase(suite, tcaseCore);

  return suite;
}

int main(void) {
  Suite *suite = S21SprintfSpecFSuiteTestCreate();
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