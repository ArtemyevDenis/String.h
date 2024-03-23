
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(memchr_1) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_memchr(test1, 'A', 11), memchr(test1, 'A', 11));
}
END_TEST

START_TEST(memchr_2) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_memchr(test1, 'a', 8), memchr(test1, 'a', 8));
}
END_TEST

START_TEST(memchr_3) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_memchr(test1, 'l', 11), memchr(test1, 'l', 11));
}
END_TEST

START_TEST(memchr_4) {
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_ptr_eq(s21_memchr(test2, 'W', 11), memchr(test2, 'W', 11));
}
END_TEST

START_TEST(memchr_5) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_memchr(test1, 'A', 1), memchr(test1, 'A', 1));
}
END_TEST

START_TEST(memchr_6) {
  char *test3 = "123455";
  ck_assert_ptr_eq(s21_memchr(test3, '5', 6), memchr(test3, '5', 6));
}
END_TEST

START_TEST(memchr_7) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_memchr(test1, '2', 6), memchr(test1, '2', 6));
}
END_TEST

START_TEST(memchr_8) {
  char *test3 = "123455";
  ck_assert_ptr_eq(s21_memchr(test3, '1', 1), memchr(test3, '1', 1));
}
END_TEST

START_TEST(memchr_9) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_memchr(test1, '4', 6), memchr(test1, '4', 6));
}
END_TEST

START_TEST(memchr_10) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_memchr(test1, '6', 6), memchr(test1, '6', 6));
}
END_TEST

START_TEST(memcmp_1) {
  char *test1 = "Alla Halla Cat Dog";
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_uint_eq(s21_memcmp(test1, test2, 11) > 0,
                    memcmp(test1, test2, 11) > 0);
}
END_TEST

START_TEST(memcmp_2) {
  char *test1 = "Alla Halla Cat Dog";
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_uint_eq(s21_memcmp(test1, test2, 11) > 0,
                    memcmp(test1, test2, 11) > 0);
}
END_TEST

START_TEST(memcmp_3) {
  char *test1 = "Alla Halla Cat Dog";
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_uint_eq(s21_memcmp(test1, test2, 5) == 0,
                    memcmp(test1, test2, 5) == 0);
}
END_TEST

START_TEST(memcmp_4) {
  char *test2 = "Alla Halla Alla Walla";
  char *test3 = "123455";
  ck_assert_uint_eq(s21_memcmp(test3, test2, 2) < 0,
                    memcmp(test3, test2, 2) < 0);
}
END_TEST

START_TEST(memcmp_5) {
  int test4[] = {1, 2, 3, 4, 5};
  int test5[] = {1, 2, 3, 4, 6};
  ck_assert_uint_eq(s21_memcmp(test4, test5, 4) == 0,
                    memcmp(test4, test5, 4) == 0);
}
END_TEST

START_TEST(memcmp_6) {
  int test4[] = {1, 2, 3, 4, 5};
  int test5[] = {1, 2, 3, 4, 6};
  ck_assert_uint_eq(s21_memcmp(test4, test5, 3) < 0,
                    memcmp(test4, test5, 3) < 0);
}
END_TEST

START_TEST(memcmp_7) {
  char test7[] = "goga\0 job";
  char test8[] = "goga\0 job";
  ck_assert_uint_eq(s21_memcmp(test7, test8, 2) == 0,
                    memcmp(test7, test8, 2) == 0);
}
END_TEST

START_TEST(memcmp_9) {
  char *test1 = "Alla Halla Cat Dog";
  char test8[] = "goga\0 job";
  ck_assert_uint_eq(s21_memcmp(test1, test8, 3) < 0,
                    memcmp(test1, test8, 3) < 0);
}
END_TEST

START_TEST(memcpy_1) {
  char *test2 = "Alla Halla Alla Walla";
  char *test0[10];
  ck_assert_str_eq(s21_memcpy(test0, test2, 1), memcpy(test0, test2, 1));
}
END_TEST

START_TEST(memcpy_2) {
  char *test2 = "Alla Halla Alla Walla";
  char *test0[10];
  ck_assert_str_eq(s21_memcpy(test0, test2, 10), memcpy(test0, test2, 10));
}
END_TEST

