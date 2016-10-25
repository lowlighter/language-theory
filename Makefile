CC = g++
CFLAGS = -std=c++11 -w
BINDIR = bin

lexer: flex lexer.cpp
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) lexer.cpp -o $(BINDIR)/$@
	rm -f lexer.cpp

flex: lexer.l
	flex -o lexer.cpp $^
