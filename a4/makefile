all: Poly.exe
Poly.exe: Poly.o Test.o
	g++ Poly.o Test.o -o Poly.exe
Poly.o: Poly.cpp
	g++ -c Poly.cpp
Test.o: Test.cpp
	g++ -c Test.cpp
clean:
	rm -f *.o Poly.exe

