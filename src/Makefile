CC=gcc
CFLAGS= -c -Wall -Wextra -Werror
FILES = s21_string.c s21_sprintf.c

all: clean s21_string.a

clean:
	rm -rf *.o *.a *.gcda *.gcno *.info s21_math rezult greport

s21_string.a: $(FILES) s21_string.h
	$(CC) $(CFLAGS) s21_string.c
	ar -rc s21_string.a s21_string.o


gcov_report:
	gcc --coverage $(FILES) unit.c -lcheck -o greport
	./greport
	lcov -t "s21_string" -o s21_string.info -c -d .
	genhtml -o ./report s21_string.info
	open ./report/index.html

test: check clean

check:
	gcc -Wall -Wextra -Werror $(FILES) unit.c -o check $(TEST_FLAGS)
	./check
	cp -f ../materials/linters/.clang-format ./.clang-format
	clang-format -n *.c *.h