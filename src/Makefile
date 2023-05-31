CC=gcc
CFLAGS= -c -Wall -Wextra -Werror -std=c11  
FLAGS= -g -Wall -Wextra -Werror
FILES = s21_string.c s21_sprintf.c

all: clean s21_string.a

clean:
	rm -rf *.o *.a *.gcda *.gcno *.info s21_string rezult greport test_my_func s21_string.h.gch .clang-format

s21_string.a: $(FILES)
	$(CC) $(CFLAGS) $^
	ar -rcs s21_string.a $(FILES:.c=.o)

gcov_report:
	$(CC) --coverage $(FILES) unit.c -lcheck -pthread -o greport
	./greport
	lcov -t "s21_string" -o s21_string.info -c -d .
	genhtml -o ./report s21_string.info
	open ./report/index.html

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