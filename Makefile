all:
	clang++ -fsanitize=address -std=c++11 -Wall roster.cpp -o roster.out
	./roster.out
