all: main.exe

main.exe: main.o
		g++ -o $@ $^ -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cc
		g++ -std=c++11 -c $^

run:
		./main.exe
