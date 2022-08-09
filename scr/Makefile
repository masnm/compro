cflags=-lm -std=c11 -Wshadow -ggdb3 -Wall -pedantic -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g -DLOCAL

all: main
	./main

main: main.c
	gcc $(cflags) main.c -o main

vec: vec.c
	gcc $(cflags) vec.c -o vec.out
	./vec.out
