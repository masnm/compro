all:
	cat Makefile
reset:
	rm in*
	touch in1 in2 in3
	echo "0 0 0" > in2
	echo "0 0 0" > in3
	cp template main.cpp
	clear
c:
	g++ -std=c++17 -Wall main.cpp
	rm a.out
r:
	g++ -std=c++17 -Wall main.cpp
	./a.out
	rm a.out
d:
	g++ -g -lm -std=c++17 -Wall -o a.out main.cpp
	gdb ./a.out
	rm a.out

t:
	g++ -Wall main.cpp -o a.out -std=c++17
	time ./a.out < in1
	time ./a.out < in2
	time ./a.out < in3
	rm a.out
stc:
	cat in*
