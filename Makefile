CC = g++
CFLAGS = -std=c++11 -w -I /usr/local/include
BINDIR = bin

all: flex bison main.cpp lexer.cpp parser.cpp
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) main.cpp lexer.cpp parser.cpp -o $(BINDIR)/interpreter
	rm -f lexer.cpp parser.cpp parser.hpp

flex: lexer.l
	flex -o lexer.cpp $^

bison: parser.y
	bison -o parser.cpp $^
