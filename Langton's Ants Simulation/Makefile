#############################################################################
# File: Makefile
# Author: Ju Hye An
# Date: 10/1/2016
# Description: A makefile that creates program Lab1
##############################################################################

JuAn_Assignment1: main.o ant.o
	g++ main.o ant.o  -o JuAn_Assignment1

main.o: main.cpp
	g++ -c main.cpp

ant.o: ant.cpp ant.hpp
	g++ -c ant.cpp

clean:
	rm -f a.out *.o *~
