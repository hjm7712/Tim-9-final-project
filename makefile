all: game.exe

game.exe: main.o user.o bullet.o
		g++ -o $@ $^ -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cc
		g++ -std=c++11 -c $^

user.o: user.cc
		g++ -std=c++11 -c $^

bullet.o: bullet.cc
		g++ -std=c++11 -c $^

run:
		./game.exe
clean:
		rm -f *.o game.exe
