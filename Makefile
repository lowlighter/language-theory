CC = g++
CFLAGS = -std=c++11 -w
BINDIR = bin

all: lexer.cpp parser.cpp
	cd server && rm -fr build && mkdir build && cd build && cmake .. && make

lexer.cpp: server/lexer.l
	cd server && flex -o $@ lexer.l

parser.cpp: server/parser.y
	cd server && bison -o $@ parser.y
