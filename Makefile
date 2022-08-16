build:
	g++ -o main main.cpp car.h car.cpp termcolor.hpp

buildclang:
	clang++ -o main *.cpp