START_TEST(memcpy_3) {
  char *test2 = "Alla Halla Alla Walla";
  char *test0[10];
  ck_assert_str_eq(s21_memcpy(test0, test2, 11), memcpy(test0, test2, 11));
}
END_TEST

START_TEST(memcpy_4) {
  char *test1 = "Alla Halla Cat Dog";
  char *test0[10];
  ck_assert_str_eq(s21_memcpy(test0, test1, 6), memcpy(test0, test1, 6));
}
END_TEST

START_TEST(memcpy_5) {
  char *test3 = "123455";
  char *test0[10];
  ck_assert_str_eq(s21_memcpy(test0, test3, 2), memcpy(test0, test3, 2));
}
END_TEST

START_TEST(memcpy_6) {
  char *test3 = "123455";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_memcpy(test01, test3, 4), memcpy(test01, test3, 4));
}
END_TEST

START_TEST(memcpy_7) {
  char *test1 = "Alla Halla Cat Dog";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_memcpy(test01, test1, 11), memcpy(test01, test1, 11));
}
END_TEST

START_TEST(memcpy_8) {
  char *test1 = "Alla Halla Cat Dog";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_memcpy(test01, test1, 10), memcpy(test01, test1, 10));
}
END_TEST

START_TEST(memset_1) {
  char *test0[10];
  ck_assert_str_eq(s21_memset(test0, 'a', 1), memset(test0, 'a', 1));
}
END_TEST

START_TEST(memset_2) {
  char *test0[10];
  ck_assert_str_eq(s21_memset(test0, 'a', 8), memset(test0, 'a', 8));
}
END_TEST

START_TEST(memset_3) {
  char *test0[10];
  ck_assert_str_eq(s21_memset(test0, 'a', 7), memset(test0, 'a', 7));
}
END_TEST

START_TEST(memset_4) {
  char *test0[10];
  ck_assert_str_eq(s21_memset(test0, 'a', 5), memset(test0, 'a', 5));
}
END_TEST

START_TEST(memset_7) {
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_memset(test01, 1, 7), memset(test01, 1, 7));
}
END_TEST

START_TEST(memset_8) {
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_memset(test01, 'a', 11), memset(test01, 'a', 11));
}
END_TEST

START_TEST(strncat_1) {
  char *test2 = "Alla Halla Alla Walla";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_strncat(test01, test2, 1), strncat(test01, test2, 1));
}
END_TEST

START_TEST(strncat_2) {
  char *test2 = "Alla Halla Alla Walla";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_strncat(test01, test2, 10), strncat(test01, test2, 10));
}
END_TEST

START_TEST(strncat_3) {
  char *test3 = "123455";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_strncat(test01, test3, 1), strncat(test01, test3, 1));
}
END_TEST

START_TEST(strncat_4) {
  char *test3 = "123455";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_strncat(test01, test3, 0), strncat(test01, test3, 0));
}
END_TEST

START_TEST(strncat_5) {
  char *test3 = "123455";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_strncat(test01, test3, 10), strncat(test01, test3, 10));
}
END_TEST

START_TEST(strchr_1) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_str_eq(s21_strchr(test1, 'A'), strchr(test1, 'A'));
}
END_TEST

START_TEST(strchr_2) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_strchr(test1, 'a'), strchr(test1, 'a'));
}
END_TEST

START_TEST(strchr_3) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_strchr(test1, 'l'), strchr(test1, 'l'));
}
END_TEST

START_TEST(strchr_4) {
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_ptr_eq(s21_strchr(test2, 'W'), strchr(test2, 'W'));
}
END_TEST

START_TEST(strchr_5) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_str_eq(s21_strchr(test1, 'A'), strchr(test1, 'A'));
}
END_TEST

START_TEST(strchr_6) {
  char *test3 = "123455";
  ck_assert_ptr_eq(s21_strchr(test3, '5'), strchr(test3, '5'));
}
END_TEST

START_TEST(strchr_7) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_strchr(test1, '2'), strchr(test1, '2'));
}
END_TEST

START_TEST(strchr_8) {
  char *test3 = "123455";
  ck_assert_str_eq(s21_strchr(test3, '1'), strchr(test3, '1'));
}
END_TEST

START_TEST(strchr_9) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_strchr(test1, '4'), strchr(test1, '4'));
}
END_TEST

