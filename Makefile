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

all:opencv.out ellipseimage.o


opencvt.out:opencv.o ellipseimage.o
	${COMPILER}  -o opencv.out opencv.o ellipseimage.o  ${LDFLAGS} $(CVFLAGS) $(CVLIBS) 

opencv.o:opencv.cpp
	${COMPILER} $(CXXFLAGS) $(CVFLAGS) $(CVLIBS) -c opencv.cpp

ellipseimage.o: ellipseimage.cpp ellipseimage.h
	$(COMPILER) -c ellipseimage.cpp ${LIBS} ${LDLIBS} ${CFLAGS} ${CPPFLAGS}
	
clean: 
	rm *.o
	rm test.out
