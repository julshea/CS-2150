#Julia Shea (jts6mq)-12:30 lab
CXX=clang++ $(CXXFLAGS)
CXXFLAGS= -Wall -O2 -std=c++11
DEBUG=-Wall -g
OFILES = BSTPathTest.o BinaryNode.o BinarySearchTree.o

a.out: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES) 
	
clean:
	-rm -f *.o *~ a.out

BinaryNode.o: BinaryNode.cpp BinaryNode.h
BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h BinaryNode.h
BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h

.SUFFIXES: .o .cpp
