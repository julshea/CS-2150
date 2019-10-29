#Filename: Makefile
#Julia Shea - jts6mq - lab6 - 10/20/2019

CXX = clang++ $(CXXFLAGS)

CXXFLAGS = -Wall -O2 -std=c++11

DEBUG = -Wall -g
OFILES = wordPuzzle.o hashTable.o timer.o 
a.out: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES) 

main: $(OFILES)
	$(CXX) $(OFILES)

clean: 
	-rm -f *.o

wordPuzzle.o: wordPuzzle.cpp 
hashTable.o: hashTable.cpp
timer.o: timer.cpp

.SUFFIXES: .o .cpp
