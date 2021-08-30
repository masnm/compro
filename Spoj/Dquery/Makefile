all:
	@cat Makefile
c:
	@g++ -std=c++17 -Wall $(f).cpp
	@rm a.out
r:
	@g++ -std=c++17 -Wall $(f).cpp
	@./a.out
	@rm a.out
d:
	@g++ -g -lm -std=c++17 -Wall -o a.out $(f).cpp
	@gdb ./a.out
	@rm a.out
t:
	@g++ -std=c++17 -Wshadow -Wall -o a.out $(f).cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g -DLOCAL
	@if [ -s in1 ]; then\
		echo "Output one :";\
		./a.out < $(f)in1;\
	fi
	@if [ -s in2 ]; then\
		echo "Output two :";\
		./a.out < $(f)in2;\
	fi
	@if [ -s in3 ]; then\
		echo "Output three :";\
		./a.out < $(f)in3;\
	fi
	@rm a.out
tm:
	@g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o a.out $(f).cpp
	@if [ -s $(f)in1 ]; then\
		echo "Ans is :";\
		cat $(f)out1;\
		echo "Output one :";\
		time ./a.out < $(f)in1;\
	fi
	@if [ -s $(f)in2 ]; then\
		echo "Ans is :";\
		cat $(f)out2;\
		echo "Output two :";\
		time ./a.out < $(f)in2;\
	fi
	@if [ -s $(f)in3 ]; then\
		echo "Ans is :";\
		cat $(f)out3;\
		echo "Output three :";\
		time ./a.out < $(f)in3;\
	fi
	@rm a.out
s:
	@xclip -selection clipboard < $(f).cpp
1:
	@xclip -o > $(f)in1
2:
	@xclip -o > $(f)in2
3:
	@xclip -o > $(f)in3
