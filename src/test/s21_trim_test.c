#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(trim_1) {
  char *str1 = " hello world ";
  char *str2 = "";
  char *q = s21_trim(str1, str2);
  ck_assert_str_eq(q, "hello world");
  free(q);
}
END_TEST

START_TEST(trim_2) {
  char *str1 = "      hello world            ";
  char *str2 = "";
  char *q = s21_trim(str1, str2);
  ck_assert_str_eq(q, "hello world");
  free(q);
}
END_TEST

START_TEST(trim_3) {
  char *str1 = "                 ";
  char *str2 = "";
  char *q = s21_trim(str1, str2);
  ck_assert_str_eq(q, "");
  free(q);
}
END_TEST

START_TEST(trim_4) {
  char *str1 = ",hello world//.,";
  char *str2 = ",/";
  char *q = s21_trim(str1, str2);
  ck_assert_str_eq(q, "hello world//.");
  free(q);
}
END_TEST

START_TEST(trim_5) {
  char *str1 = ".,hello world.,.//";
  char *str2 = "";
  char *q = s21_trim(str1, str2);
  ck_assert_str_eq(q, ".,hello world.,.//");
  free(q);
}
END_TEST

START_TEST(trim_6) {
  char *str1 = ".,hello world.,.//";
  char *str2 = ".,/";
  char *q = s21_trim(str1, str2);
  ck_assert_str_eq(q, "hello world");
  free(q);
}
END_TEST

START_TEST(trim_7) {
  char *str1 = NULL;
  char *str2 = ".,/";
  char *q = s21_trim(str1, str2);
  ck_assert_ptr_null(q);
}
END_TEST

START_TEST(trim_8) {
  char *str1 = "A";
  char *str2 = NULL;
  char *q = s21_trim(str1, str2);
  ck_assert_ptr_null(q);
}
END_TEST

START_TEST(trim_9) {
  char *str1 = NULL;
  char *str2 = NULL;
  char *q = s21_trim(str1, str2);
  ck_assert_ptr_null(q);
}
END_TEST

START_TEST(trim_10) {
  char *str1 = "\thello world\t";
  char *str2 = "";
  char *q = s21_trim(str1, str2);
  ck_assert_str_eq(q, "hello world");
  free(q);
}
END_TEST

Suite *S21TrimSuiteTestCreate(void) {
  Suite *suite = suite_create("s21_trim tests");
  TCase *tcaseCore = tcase_create("");
  tcase_add_test(tcaseCore, trim_1);
  tcase_add_test(tcaseCore, trim_2);
  tcase_add_test(tcaseCore, trim_3);
  tcase_add_test(tcaseCore, trim_4);
  tcase_add_test(tcaseCore, trim_5);
  tcase_add_test(tcaseCore, trim_6);
  tcase_add_test(tcaseCore, trim_7);
  tcase_add_test(tcaseCore, trim_8);
  tcase_add_test(tcaseCore, trim_9);
  tcase_add_test(tcaseCore, trim_10);
  suite_add_tcase(suite, tcaseCore);

  return suite;
}

int main(void) {
  Suite *suite = S21TrimSuiteTestCreate();
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