#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(spec_s_1) {
  char res1[500], res2[500];
  char *pattern = "HELLO %s HELLO %s |||| %s _____ %s";
  char *s = "World ";
  int str = sprintf(res1, pattern, s, s, s, s);
  int s21 = s21_sprintf(res2, pattern, s, s, s, s);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_s_2) {
  char res1[500], res2[500];
  char *pattern = "HELLO \t%20s HELLO \n%-20s |||| %040s _____ %+100s";
  char *s = "World ";
  int str = sprintf(res1, pattern, s, s, s, s);
  int s21 = s21_sprintf(res2, pattern, s, s, s, s);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_s_3) {
  char res1[500], res2[500];
  char *pattern = "HELLO \t%20s HELLO \0\n%-20s |||| %040s _____ %+100s";
  char *s = "World ";
  int str = sprintf(res1, pattern, s, s, s, s);
  int s21 = s21_sprintf(res2, pattern, s, s, s, s);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_s_4) {
  char res1[500], res2[500];
  char *pattern = "HELLO \t%20s HELLO \0\n%-20s |||| %040s _____ %+100s";
  char *s = "Wor\0ld ";
  int str = sprintf(res1, pattern, s, s, s, s);
  int s21 = s21_sprintf(res2, pattern, s, s, s, s);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_s_5) {
  char res1[500], res2[500];
  char *pattern = "HELLO \t%20s HELLO \0\n%-20s |||| %040s _____ %+100s";
  char *s = "";
  int str = sprintf(res1, pattern, s, s, s, s);
  int s21 = s21_sprintf(res2, pattern, s, s, s, s);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

START_TEST(spec_s_6) {
  char res1[500], res2[500];
  char *pattern = "HELLO \t%20s HELLO \0\n%-20s |||| %040s _____ %+100s";
  char *s = "\n \t";
  int str = sprintf(res1, pattern, s, s, s, s);
  int s21 = s21_sprintf(res2, pattern, s, s, s, s);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

Suite *S21SprintfSpecSSuiteTestCreate(void) {
  Suite *suite = suite_create("s21_printf_spec_s tests");
  TCase *tcaseCore = tcase_create("Core of example");
  tcase_add_test(tcaseCore, spec_s_1);
  tcase_add_test(tcaseCore, spec_s_2);
  tcase_add_test(tcaseCore, spec_s_3);
  tcase_add_test(tcaseCore, spec_s_4);
  tcase_add_test(tcaseCore, spec_s_5);
  tcase_add_test(tcaseCore, spec_s_6);

  suite_add_tcase(suite, tcaseCore);

  return suite;
}

int main(void) {
  Suite *suite = S21SprintfSpecSSuiteTestCreate();
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