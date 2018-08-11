all:
	clang++ -fsanitize=address -std=c++11 -Wall roster.cpp -o roster.out
	stdbuf -o 0 ./roster.out
