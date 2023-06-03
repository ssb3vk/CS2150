# Sidhardh Burre, ssb3vk@virginia.edu, 4/20/2021, Makefile
# Makefile for Lab10 Pre-Lab

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall #-fsanitize=address -fno-omit-frame-pointer -g # Enable all warnings
DEBUG=-g
OBJECTS = element.o heap.o huffmanenc.o

Encoding: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)

.PHONY: clean
clean:
	-rm -f *.o *~ a.out




