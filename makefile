###
### @file - lab2_makefile
### @author - Michael Nutt <nuttm@oregonstate.edu>
### @description - makefile for lab 2 - Character Counter

#
# LangtonAnt
#

CXX = g++

CFLAGS = -std=c++11

.PHONY: clean

characterCounter: characterCounter.o countLetters.o outputLetters.o
	$(CXX) $(CFLAGS) -g characterCounter.o countLetters.o outputLetters.o -o characterCounter

characterCounter.o: characterCounter.cpp
	$(CXX) $(CFLAGS) -c characterCounter.cpp

countLetters.o: countLetters.cpp countLetters.hpp
	$(CXX) $(CFLAGS) -c countLetters.cpp

outputLetters.o: outputLetters.cpp outputLetters.hpp
	$(CXX) $(CFLAGS) -c outputLetters.cpp

clean:
	rm *.o characterCounter