START_TEST(strchr_10) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_strchr(test1, '6'), strchr(test1, '6'));
}
END_TEST

START_TEST(strncmp_1) {
  char *test1 = "Alla Halla Cat Dog";
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_uint_eq(s21_strncmp(test1, test2, 2), strncmp(test1, test2, 2));
}
END_TEST

START_TEST(strncmp_2) {
  char *test1 = "Alla Halla Cat Dog";
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_uint_eq(s21_strncmp(test1, test2, 11), strncmp(test1, test2, 11));
}
END_TEST

START_TEST(strncmp_3) {
  char *test1 = "Alla Halla Cat Dog";
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_uint_eq(s21_strncmp(test1, test2, 14), strncmp(test1, test2, 14));
}
END_TEST

START_TEST(strncmp_4) {
  char *test1 = "Alla Halla Cat Dog";
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_uint_eq(s21_strncmp(test1, test2, 18), strncmp(test1, test2, 18));
}
END_TEST

START_TEST(strncmp_5) {
  char test7[] = "goga\0 job";
  char test8[] = "goga\0 job";
  ck_assert_uint_eq(s21_strncmp(test7, test8, 9), strncmp(test7, test8, 9));
}
END_TEST

START_TEST(strncmp_6) {
  char test6[] = "\0";
  char test7[] = "goga\0 job";
  ck_assert_uint_eq(s21_strncmp(test6, test7, 1), strncmp(test6, test7, 1));
}
END_TEST

START_TEST(strncmp_7) {
  char *test1 = "Alla Halla Cat Dog";
  char test8[] = "goga\0 job";
  ck_assert_uint_eq(s21_strncmp(test1, test8, 5), strncmp(test1, test8, 5));
}
END_TEST

START_TEST(strncpy_1) {
  char *test3 = "123455";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_strncpy(test01, test3, 10), strncpy(test01, test3, 10));
}
END_TEST

START_TEST(strncpy_2) {
  char *test1 = "Alla Halla Cat Dog";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_strncpy(test01, test1, 11), strncpy(test01, test1, 11));
}
END_TEST

START_TEST(strncpy_3) {
  char *test1 = "Alla Halla Cat Dog";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_strncpy(test01, test1, 100),
                   strncpy(test01, test1, 100));
}
END_TEST

START_TEST(strncpy_4) {
  char *test3 = "123455";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_strncpy(test01, test3, 4), strncpy(test01, test3, 4));
}
END_TEST

START_TEST(strncpy_5) {
  char *test1 = "Alla Halla Cat Dog";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_strncpy(test01, test1, 2), strncpy(test01, test1, 2));
}
END_TEST

START_TEST(strncpy_6) {
  char *test1 = "Alla Halla Cat Dog";
  char test01[1000] = "Alla Halla Cat Dog";
  ck_assert_str_eq(s21_strncpy(test01, test1, 1), strncpy(test01, test1, 1));
}
END_TEST

START_TEST(strcspn_1) {
  char *test1 = "Alla Halla Cat Dog";
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_uint_eq(s21_strcspn(test1, test2), strcspn(test1, test2));
}
END_TEST

START_TEST(strcspn_2) {
  char *test1 = "Alla Halla Cat Dog";
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_uint_eq(s21_strcspn(test2, test1), strcspn(test2, test1));
}
END_TEST

START_TEST(strcspn_3) {
  char *test1 = "Alla Halla Cat Dog";
  char *test3 = "123455";
  ck_assert_uint_eq(s21_strcspn(test1, test3), strcspn(test1, test3));
}
END_TEST

START_TEST(strcspn_4) {
  char *test2 = "Alla Halla Alla Walla";
  char *test3 = "123455";
  ck_assert_uint_eq(s21_strcspn(test3, test2), strcspn(test3, test2));
}
END_TEST

START_TEST(strcspn_5) {
  char *test2 = "Alla Halla Alla Walla";
  char *test3 = "123455";
  ck_assert_uint_eq(s21_strcspn(test2, test3), strcspn(test2, test3));
}
END_TEST

START_TEST(strcspn_6) {
  char test6[] = "\0";
  char test7[] = "goga\0 job";
  ck_assert_uint_eq(s21_strcspn(test6, test7), strcspn(test6, test7));
}
END_TEST

