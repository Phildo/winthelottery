SRCDIR = ../src
BINDIR = ../bin
CC = g++
DEBUG = -ggdb3
DEBUGGER = gdb
CFLAGS = -Wall
LFLAGS = -Wall

build:
	$(CC) $(CFLAGS) $(SRCDIR)/test_main.cpp $(SRCDIR)/model.cpp -o $(BINDIR)/test.out && $(BINDIR)/test.out

install: build
	

debug:
	$(CC) $(DEBUG) $(CFLAGS) $(SRCDIR)/test_main.cpp $(SRCDIR)/model.cpp -o $(BINDIR)/test.out && $(DEBUGGER) $(BINDIR)/test.out

