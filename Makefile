all:
	cat Makefile
reset:
	rm in1 in2 in3
	touch in1 in2 in3
	cp template main.cpp
c:
	g++ -std=c++17 -Wall main.cpp
	rm a.out
t1:
	g++ -std=c++17 -Wall main.cpp
	a.out < in1
	rm a.out
t2:
	g++ -std=c++17 -Wall main.cpp
	a.out < in2
	rm a.out
t3:
	g++ -std=c++17 -Wall main.cpp
	a.out < in3
	rm a.out
