#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(percent_1) {
  char res1[500], res2[500];
  char *pattern = "HELLO %% HELLO %12345% |||| %+ 0-12345% _____ %% %c %%";
  int str = sprintf(res1, pattern, 'a');
  int s21 = s21_sprintf(res2, pattern, 'a');
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(str, s21);
}
END_TEST

Suite *S21PerecntSuiteTestCreate(void) {
  Suite *suite = suite_create("s21_printf_percenttests");
  TCase *tcaseCore = tcase_create("Core of example");
  tcase_add_test(tcaseCore, percent_1);

  suite_add_tcase(suite, tcaseCore);

  return suite;
}

int main(void) {
  Suite *suite = S21PerecntSuiteTestCreate();
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