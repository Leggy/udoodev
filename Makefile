FLAGS = -Wall -g -pedantic -ansi -std=gnu99 -g

all: clean test

kmp: kmp.c
	gcc $(FLAGS) kmp.c -c -o $@.o

filesearch: filesearch.c kmp
	gcc $(FLAGS) filesearch.c kmp.o -c -o $@.o

test: test.c kmp filesearch
	gcc $(FLAGS) test.c kmp.o filesearch.o -o $@
	rm -rf kmp.o
	rm -rf filesearch.o

clean: sweep
	rm -rf test

sweep:
	rm -rf kmp.o
	rm -rf filesearch.o
