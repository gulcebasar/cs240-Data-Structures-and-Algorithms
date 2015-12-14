all: BST.exe
BST.exe: bst.o mainBST.o
	g++ bst.o mainBST.o -o BST.exe
bst.o: bst.cpp
	g++ -c bst.cpp
mainBST.o: mainBST.cpp
	g++ -c mainBST.cpp
clean:
	rm -f *.o BST.exe

