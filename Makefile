CC = gcc
CFLAGS = -g -Wall -O0 -o
SOURCE = lexer.c parser.c emitter.c symbol.c init.c error.c main.c
start: $(SOURCE) global.h
	$(CC) $(CFLAGS) $@ $(SOURCE)