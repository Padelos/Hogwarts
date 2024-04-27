build:
	g++ -c cords.cpp -o cords.o
	g++ -c gameobject.cpp -o gameobject.o
	g++ -c gem.cpp -o gem.o
	g++ -c player.cpp -o player.o
	g++ -c map.cpp -o map.o
	g++ -c ai.cpp -o ai.o
	g++ -c gameengine.cpp -o gameengine.o
	g++ *.o main.cpp -o main.out -lncurses

run: build
	./main.out 'map10-20.txt'

map:
	g++ -c cords.cpp -o cords.o
	g++ -c gameobject.cpp -o gameobject.o
	g++ -c gem.cpp -o gem.o
	g++ -c player.cpp -o player.o
	g++ map.cpp -c -o map.o
	g++ player.o gem.o gameobject.o cords.o map.o map.test.cpp -o map.test.out
	./map.test.out "map10-20.txt"

cords:
	g++ cords.cpp -c -o cords.o
	g++ cords.o cords.test.cpp -o cords.test.out
	./cords.test.out

gem:
	g++ -c cords.cpp -o cords.o
	g++ -c gameobject.cpp -o gameobject.o
	g++ -c gem.cpp -o gem.o
	g++ gem.o gameobject.o cords.o gem.test.cpp -o gem.test.out
	./gem.test.out

player:
	g++ -c cords.cpp -o cords.o
	g++ -c gameobject.cpp -o gameobject.o
	g++ -c player.cpp -o player.o
	g++ player.o gameobject.o cords.o player.test.cpp -o player.test.out
	./player.test.out

game:
	g++ -c cords.cpp -o cords.o
	g++ -c gameobject.cpp -o gameobject.o
	g++ -c gem.cpp -o gem.o
	g++ -c player.cpp -o player.o
	g++ map.cpp -c -o map.o
	g++ -c ai.cpp -o ai.o
	g++ -c gameengine.cpp -o gameengine.o
	g++ ai.o gameengine.o player.o gem.o gameobject.o cords.o map.o gameengine.test.cpp -o gameengine.test.out -lncurses
	./gameengine.test.out "map10-20.txt"

ai:
	g++ -c cords.cpp -o cords.o
	g++ -c gameobject.cpp -o gameobject.o
	g++ -c gem.cpp -o gem.o
	g++ -c player.cpp -o player.o
	g++ map.cpp -c -o map.o
	g++ -c ai.cpp -o ai.o
	g++ ai.o player.o gem.o gameobject.o cords.o map.o ai.test.cpp -o ai.test.out
	./ai.test.out

clean:
	rm *.o
	rm *.out