all:
	cat Makefile
reset:
	touch in1 in2 in3
	cp template main.cpp
c:
	g++ -std=c++17 -Wall main.cpp
	rm a.out
r:
	g++ -std=c++17 -Wall main.cpp
	./a.out
	rm a.out
d:
	g++ -g -lm -std=c++17 -Wall main.cpp
	gdb ./a.out
	rm a.out

t:
	g++ -g -std=c++17 -Wall main.cpp
	./a.out < in1
	./a.out < in2
	./a.out < in3
	rm a.out
