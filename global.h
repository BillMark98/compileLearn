#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define BSIZE 128
#define NONE -1
#define EOS '\0'

#define NUM 256
#define DIV 257
#define MOD 258
#define ID 259
#define DONE 260

extern int tokenval;   // value of token attribute
extern int lineno;

struct entry {
    char *lexptr;
    int token;
};

extern struct entry symtable[]; // symbol tabel

// init.c
void init();

// emitter.c
void emit(int t, int tval);
// error.c
void error(char * m);

// lexer.c
int lexan();

// parser.c
void parse();
void expr();
void term();
void factor();
void match(int t);

// symbol.c
int lookup(char s[]);
int insert(char s[], int tok);