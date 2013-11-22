FLAGS = -Wall -g -pedantic -ansi -std=gnu99

all: clean kmptest

kmp: kmp.c
	gcc $(FLAGS) kmp.c -c -o $@.o

filesearch: filesearch.c kmp
	gcc $(FLAGS) filesearch.c kmp.o -c -o $@.o

fstest: fstest.c kmp filesearch
	gcc $(FLAGS) fstest.c kmp.o filesearch.o -o $@
	rm -rf kmp.o
	rm -rf filesearch.o

zane: zanetest.c kmp
	gcc $(FLAGS) zanetest.c kmp.o -o $@
	rm -rf kmp.o
	
kmptest: kmptest.c kmp
	gcc $(FLAGS) kmptest.c kmp.o -o $@
	rm -rf kmp.o

clean: sweep
	rm -rf test

sweep:
	rm -rf kmp.o
	rm -rf filesearch.o