START_TEST(strcspn_7) {
  char *test1 = "Alla Halla Cat Dog";
  char test8[] = "goga\0 job";
  ck_assert_uint_eq(s21_strcspn(test1, test8), strcspn(test1, test8));
}
END_TEST

START_TEST(strerror_1) { ck_assert_str_eq(s21_strerror(0), strerror(0)); }
END_TEST

START_TEST(strerror_2) { ck_assert_str_eq(s21_strerror(2000), strerror(2000)); }
END_TEST

START_TEST(strerror_3) { ck_assert_str_eq(s21_strerror(10), strerror(10)); }
END_TEST

START_TEST(strerror_4) { ck_assert_str_eq(s21_strerror(-20), strerror(-20)); }
END_TEST

START_TEST(strerror_5) { ck_assert_str_eq(s21_strerror(5), strerror(5)); }
END_TEST

START_TEST(strerror_6) { ck_assert_str_eq(s21_strerror(105), strerror(105)); }
END_TEST

START_TEST(strerror_7) {
  ck_assert_str_eq(s21_strerror(-2005), strerror(-2005));
}
END_TEST

START_TEST(strerror_8) { ck_assert_str_eq(s21_strerror(56), strerror(56)); }
END_TEST

START_TEST(strerror_9) { ck_assert_str_eq(s21_strerror(44), strerror(44)); }
END_TEST

START_TEST(strerror_10) { ck_assert_str_eq(s21_strerror(76), strerror(76)); }
END_TEST

START_TEST(strlen_1) {
  char *test1 = "Alla Halla Cat Dog";
  ck_assert_uint_eq(s21_strlen(test1), strlen(test1));
}
END_TEST

START_TEST(strlen_2) {
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_uint_eq(s21_strlen(test2), strlen(test2));
}
END_TEST

START_TEST(strlen_3) {
  char *test3 = "123455";
  ck_assert_uint_eq(s21_strlen(test3), strlen(test3));
}
END_TEST

START_TEST(strlen_4) {
  char test6[] = "\0";
  ck_assert_uint_eq(s21_strlen(test6), strlen(test6));
}
END_TEST

START_TEST(strlen_5) {
  char test7[] = "goga\0 job";
  ck_assert_uint_eq(s21_strlen(test7), strlen(test7));
}
END_TEST

START_TEST(strlen_6) {
  char test8[] = "goga\0 job";
  ck_assert_uint_eq(s21_strlen(test8), strlen(test8));
}
END_TEST

START_TEST(strpbrk_1) {
  char *test1 = "Alla Halla Cat Dog";
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_ptr_eq(s21_strpbrk(test1, test2), strpbrk(test1, test2));
}
END_TEST

START_TEST(strpbrk_2) {
  char *test1 = "Alla Halla Cat Dog";
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_ptr_eq(s21_strpbrk(test2, test1), strpbrk(test2, test1));
}
END_TEST

START_TEST(strpbrk_3) {
  char *test1 = "Alla Halla Cat Dog";
  char *test3 = "123455";
  ck_assert_ptr_eq(s21_strpbrk(test1, test3), strpbrk(test1, test3));
}
END_TEST

START_TEST(strpbrk_4) {
  char *test2 = "Alla Halla Alla Walla";
  char *test3 = "123455";
  ck_assert_ptr_eq(s21_strpbrk(test3, test2), strpbrk(test3, test2));
}
END_TEST

START_TEST(strpbrk_5) {
  char *test2 = "Alla Halla Alla Walla";
  char *test3 = "123455";
  ck_assert_ptr_eq(s21_strpbrk(test2, test3), strpbrk(test2, test3));
}
END_TEST

START_TEST(strpbrk_6) {
  char test6[] = "\0";
  char test7[] = "goga\0 job";
  ck_assert_ptr_eq(s21_strpbrk(test6, test7), strpbrk(test6, test7));
}
END_TEST

START_TEST(strpbrk_7) {
  char *test1 = "Alla Halla Cat Dog";
  char test8[] = "goga\0 job";
  ck_assert_ptr_eq(s21_strpbrk(test1, test8), strpbrk(test1, test8));
}
END_TEST

START_TEST(strrchr_1) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_strrchr(test1, 'a'), strrchr(test1, 'a'));
}
END_TEST

