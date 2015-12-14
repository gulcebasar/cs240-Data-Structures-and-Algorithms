all: Map.exe
Map.exe: map.o main.o
	g++ map.o main.o -o Map.exe
map.o: map.cpp
	g++ -c map.cpp
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm -f *.o Map.exe

