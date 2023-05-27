CC=gcc
CFLAGS= -c -Wall -Wextra -Werror
FLAGS= -g -Wall -Wextra -Werror
FILES = s21_string.c s21_sprintf.c

all: clean s21_string.a

clean:
	rm -rf *.o *.a *.gcda *.gcno *.info s21_string rezult greport

s21_string.a: $(FILES)
	$(CC) $(CFLAGS) $^
	ar -rcs s21_string.a $(FILES:.c=.o)

gcov_report:
	$(CC) --coverage $(FILES) unit.c -lcheck -o greport
	./greport
	lcov -t "s21_string" -o s21_string.info -c -d .
	genhtml -o ./report s21_string.info
	open ./report/index.html

test: check clean

check:
	$(CC) $(CFLAGS) $(FILES) unit.c -o check $(TEST_FLAGS)
	./check
	cp -f ../materials/linters/.clang-format ./.clang-format
	clang-format -n *.c *.h

my: clean s21_string.a
	$(CC) $(FLAGS) test_my_func.c s21_string.a -o test_my_func
	echo             
	./test_my_func