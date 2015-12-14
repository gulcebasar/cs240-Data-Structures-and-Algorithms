all: Main.exe
Main.exe: main.o Fraction.o
	g++ main.o Fraction.o -o Main.exe
main.o: main.cpp
	g++ -c main.cpp
Fraction.o: Fraction.cpp
	g++ -c Fraction.cpp
clean:
	rm -f *.o Main.exe

