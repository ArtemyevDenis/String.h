#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(ins_1) {
  char *str1 = "HELLO";
  char *str2 = "WORLD";
  char *q = s21_insert(str1, str2, 0);
  ck_assert_str_eq(q, "WORLDHELLO");
  free(q);
}
END_TEST

START_TEST(ins_2) {
  char *str1 = "HELLO";
  char *str2 = "WORLD";
  char *q = s21_insert(str1, str2, 1);
  ck_assert_str_eq(q, "HWORLDELLO");
  free(q);
}
END_TEST

START_TEST(ins_3) {
  char *str1 = "HELLO";
  char *str2 = " ";
  char *q = s21_insert(str1, str2, 5);
  ck_assert_str_eq(q, "HELLO ");
  free(q);
}
END_TEST

START_TEST(ins_4) {
  char *str1 = "HELLO";
  char *str2 = NULL;
  char *q = s21_insert(str1, str2, 5);
  ck_assert_ptr_null(q);
}
END_TEST

START_TEST(ins_5) {
  char *str2 = "HELLO";
  char *str1 = NULL;
  char *q = s21_insert(str1, str2, 5);
  ck_assert_ptr_null(q);
}
END_TEST

START_TEST(ins_6) {
  char *str2 = NULL;
  char *str1 = NULL;
  char *q = s21_insert(str1, str2, 5);
  ck_assert_ptr_null(q);
}
END_TEST

START_TEST(ins_7) {
  char *str1 = "A";
  char *str2 = "WORLD";
  char *q = s21_insert(str1, str2, -5);
  ck_assert_ptr_null(q);
}
END_TEST

START_TEST(ins_8) {
  char *str1 = "A";
  char *str2 = "WORLD";
  char *q = s21_insert(str1, str2, 6);
  ck_assert_ptr_null(q);
}
END_TEST

Suite *S21InsertSuiteTestCreate(void) {
  Suite *suite = suite_create("s21_insert tests");
  TCase *tcaseCore = tcase_create("");
  tcase_add_test(tcaseCore, ins_1);
  tcase_add_test(tcaseCore, ins_2);
  tcase_add_test(tcaseCore, ins_3);
  tcase_add_test(tcaseCore, ins_4);
  tcase_add_test(tcaseCore, ins_5);
  tcase_add_test(tcaseCore, ins_6);
  tcase_add_test(tcaseCore, ins_7);
  tcase_add_test(tcaseCore, ins_8);

  suite_add_tcase(suite, tcaseCore);

  return suite;
}

int main(void) {
  Suite *suite = S21InsertSuiteTestCreate();
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