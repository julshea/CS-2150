#Julia Shea (jts6mq)-12:30 lab- postlab5
CXX=clang++ $(CXXFLAGS)
CXXFLAGS= -Wall -O2 -std=c++11
DEBUG=-Wall -g
OFILES = AVLPathTest.o AVLNode.o AVLTree.o

a.out: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES) 
        
clean:
	-rm -f *.o *~ a.out

AVLNode.o: AVLNode.cpp AVLNode.h
AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h
AVLTree.o: AVLTree.cpp AVLTree.h AVLNode.h


.SUFFIXES: .o .cpp
