%{
	#define LIST     strcat(buf,yytext)
	#define token(t) {LIST; printf("<'%s'>\n",t);}
	#define tokenInteger(t,i) {LIST; printf("<%s: %d>\n",t,i);}
	#define tokenFloat(t,i) {LIST; printf("<%s: %lf>\n",t,i);}
	#define tokenString(t,s) {LIST; printf("<%s: %s>\n",t,s);}

	#define MAX_LINE_LENG 256

	int linenum = 1;
	char buf[MAX_LINE_LENG];
	#include <stdio.h>
	#include <memory.h>
	#include <string.h>
	#include <stdlib.h>

	typedef struct
	{
    	char *Key;
    	int data;
    	int index;
    	struct Item *next;
	} Item;

	typedef struct
	{
    	Item *items;
    	int size;
	} SymbolTable;

	SymbolTable *create();
	int lookup(char *Key, SymbolTable *Table);
	void insert(char *Key, SymbolTable *Table);
	void dump(SymbolTable *Table);

	SymbolTable * TABLE = NULL;

%}

%pointer

%x COMMENT

delims [,:;()\[\]\{\}\.]

arithmetic [-/%\*\+\=]
relational <|<=|>=|>|==|!=
logical "&&"|"||"|"!"

operators {arithmetic}|{relational}|{logical}

integer [0-9]+
realnum [+-]?{integer}"."{integer}([Ee][+-]?{integer})?
string \"[^\"]*\"

id  [a-zA-Z]([0-9a-zA-Z]*)

linecomments "//"[^\n]*

blockcommentstart "/*"
blockcommentend "*/"

%%

 // Keywords

boolean {
	token("BOOLEAN");
}
break {
	token("BREAK");
}
char {
	token("CHAR");
}
case {
	token("CASE");
}
class {
    token("CLASS")
}
continue {
	token("CONTINUE");
}
def {
    token("DEF")
}
do {
    token("DO")
}
else { 
    token("ELSE")
}
exit {
    token("EXIT")
}
false {
    token("FALSE")
}
for {
    token("FOR")
}
if {
    token("IF")
}
int {
    token("INT")
}
null {
    token("NULL")
}
object {
    token("OBJECT")
}
print {
    token("PRINT")
}
println {
    token("PRINTLN")
}
repeat {
    token("REPEAT")
}
return {
    token("RETURN")
}
string {
    token("STRING")
}
to {
    token("TO")
}
true {
    token("TRUE")
}
type {
    token("TYPE")
}
val {
    token("VAL")
}
var {
    token("VAR")
}
while {
    token("WHILE")
}

{delims} {
	token(yytext);
}

{operators} {
	token(yytext);
}

{string} {
	char c = input();
	if(c =='"'){
		unput(c);
		yymore();
	}
	else{
		char * temp = (char*)malloc(yyleng-1);
		int i;
		for( i = 1 ; i < yyleng ; ++i){
			if(yytext[i]=='"')
			break;
		}
		if(i==yyleng-1){
            
			strcpy(temp,yytext);
		}
		else{
			strncpy(temp,yytext,i);
			strcat(temp,yytext+i+1);
		}
        char * temp2 = (char*)malloc(yyleng);
        strncpy(temp2,temp+1,strlen(temp)-2);
		tokenString("string",temp2);
		free(temp);
        free(temp2);
		unput(c);
	}
}

{integer} {
	int tmp;
	sscanf(yytext,"%d",&tmp);
	tokenInteger("integer",tmp)
}

{realnum} {
	double tmp;
	sscanf(yytext,"%lf",&tmp);
	tokenFloat("real",tmp);
} 

{id} {
	tokenString("id",yytext);
	insert(yytext,TABLE);
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

SymbolTable *create()
{
    SymbolTable *temp = malloc(sizeof(SymbolTable));
    temp->items = NULL;
    temp->size = 0;
    return temp;
}
int lookup(char *Key, SymbolTable *Table)
{
    if (Table->size == 0 || Table->items == NULL)
        return -1;
    Item *ptr = Table->items;
    while (ptr != NULL)
    {
        if (strcmp(Key, ptr->Key) == 0)
            return ptr->index;
        else
            ptr = ptr->next;
    }
    return -1;
}
void insert(char *Key, SymbolTable *Table)
{
    int flag = lookup(Key, Table);
    if (flag >= 0)
    {
        Item *ptr = Table->items;
        while (ptr != NULL)
        {
            if (strcmp(Key, ptr->Key) == 0)ptr->data += 1;
            ptr = ptr->next;
        }
    }
    else
    {
		Item *newItem = malloc(sizeof(Item));
		newItem->Key = malloc(strlen(Key)+1);
		strcpy(newItem->Key, Key);
        newItem->data = 1;
        newItem->index = 0;
		newItem->next = NULL;
		if (Table->size == 0){
			Table->items = newItem;
			Table->size++;
		}
        else{
			Item *ptr = Table->items;
        	while (ptr != NULL)
        	{
				if(ptr->index == Table->size -1 ){
					ptr->next = newItem;
					newItem->index = ptr->index + 1;
					Table->size++;
					break;
				}
				ptr = ptr->next;
        	}
		}
    }
}
void dump(SymbolTable *Table)
{
    //printf("Table size : %d\n", Table->size);
    if (Table->size == 0 || Table->items == NULL)
    {
        printf("There is Nothing in Table\n");
        return;
    }
    Item *ptr = malloc(sizeof(Item));
    ptr = Table->items;
    while (ptr != NULL)
    {
        printf("%s\n", ptr->Key,ptr->data);
        ptr = ptr->next;
    }
}

int main(int argc,char ** argv )
{
	++argv, --argc; 

	if ( argc > 0 )
	    yyin = fopen( argv[0], "r" );
	else
	    yyin = stdin;

	if(!yyin){
		printf("Load File Failed\n");
		return -1;
	} 
	TABLE = create();
	yylex();
	printf("\nSymbol Table:\n");
	dump(TABLE);
    
}
