CC = g++
CFLAGS = -std=c++11 -w
BINDIR = bin

all: main.cpp lexer.cpp parser.cpp
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $(BINDIR)/interpreter
	rm -f lexer.cpp parser.cpp parser.hpp

lexer.cpp: lexer.l
	flex -o $@ $^

parser.cpp: parser.y
	bison -o $@ $^
