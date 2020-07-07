all: parser

parser: lex.yy.cpp y.tab.cpp Tables.hpp
	g++ y.tab.cpp  -o parser -ll -ly  -std=c++11  -Wno-deprecated-register

lex.yy.cpp: scanner.l
	lex -o lex.yy.cpp scanner.l

y.tab.cpp: parser.y
	yacc -d parser.y -o y.tab.cpp

clean:
	rm -r -f parser lex.yy.cpp y.tab.cpp y.tab.hpp *.jasm *.class

run:
	./parser $(file).scala
	./javaa_mac $(file).scala.jasm
	java $(file)