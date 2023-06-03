# Sidhardh Burre, ssb3vk@virginia.edu, 3/27/2021, Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g
OBJECTS = timer.o wordPuzzle.o hashTable.o

WordPuzzle: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

timer.o: timer.cpp timer.h
wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
hashTable.o: hashTable.cpp hashTable.h



