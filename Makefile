all:
	@cat Makefile
reset:
	@touch in9
	@rm in*
	@if [ -s a.out ]; then\
		rm a.out;\
	fi
	@cp template main.cpp
	@clear
c:
	@g++ -std=c++17 -Wall main.cpp
	@rm a.out
r:
	@g++ -std=c++17 -Wall main.cpp
	@./a.out
	@rm a.out
d:
	@g++ -g -lm -std=c++17 -Wall -o a.out main.cpp
	@gdb ./a.out
	@rm a.out
t:
	@g++ -std=c++17 -Wshadow -Wall -o a.out main.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
	@if [ -s in1 ]; then\
		echo "Output one :";\
		./a.out < in1;\
	fi
	@if [ -s in2 ]; then\
		echo "Output two :";\
		./a.out < in2;\
	fi
	@if [ -s in3 ]; then\
		echo "Output three :";\
		./a.out < in3;\
	fi
	@rm a.out
tm:
	@g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o a.out main.cpp
	@if [ -s in1 ]; then\
		echo "Output one :";\
		time ./a.out < in1;\
	fi
	@if [ -s in2 ]; then\
		echo "Output two :";\
		time ./a.out < in2;\
	fi
	@if [ -s in3 ]; then\
		echo "Output three :";\
		time ./a.out < in3;\
	fi
	@rm a.out
stc:
	@clear
	@cat in*
git:
	@git add .
	@git commit -S 
	@git push
	@clear
