#Kobe Soetaert
#Kobe.Soetaert@student.uantwerpen.be
#Datum van indienen: 22/04/2019

#Makefile 
#Compiler
COMPILER = g++
#Macros
CXXFLAGS = -g -std=c++11 -Wall
CVFLAGS = $(shell pkg-config --cflags opencv)
CVLIBS = $(shell pkg-config --libs opencv)

all: test.out

test.out:test.o 
	${COMPILER}  -o test.out test.o ${LDFLAGS} $(CVFLAGS) $(CVLIBS) 

test.o:test.cpp
	${COMPILER} $(CXXFLAGS) $(CVFLAGS) $(CVLIBS) -c test.cpp

#hough:hough.o
#	${COMPILER} -o hough hough.o  ${LDFLAGS} $(CVFLAGS) $(CVLIBS)

#hough.o:hough.cpp hough.h
#	${COMPILER} -c  ${CXXFLAGS} $(CVFLAGS) $(CVLIBS)  hough.cpp
	
clean: 
	rm *.o
	rm test.out
