all:
	clang++ -fsanitize=address -std=c++11 -Wall harness.cpp -o harness.out
	./harness.out
