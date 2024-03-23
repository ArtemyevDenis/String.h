CC=gcc -Wall -Wextra -Werror -std=c11
FUNC_FILES_C=s21_insert.c s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memset.c s21_sprintf.c s21_strchr.c s21_strcspn.c s21_strerror.c s21_strlen.c s21_strncat.c s21_strncmp.c s21_strncpy.c s21_strpbrk.c s21_strrchr.c s21_strstr.c s21_strtok.c s21_to_lower.c s21_to_upper.c s21_trim.c
FUNC_FILES_O=s21_insert.o s21_memchr.o s21_memcmp.o s21_memcpy.o s21_memset.o s21_sprintf.o s21_strchr.o s21_strcspn.o s21_strerror.o s21_strlen.o s21_strncat.o s21_strncmp.o s21_strncpy.o s21_strpbrk.o s21_strrchr.o s21_strstr.o s21_strtok.o s21_to_lower.o s21_to_upper.o s21_trim.o
GCOVFLAGS=-fprofile-arcs -ftest-coverage
LIBNAME=s21_string.a
GLFLAGS=--coverage
OPEN_CMD = xdg-open
FLAGS = -lcheck -lpthread -lsubunit -lrt -lm


all: s21_string.a


build_object_files:
	$(CC) $(FLAGS) $(GCOVFLAGS) $(GLFLAGS) -c $(FUNC_FILES_C)

build_library:
	ar rcs $(LIBNAME) $(FUNC_FILES_O)

s21_string.a:
	$(CC) -lm -c $(FUNC_FILES_C)
	make build_library
	rm -rf *.o

test: s21_string.a
	$(CC)  $(GLFLAGS) $(GCOVFLAGS) test/micro_func_test.c -L. s21_string.a  -o micro_func_test $(FLAGS)
	$(CC)  $(GLFLAGS) $(GCOVFLAGS) test/s21_insert_test.c -L. s21_string.a  -o s21_insert_test $(FLAGS)
	$(CC)  $(GLFLAGS) $(GCOVFLAGS) test/s21_to_lower_test.c -L. s21_string.a  -o s21_to_lower_test $(FLAGS)
	$(CC)  $(GLFLAGS) $(GCOVFLAGS) test/s21_to_upper_test.c -L. s21_string.a  -o s21_to_upper_test $(FLAGS)
	$(CC)  $(GLFLAGS) $(GCOVFLAGS) test/s21_trim_test.c -L. s21_string.a  -o s21_trim_test $(FLAGS)
	$(CC)  $(GLFLAGS) $(GCOVFLAGS) test/sprintf_random_test.c -L. s21_string.a  -o sprintf_random_test $(FLAGS)
	$(CC)  $(GLFLAGS) $(GCOVFLAGS) test/sprintf_test_perecnt.c -L. s21_string.a  -o sprintf_test_perecnt_test $(FLAGS)
	$(CC)  $(GLFLAGS) $(GCOVFLAGS) test/sprintf_test_spec_c_test.c -L. s21_string.a  -o sprintf_test_spec_c_test $(FLAGS)
	$(CC)  $(GLFLAGS) $(GCOVFLAGS) test/sprintf_test_spec_d_test.c -L. s21_string.a  -o sprintf_test_spec_d_test $(FLAGS)
	$(CC)  $(GLFLAGS) $(GCOVFLAGS) test/sprintf_test_spec_f_test.c -L. s21_string.a  -o sprintf_test_spec_f_test $(FLAGS)
	$(CC)  $(GLFLAGS) $(GCOVFLAGS) test/sprintf_test_spec_o_test.c -L. s21_string.a  -o sprintf_test_spec_o_test $(FLAGS)
	$(CC)  $(GLFLAGS) $(GCOVFLAGS) test/sprintf_test_spec_p_test.c -L. s21_string.a  -o sprintf_test_spec_p_test $(FLAGS)
	$(CC)  $(GLFLAGS) $(GCOVFLAGS) test/sprintf_test_spec_s_test.c -L. s21_string.a  -o sprintf_test_spec_s_test $(FLAGS)
	$(CC)  $(GLFLAGS) $(GCOVFLAGS) test/sprintf_test_spec_u_test.c -L. s21_string.a  -o sprintf_test_spec_u_test $(FLAGS)
	$(CC)  $(GLFLAGS) $(GCOVFLAGS) test/sprintf_test_spec_xX_test.c -L. s21_string.a  -o sprintf_test_spec_xX_test $(FLAGS)
	$(CC)  $(GLFLAGS) $(GCOVFLAGS) test/sprintf_spec_g_test.c -L. s21_string.a  -o sprintf_spec_g_test $(FLAGS)
	$(CC)  $(GLFLAGS) $(GCOVFLAGS) test/sprintf_test_e_test.c -L. s21_string.a  -o sprintf_test_e_test $(FLAGS)

	./micro_func_test
	./s21_insert_test
	./s21_to_lower_test
	./s21_to_upper_test
	./s21_trim_test
	./sprintf_random_test
	./sprintf_test_perecnt_test
	./sprintf_test_spec_c_test
	./sprintf_test_spec_d_test
	./sprintf_test_spec_f_test
	./sprintf_test_spec_o_test
	./sprintf_test_spec_s_test
	./sprintf_test_spec_u_test
	./sprintf_test_spec_xX_test
	./sprintf_spec_g_test
	./sprintf_test_e_test
	./sprintf_test_spec_p_test

gcov_report: clean build_object_files build_library test
	lcov -o tests.info -c -d .  
	genhtml -o report tests.info
	$(OPEN_CMD) report/index.html
	make clean

 
clean:
	rm -rf *.o
	rm -rf *.gcno
	rm -rf *.gcov
	rm -rf *.gcda
	rm -rf *.a
	rm -rf *.info
	rm -rf *_test

rebuild:
	make clean
	make