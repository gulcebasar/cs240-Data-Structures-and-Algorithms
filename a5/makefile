all: Stack.exe
Stack.exe: Stack.o File.o
	g++ Stack.o File.o -o Stack.exe
Stack.o: Stack.cpp
	g++ -c Stack.cpp
File.o: File.cpp
	g++ -c File.cpp
clean:
	rm -f *.o Stack.exe

