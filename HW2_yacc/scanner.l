%{
	/* from template */
	#define LIST     //strcat(buf,yytext)
	#define token(t) {/*LIST; cout << "<'" << t << "'>" << endl;*/}
	#define tokenInteger(t,i) {/*LIST; printf("<%s: %d>\n",t,i);*/}
	#define tokenFloat(t,i) {/*LIST; printf("<%s: %lf>\n",t,i);*/}
	#define tokenString(t,s) {/*LIST; printf("<%s: %s>\n",t,s);*/}

	#define MAX_LINE_LENG 256

	int linenum = 1;
	char buf[MAX_LINE_LENG];
	#include <stdio.h>
	#include <memory.h>
	#include <string.h>
	#include <stdlib.h>
    #include "y.tab.hpp"
    using namespace std;
    
%}

%pointer

%x COMMENT

/*///////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////*/
/*                   regex declare                   */
/*///////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////*/

/* Delims Field*/
delims [,:;()\[\]\{\}\.]

/* Operator Field */
arithmetic [-/%\*\+]
relational <|<=|>=|>|==|!=
logical "&&"|"||"|"!"
assign =

operators {arithmetic}|{relational}|{logical}|{assign}


/* Num Field*/
integer [0-9]+
realnum [+-]?{integer}"."{integer}([Ee][+-]?{integer})?

/* Word Field */
string \"(\"\"|[^\"\n])*\"
Char   \'([A-Za-z0-9])\'

/* ID Field*/
id  [a-zA-Z]([0-9a-zA-Z]*)

/* Comments Field */
linecomments "//"[^\n]*
blockcommentstart "/*"
blockcommentend "*/"

/*///////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////*/
/*                   regex declare                   */
/*///////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////*/

%%


boolean {
	token("BOOLEAN");
    return BOOLEAN;
}

break {
	token("BREAK");
    return BREAK;
}
char {
	token("CHAR");
    return CHAR;
}
case {
	token("CASE");
    return CASE;
}
class {
    token("CLASS");
    return CLASS;
}
continue {
	token("CONTINUE");
    return CONTINUE;
}
def {
    token("DEF")
    return DEF;
}
do {
    token("DO")
    return DO;
}
else { 
    token("ELSE")
    return ELSE;
}
exit {
    token("EXIT")
    return EXIT;
}
false {
    token("FALSE")
    yylval.bVAL = false;
    return BOOL_VALUE;
}
for {
    token("FOR")
    return FOR;
}
if {
    token("IF")
    return IF;
}
int {
    token("INT")
    return INT;
}
null {
    token("NULL")
    return _NULL_;
}
object {
    token("OBJECT")
    return OBJECT;
}
print {
    token("PRINT")
    return PRINT;
}
println {
    token("PRINTLN")
    return PRINTLN;
}
repeat {
    token("REPEAT")
    return REPEAT;
}
return {
    token("RETURN")
    return RETURN;
}
string {
    token("STRING")
    return STRING;
}
to {
    token("TO")
    return TO;
}
true {
    token("TRUE")
    yylval.bVAL = true;
    return BOOL_VALUE;
}
type {
    token("TYPE")
    return TYPE;
}
val {
    token("VAL")
    return VAL;
}
var {
    token("VAR")
    return VAR;
}
while {
    token("WHILE")
    return WHILE;
}
read {
    token("READ")
    return READ;
}
float {
    token("FLOAT")
    return FLOAT;
}


{delims} {
	token(yytext);
    return *yytext;
}

{arithmetic} {
    token(yytext);
    return *yytext;
}


{assign} {
    LIST;
    return ASSIGN;
}

"<" {
    LIST;
    return LESSTHEN;
}
"<=" {
    LIST;
    return LESSEQUAL;
}
">=" {
    LIST;
    return MOREEQUAL;
}
">" {
    LIST;
    return MORETHEN;
}
"==" {
    LIST;
    return EQUAL;
}
"!=" {
    LIST;
    return NOTEQUAL;
}
"&&" {
    LIST;
    return LG_AND;
}
"||" {
    LIST;
    return LG_OR;
}
"!" {
    LIST;
    return LG_NOT;
}


{string} {
	/* deal with special condition */
	string str = "";
    for(int i = 1; i < yyleng - 1; i++){
        if(yytext[i] == '"') i++;
        str += yytext[i];
    }
    token(str);
    yylval.sVAL = new string(str);
    return STRING_VALUE;
	
}
{Char} {
    tokenString("char", yytext);
    yylval.cVAL = yytext[1];
    return CHAR_VALUE;
}


{integer} {
	int temp;
	sscanf(yytext,"%d",&temp);
	tokenInteger("integer",temp)
    yylval.iVAL = temp;
    return INT_VALUE;
}
{realnum} {
	float temp;
	sscanf(yytext,"%f",&temp);
	tokenFloat("real",temp);
    yylval.fVAL = temp;
    return FLOAT_VALUE;
} 

{id} {
	tokenString("id",yytext);
    yylval.sVAL = new string(yytext);
    return ID;
}

{linecomments} {
	LIST;
}

{blockcommentstart} {
	LIST;
	BEGIN COMMENT;
}

<COMMENT>{blockcommentend} {
	LIST;
	BEGIN INITIAL;
}
<COMMENT>. {
	LIST;
}

<COMMENT>\n {
	LIST;
	printf("%d: %s", linenum++, buf);
	buf[0] = '\0';	
}

\n {
	LIST;
	printf("%d: %s", linenum++, buf);
    //charnum = 0;
	buf[0] = '\0';
}

[ \t]* {
    LIST;
}

. {
	LIST;
	printf("%d:%s\n", linenum, buf);
	printf("bad character:’%s’\n",yytext);
	exit(-1);
}

%%
