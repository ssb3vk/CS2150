# Sidhardh Burre, ssb3vk@virginia.edu, 4/15/2021, Makefile
# Makefile for CS 2150 In-lab 9

# Defines the C compiler we'll be using
C = clang

# Defines the flags we'll be passing to the C++ compiler
CFLAGS = -Wall -g #-fsanitize=address -fno-omit-frame-pointer -g

# Defines the assembler
AS = nasm

# Defines the flags for the assembler
ASFLAGS = -f elf64 -g

# All of the .o files for our program
OBJECTS = linkedlist.o

# Compile our files into a.out
a.out: $(OBJECTS)
	$(C) $(CFLAGS) $(OBJECTS)

# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not).  This removes object files (*.o) and Emacs
# backup files (*~)
clean:
	-rm -f *.o *~ 
