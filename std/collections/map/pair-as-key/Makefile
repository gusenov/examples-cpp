example_program : main.o
	clang++ main.o -o example_program

main.o : main.cc
	clang++ --std=c++17 -c main.cc

clean :
	rm example_program *.o
