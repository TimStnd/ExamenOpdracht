
#Makefile 

SHELL = /bin/bash
#Compiler
COMPILER = g++ -g -std=c++11 -Wall
#Macros
CPPFLAGS = $(shell pkg-config --cflags opencv)
LDLIBS = $(shell pkg-config --libs opencv)


all:main


main: main.cpp
	$(COMPILER) ellipsfinder.h ellipsfinder.cpp main.cpp -o run ${LDLIBS} ${CPPFLAGS}

clean : 
	rm run
	


