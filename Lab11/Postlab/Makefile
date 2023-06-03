# Sidhardh Burre, ssb3vk@virginia.edu, 4/28/2021, Makefile
# Makefile for Lab11 In-Lab

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-O2 #-Wall -fsanitize=address -fno-omit-frame-pointer -g # Enable all warnings
DEBUG=-g
OBJECTS = middleearth.o traveling.cpp
 
Traveling: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)
	doxygen

.PHONY: clean
clean:
	-rm -f *.o *~ a.out




