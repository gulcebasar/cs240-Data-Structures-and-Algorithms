all: Main.exe
Main.exe: printer.o pqueue.o job.o main.o
	g++ printer.o pqueue.o job.o main.o -o Main.exe
printer.o: printer.cpp
	g++ -c printer.cpp
pqueue.o: pqueue.cpp
	g++ -c pqueue.cpp
job.o: job.cpp
	g++ -c job.cpp
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm -f *.o Main.exe