START_TEST(strrchr_2) {
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_ptr_eq(s21_strrchr(test2, 'l'), strrchr(test2, 'l'));
}
END_TEST

START_TEST(strrchr_3) {
  char *test3 = "123455";
  ck_assert_ptr_eq(s21_strrchr(test3, '1'), strrchr(test3, '1'));
}
END_TEST

START_TEST(strrchr_4) {
  char test6[] = "\0";
  ck_assert_ptr_eq(s21_strrchr(test6, '1'), strrchr(test6, '1'));
}
END_TEST

START_TEST(strrchr_5) {
  char test7[] = "goga\0 job";
  ck_assert_ptr_eq(s21_strrchr(test7, 'g'), strrchr(test7, 'g'));
}
END_TEST

START_TEST(strrchr_6) {
  char test8[] = "goga\0 job";
  ck_assert_ptr_eq(s21_strrchr(test8, 'o'), strrchr(test8, 'o'));
}
END_TEST

START_TEST(strrchr_7) {
  char *test3 = "123455";
  ck_assert_ptr_eq(s21_strrchr(test3, 5), strrchr(test3, 5));
}
END_TEST

START_TEST(strrchr_8) {
  char *test1 = "Alla Halla Cat Dog";
  ck_assert_ptr_eq(s21_strrchr(test1, 'Q'), strrchr(test1, 'Q'));
}
END_TEST

START_TEST(strstr_1) {
  char *test1 = "Alla Halla Cat Dog";

  ck_assert_ptr_eq(s21_strstr(test1, "all"), strstr(test1, "all"));
}
END_TEST

START_TEST(strstr_2) {
  char *test2 = "Alla Halla Alla Walla";
  ck_assert_ptr_eq(s21_strstr(test2, "lla"), strstr(test2, "lla"));
}
END_TEST

START_TEST(strstr_3) {
  char *test3 = "123455";
  ck_assert_ptr_eq(s21_strstr(test3, "123"), strstr(test3, "123"));
}
END_TEST

START_TEST(strstr_4) {
  char test6[] = "\0";
  ck_assert_ptr_eq(s21_strstr(test6, "lla"), strstr(test6, "lla"));
}
END_TEST

START_TEST(strstr_5) {
  char test7[] = "goga\0 job";
  ck_assert_ptr_eq(s21_strstr(test7, "gog"), strstr(test7, "gog"));
}
END_TEST

START_TEST(strstr_6) {
  char test7[] = "goga\0 job";
  char test8[] = "goga\0 job";
  ck_assert_ptr_eq(s21_strstr(test8, test7), strstr(test8, test7));
}
END_TEST

// START_TEST(strtok_1) {
//   char *str_ = s21_strtok("UwU", "UwU");
//   char *str = strtok("UwU", "UwU");
//   ck_assert_ptr_null(str);
//   ck_assert_ptr_null(str_);
// }
// END_TEST

START_TEST(strtok_2) {
  char *str_ = s21_strtok("1", "\0");
  char *str = strtok("1", "\0");
  ck_assert_str_eq(str_, str);
}
END_TEST

// START_TEST(strtok_3) {
//   char *str_ = s21_strtok("", "");
//   char *str = strtok("", "");
//   ck_assert_ptr_null(str);
//   ck_assert_ptr_null(str_);
// }
// END_TEST

START_TEST(strtok_4) {
  char *str_ = s21_strtok(s21_NULL, "/");
  ck_assert_ptr_null(str_);
}
END_TEST

START_TEST(strtok_5) {
  char *str_ = s21_strtok("aaabbb", ";,");
  char *str = strtok("aaabbb", ";,");
  ck_assert_str_eq(str_, str);
}
END_TEST

START_TEST(strtok_6) {
  char str_[] = "- OMAE WA MOU SHINDEIRU. - NANI?!? ";
  char *str_1 = "?!?";
  char *res = s21_strtok(str_, str_1);
  char *res_ = strtok(str_, str_1);
  ck_assert_str_eq(res, res_);
}
END_TEST

START_TEST(strtok_8) {
  char str_[] = "Initialize";
  char *res = strtok(str_, "i");
  char *res_ = s21_strtok(str_, "i");
  ck_assert_str_eq(res, res_);
}
END_TEST

