#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(up_1) {
  char *str = NULL;
  ck_assert_ptr_null(s21_to_upper(str));
}
END_TEST

START_TEST(up_2) {
  char *str = "";
  char *q = s21_to_upper(str);
  ck_assert_str_eq(q, "");
  free(q);
}
END_TEST

START_TEST(up_3) {
  char *str = "hello world";
  char *q = s21_to_upper(str);
  ck_assert_str_eq(q, "HELLO WORLD");
  free(q);
}
END_TEST

START_TEST(up_4) {
  char *str = "hello \0world";
  char *q = s21_to_upper(str);
  ck_assert_str_eq(q, "HELLO ");
  free(q);
}
END_TEST

START_TEST(up_5) {
  char *str = "`hello {world";
  char *q = s21_to_upper(str);
  ck_assert_str_eq(q, "`HELLO {WORLD");
  free(q);
}
END_TEST

START_TEST(up_6) {
  char *str = "123534365543&^#$^&&$#";
  char *q = s21_to_upper(str);
  ck_assert_str_eq(q, "123534365543&^#$^&&$#");
  free(q);
}
END_TEST

START_TEST(up_7) {
  char *str = "aasdffsz \n \t ";
  char *q = s21_to_upper(str);
  ck_assert_str_eq(q, "AASDFFSZ \n \t ");
  free(q);
}
END_TEST

Suite *S21ToUpperSuiteTestCreate(void) {
  Suite *suite = suite_create("s21_to_upper tests");
  TCase *tcaseCore = tcase_create("");
  tcase_add_test(tcaseCore, up_1);
  tcase_add_test(tcaseCore, up_2);
  tcase_add_test(tcaseCore, up_3);
  tcase_add_test(tcaseCore, up_4);
  tcase_add_test(tcaseCore, up_5);
  tcase_add_test(tcaseCore, up_6);
  tcase_add_test(tcaseCore, up_7);

  suite_add_tcase(suite, tcaseCore);

  return suite;
}

int main(void) {
  Suite *suite = S21ToUpperSuiteTestCreate();
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