CC=gcc
CFLAGS= -c -Wall -Wextra -Werror -std=c11  
FLAGS= -g -Wall -Wextra -Werror
FILES = s21_string.c s21_sprintf.c
TEST_FLAGS=-lcheck --coverage
OS := $(shell uname -s)
ifeq ($(OS), Linux)
	TEST_FLAGS += -lsubunit -lm
	OPEN=echo 'report: C4_s21_math-1/src/report/index.html'
else
	OPEN=open ./report/index.html
endif

all: clean s21_string.a

clean:
	rm -rf *.o *.a *.gcda *.gcno *.info s21_string rezult greport test_my_func s21_string.h.gch .clang-format index.css index.html report

s21_string.a: $(FILES)
	$(CC) $(CFLAGS) $^
	ar -rcs s21_string.a $(FILES:.c=.o)

gcov_report:
	gcc s21_sprintf.c unit.c -o greport $(TEST_FLAGS)
	./greport
	lcov -t "s21_sprintf" -o s21_sprintf.info -c -d .
	genhtml -o ./report s21_sprintf.info
	$(OPEN)

test: check clean

check:
	cp -f ../materials/linters/.clang-format ./.clang-format
	clang-format -n *.c *.h
	$(CC) $(FLAGS) $(FILES) unit.c -lm -lcheck -pthread -o check
	./check

my: clean s21_string.a
	$(CC) $(FLAGS) test_my_func.c s21_string.a -o test_my_func
	echo             
	./test_my_func