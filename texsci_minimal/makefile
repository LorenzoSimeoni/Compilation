
CC=gcc
CFLAGS=-g

all: texcc

texcc: texcc.c texcc.tab.o lex.yy.o lib.o
	gcc -o $@ $^

texcc.tab.o: texcc.tab.c lib.h

texcc.tab.c: texcc.y
	bison -d $<

lex.yy.o: lex.yy.c

lex.yy.c: texcc.l texcc.tab.c
	flex texcc.l -lfl

lib.o: CFLAGS+=-Wall -Wextra
lib.o: lib.c lib.h

clean:
	rm -f texcc *.o texcc.tab.c texcc.tab.h lex.yy.c *~
