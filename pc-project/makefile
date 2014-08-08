SRCDIR = ../src
BINDIR = ../bin
CC = g++
DEBUG = -ggdb3
DEBUGGER = gdb
CFLAGS = -Wall
LFLAGS = -Wall

SOURCES=$(SRCDIR)/main.cpp $(SRCDIR)/game.cpp $(SRCDIR)/graphics.cpp $(SRCDIR)/model.cpp $(SRCDIR)/units.cpp

build:
	$(CC) $(CFLAGS) $(SOURCES) -o $(BINDIR)/pc.out && $(BINDIR)/pc.out

install: build
	

debug:
	$(CC) $(DEBUG) $(CFLAGS) $(SOURCES) -o $(BINDIR)/pc.out && $(DEBUGGER) $(BINDIR)/pc.out

