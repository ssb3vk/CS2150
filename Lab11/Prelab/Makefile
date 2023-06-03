# Sidhardh Burre, ssb3vk@virginia.edu, 4/28/2021, Makefile
# Makefile for Lab11 Pre-Lab

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall #-fsanitize=address -fno-omit-frame-pointer -g # Enable all warnings
DEBUG=-g
OBJECTS = topological.o

Topological: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)
	doxygen

.PHONY: clean
clean:
	-rm -f *.o *~ a.out




