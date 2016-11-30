CC = g++
CFLAGS = -std=c++11 -w
BINDIR = bin

all: lexer.cpp parser.cpp
	cd server && rm -fr build && mkdir build && cd build && cmake .. && make

main.cpp: server/main.cp

lexer.cpp: server/lexer.l
	cd server && flex -o $@ lexer.l

parser.cpp: server/parser.y
	cd server && bison -o $@ parser.y

fast: ./local/main.cpp
	flex -o ./local/lexer.cpp ./server/lexer.l
	bison -o ./local/parser.cpp ./server/parser.y -v
	$(CC) $(CFLAGS) ./local/main.cpp ./local/lexer.cpp ./local/parser.cpp -o ./local/interpreter
	rm -f ./local/lexer.cpp ./local/parser.cpp ./local/parser.hpp
	clear
	./local/interpreter
