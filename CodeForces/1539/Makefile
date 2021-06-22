all:
	@cat Makefile
#%: %.cpp
#	@g++ -std=c++17 -Wshadow -Wall -o $@ $^ -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
#	@./$@
#	@rm $@
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
	@g++ -std=c++17 -Wshadow -Wall -o a.out $(f).cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
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
	@g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o a.out $(f).cpp
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
s:
	@xclip -selection clipboard < $(f).cpp
1:
	@xclip -o > in1
2:
	@xclip -o > in2
3:
	@xclip -o > in3
clear:
	@touch in9
	@rm in*
	@rm *.out
