all: Hash.exe
Hash.exe: hashTable.o mainHash.o
	g++ hashTable.o mainHash.o -o Hash.exe
hashTable.o: hashTable.cpp
	g++ -c hashTable.cpp
mainHash.o: mainHash.cpp
	g++ -c mainHash.cpp
clean:
	rm -f *.o Hash.exe