START_TEST(strtok_9) {
  char str_[] = "весело \0 -----нет";
  char *res = strtok(str_, "нет");
  char *res_ = s21_strtok(str_, "нет");
  ck_assert_str_eq(res, res_);
}
END_TEST

START_TEST(strtok_10) {
  char str_[] = "Мы_молодцы (яМолодец)";
  char *res = strtok(str_, " ");
  char *res_ = s21_strtok(str_, " ");
  ck_assert_ptr_eq(res, res_);
}
END_TEST

int main(void) {
  Suite *s1_1 = suite_create("Core");
  TCase *tc1_1_1 = tcase_create("Core");
  SRunner *sr_1 = srunner_create(s1_1);

  suite_add_tcase(s1_1, tc1_1_1);

  Suite *ne_kak_u_vseh = suite_create("Core");
  TCase *otli4noe_ot_vashego = tcase_create("Core");
  SRunner *krasivoe = srunner_create(ne_kak_u_vseh);

  suite_add_tcase(ne_kak_u_vseh, otli4noe_ot_vashego);
  // tcase_add_test(otli4noe_ot_vashego, strtok_1);
  tcase_add_test(otli4noe_ot_vashego, strtok_2);
  // tcase_add_test(otli4noe_ot_vashego, strtok_3);
  tcase_add_test(otli4noe_ot_vashego, strtok_4);
  tcase_add_test(otli4noe_ot_vashego, strtok_5);
  tcase_add_test(otli4noe_ot_vashego, strtok_6);
  tcase_add_test(otli4noe_ot_vashego, strtok_8);
  tcase_add_test(otli4noe_ot_vashego, strtok_9);
  tcase_add_test(otli4noe_ot_vashego, strtok_10);

  tcase_add_test(tc1_1_1, memchr_1);
  tcase_add_test(tc1_1_1, memchr_2);
  tcase_add_test(tc1_1_1, memchr_3);
  tcase_add_test(tc1_1_1, memchr_4);
  tcase_add_test(tc1_1_1, memchr_5);
  tcase_add_test(tc1_1_1, memchr_6);
  tcase_add_test(tc1_1_1, memchr_7);
  tcase_add_test(tc1_1_1, memchr_8);
  tcase_add_test(tc1_1_1, memchr_9);
  tcase_add_test(tc1_1_1, memchr_10);
  tcase_add_test(tc1_1_1, memcmp_1);
  tcase_add_test(tc1_1_1, memcmp_2);
  tcase_add_test(tc1_1_1, memcmp_3);
  tcase_add_test(tc1_1_1, memcmp_4);
  tcase_add_test(tc1_1_1, memcmp_5);
  tcase_add_test(tc1_1_1, memcmp_6);
  tcase_add_test(tc1_1_1, memcmp_7);
  tcase_add_test(tc1_1_1, memcmp_9);
  // tcase_add_test(tc1_1_1, memcmp_10);
  tcase_add_test(tc1_1_1, memcpy_1);
  tcase_add_test(tc1_1_1, memcpy_2);
  tcase_add_test(tc1_1_1, memcpy_3);
  tcase_add_test(tc1_1_1, memcpy_4);
  tcase_add_test(tc1_1_1, memcpy_5);
  tcase_add_test(tc1_1_1, memcpy_6);
  tcase_add_test(tc1_1_1, memcpy_7);
  tcase_add_test(tc1_1_1, memcpy_8);
  tcase_add_test(tc1_1_1, memset_1);
  tcase_add_test(tc1_1_1, memset_2);
  tcase_add_test(tc1_1_1, memset_3);
  tcase_add_test(tc1_1_1, memset_4);
  tcase_add_test(tc1_1_1, memset_7);
  tcase_add_test(tc1_1_1, memset_8);
  tcase_add_test(tc1_1_1, strncat_1);
  tcase_add_test(tc1_1_1, strncat_2);
  tcase_add_test(tc1_1_1, strncat_3);
  tcase_add_test(tc1_1_1, strncat_4);
  tcase_add_test(tc1_1_1, strncat_5);
  tcase_add_test(tc1_1_1, strchr_1);
  tcase_add_test(tc1_1_1, strchr_2);
  tcase_add_test(tc1_1_1, strchr_3);
  tcase_add_test(tc1_1_1, strchr_4);
  tcase_add_test(tc1_1_1, strchr_5);
  tcase_add_test(tc1_1_1, strchr_6);
  tcase_add_test(tc1_1_1, strchr_7);
  tcase_add_test(tc1_1_1, strchr_8);
  tcase_add_test(tc1_1_1, strchr_9);
  tcase_add_test(tc1_1_1, strchr_10);
  tcase_add_test(tc1_1_1, strncmp_1);
  tcase_add_test(tc1_1_1, strncmp_2);
  tcase_add_test(tc1_1_1, strncmp_3);
  tcase_add_test(tc1_1_1, strncmp_4);
  tcase_add_test(tc1_1_1, strncmp_5);
  tcase_add_test(tc1_1_1, strncmp_6);
  tcase_add_test(tc1_1_1, strncmp_7);
  tcase_add_test(tc1_1_1, strncpy_1);
  tcase_add_test(tc1_1_1, strncpy_2);
  tcase_add_test(tc1_1_1, strncpy_3);
  tcase_add_test(tc1_1_1, strncpy_4);
  tcase_add_test(tc1_1_1, strncpy_5);
  tcase_add_test(tc1_1_1, strncpy_6);
  tcase_add_test(tc1_1_1, strcspn_1);
  tcase_add_test(tc1_1_1, strcspn_2);
  tcase_add_test(tc1_1_1, strcspn_3);
  tcase_add_test(tc1_1_1, strcspn_4);
  tcase_add_test(tc1_1_1, strcspn_5);
  tcase_add_test(tc1_1_1, strcspn_6);
  tcase_add_test(tc1_1_1, strcspn_7);
  tcase_add_test(tc1_1_1, strerror_1);
  tcase_add_test(tc1_1_1, strerror_2);
  tcase_add_test(tc1_1_1, strerror_3);
  tcase_add_test(tc1_1_1, strerror_4);
  tcase_add_test(tc1_1_1, strerror_5);
  tcase_add_test(tc1_1_1, strerror_6);
  tcase_add_test(tc1_1_1, strerror_7);
  tcase_add_test(tc1_1_1, strerror_8);
  tcase_add_test(tc1_1_1, strerror_9);
  tcase_add_test(tc1_1_1, strerror_10);
  tcase_add_test(tc1_1_1, strlen_1);
  tcase_add_test(tc1_1_1, strlen_2);
  tcase_add_test(tc1_1_1, strlen_3);
  tcase_add_test(tc1_1_1, strlen_4);
  tcase_add_test(tc1_1_1, strlen_5);
  tcase_add_test(tc1_1_1, strlen_6);
  tcase_add_test(tc1_1_1, strpbrk_1);
  tcase_add_test(tc1_1_1, strpbrk_2);
  tcase_add_test(tc1_1_1, strpbrk_3);
  tcase_add_test(tc1_1_1, strpbrk_4);
  tcase_add_test(tc1_1_1, strpbrk_5);
  tcase_add_test(tc1_1_1, strpbrk_6);
  tcase_add_test(tc1_1_1, strpbrk_7);
  tcase_add_test(tc1_1_1, strrchr_1);
  tcase_add_test(tc1_1_1, strrchr_2);
  tcase_add_test(tc1_1_1, strrchr_3);
  tcase_add_test(tc1_1_1, strrchr_4);
  tcase_add_test(tc1_1_1, strrchr_5);
  tcase_add_test(tc1_1_1, strrchr_6);
  tcase_add_test(tc1_1_1, strrchr_7);
  tcase_add_test(tc1_1_1, strrchr_8);
  tcase_add_test(tc1_1_1, strstr_1);
  tcase_add_test(tc1_1_1, strstr_2);
  tcase_add_test(tc1_1_1, strstr_3);
  tcase_add_test(tc1_1_1, strstr_4);
  tcase_add_test(tc1_1_1, strstr_5);
  tcase_add_test(tc1_1_1, strstr_6);

  srunner_run_all(sr_1, CK_ENV);
  srunner_ntests_failed(sr_1);
  srunner_free(sr_1);
  srunner_run_all(krasivoe, CK_ENV);
  srunner_ntests_failed(krasivoe);
  srunner_free(krasivoe);

  return 0;
}