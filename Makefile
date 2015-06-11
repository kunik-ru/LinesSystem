CC=g++

CFLAGS=-c -Wall

LIBS=-lglut -lGLU -lGL

all: clean linesSystem

build: linesSystem

linesSystem: Main.o Draw.o Recognize.o
	$(CC) Main.o Draw.o Recognize.o $(LIBS) -o linesSystem

Main.o: Main.cpp
	$(CC) $(CFLAGS) Main.cpp

Draw.o: Draw.cpp
	$(CC) $(CFLAGS) Draw.cpp

Recognize.o: Recognize.cpp
	$(CC) $(CFLAGS) Recognize.cpp

clean:
	rm -rf *.o linesSystem
