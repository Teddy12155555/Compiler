all: Scanner

CC = gcc

Scanner: lex.yy.c
	$(CC) -o Result lex.yy.c -ll

.PHONY: clean,run
clean:
	rm Scanner 

run:
	./Result HelloWorld.scala
