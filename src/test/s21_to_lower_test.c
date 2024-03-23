#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(low_1) {
  char *str = NULL;
  ck_assert_ptr_null(s21_to_lower(str));
}
END_TEST

START_TEST(low_2) {
  char *str = "";
  char *q = s21_to_lower(str);
  ck_assert_str_eq(q, "");
  free(q);
}
END_TEST

START_TEST(low_3) {
  char *str = "HELLO WORLD";
  char *q = s21_to_lower(str);
  ck_assert_str_eq(q, "hello world");
  free(q);
}
END_TEST

START_TEST(low_4) {
  char *str = "HElLO \0WORLD";
  char *q = s21_to_lower(str);
  ck_assert_str_eq(q, "hello ");
  free(q);
}
END_TEST

START_TEST(low_5) {
  char *str = "`heLlo {woRLd";
  char *q = s21_to_lower(str);
  ck_assert_str_eq(q, "`hello {world");
  free(q);
}
END_TEST

START_TEST(low_6) {
  char *str = "123534365543&^#$^&&$#";
  char *q = s21_to_lower(str);
  ck_assert_str_eq(q, "123534365543&^#$^&&$#");
  free(q);
}
END_TEST

START_TEST(low_7) {
  char *str = "AaSdFfSZ \n \t ";
  char *q = s21_to_lower(str);
  ck_assert_str_eq(q, "aasdffsz \n \t ");
  free(q);
}
END_TEST

Suite *S21ToLowerSuiteTestCreate(void) {
  Suite *suite = suite_create("s21_to_lower tests");
  TCase *tcaseCore = tcase_create("");
  tcase_add_test(tcaseCore, low_1);
  tcase_add_test(tcaseCore, low_2);
  tcase_add_test(tcaseCore, low_3);
  tcase_add_test(tcaseCore, low_4);
  tcase_add_test(tcaseCore, low_5);
  tcase_add_test(tcaseCore, low_6);
  tcase_add_test(tcaseCore, low_7);

  suite_add_tcase(suite, tcaseCore);

  return suite;
}

int main(void) {
  Suite *suite = S21ToLowerSuiteTestCreate();
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