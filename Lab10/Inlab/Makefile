# Sidhardh Burre, ssb3vk@virginia.edu, 4/21/2021, Makefile
# Makefile for Lab10 In-Lab

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall #-fsanitize=address -fno-omit-frame-pointer -g # Enable all warnings
DEBUG=-g
OBJECTS = element.o huffmandec.o

Decoding: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)

.PHONY: clean
clean:
	-rm -f *.o *~ a.out




