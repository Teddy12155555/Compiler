%{
#include <iostream>
#include "Tables.hpp"
#include "lex.yy.cpp"
#define Trace(s)        //{cout << "Parser Msg : " << s << endl;}
#define Warning(t)      {printf(t);printf("\n");} 

bool isHasMain = false;
// yyeror define
void yyerror(string error_msg){
    cout << "=============== Error ===============" << endl;
    cout << buf << " ( " <<  error_msg <<  " )" << endl;
    cout << "============ Parser Fail ============" << endl;
    cout << "Terminal Casuse By Error" << endl << endl;
    exit(-1);
}
void yyerror(string error_msg,string t)
{
    cout << "=============== Error ===============" << endl;
    cout << buf << " ( " <<  error_msg <<  ")" << endl;
    cout << "With bad string : " << t << endl;
    cout << "============ Parser Fail ============" << endl;
    cout << "Terminal Casuse By Error" << endl << endl;
    exit(-1);
}
// Create a new global tables
GlobalTABLE SYMBOLTABLES;
bool global_INSERT(IDContent * Id);

// Java 
streampos fp;
int varStackID = 0;
int tabCounts = 1;
// extern vars
fstream JavaCode;
int JumpCount;
//

string className = "";
// some bool flags
bool returnFlag = false;
bool IsElseIf = false;
//
vector<vector<int>> IfJumpPoints;
vector<vector<int>> WhileJumpPoints;

%}

// some import yylval
%union {
    float fVAL;
    int iVAL;
    bool bVAL;
    string * sVAL;
    char cVAL;
    DataValue * dataValue;

    // Enum
    ID_DATA_TYPE DATA_TYPE;
    // Block
    map<string, IDContent *>* blockTABLE;
    // Function Call
    vector<DataValue*>* func_CallArgs;
    vector<IDContent*>* func_DeclareArgs;
    IDContent* func_DeclareArg;
}

// show detail error message
%error-verbose

// Tokens keyword
%token  BOOLEAN BREAK CHAR CASE CLASS CONTINUE DEF DO ELSE EXIT FALSE FLOAT FOR IF INT OBJECT PRINT PRINTLN REPEAT RETURN STRING TO TRUE TYPE VAL VAR WHILE ASSIGN READ _NULL_

// Diff Value Declare
%token <sVAL>  ID

%token <bVAL> BOOL_VALUE
%token <iVAL> INT_VALUE 
%token <sVAL> STRING_VALUE
%token <fVAL> FLOAT_VALUE
%token <cVAL> CHAR_VALUE


// Type Declare
%type <dataValue> DATA_VALUE EXPRESSION FUNCTION_RETURN FUNCTION_CALL
%type <DATA_TYPE> TYPE_ FUNCTION_RETURN_TYPE
%type <blockTABLE> BLOCK FUNCTION_SCOPE
// Funct
%type <func_CallArgs> COMMA_SEPARATED_EXPRESSION
%type <func_DeclareArgs> ARGS
%type <func_DeclareArg> ARG
// //////////////////////////////
//Jave
%type <bVAL> BLOCK_OR_SIMPLE WHILE_BLOCK_OR_SIMPLE

%nonassoc UMINUS
%left LG_AND LG_OR LG_NOT
%left LESSTHEN LESSEQUAL MOREEQUAL MORETHEN EQUAL NOTEQUAL
%left '+' '-'
%left '*' '/' '%'

%start PROGRAM

%%

PROGRAM : 
        OBJECT ID
        {
            
            Trace("========== Parsering Start ! ==========");
            // Symbol Table push 
            // Init with program entry point 
            // and start to pasre
            if(SYMBOLTABLES.insertTABLE(new IDContent(*$2,OBJECT_TYPE)))
            {
                cout << "Symbol Tables Successed to Init" << endl;
            }
            else
            {
                yyerror("This ID Already Exist(from OBJ ID)",*$2);
            }

            className = *$2;
            JavaCode << "class " << *$2 << "{" << endl;
        }
        '{' OBJECT_CONTENTS '}'
        {
            //Trace("");
            JavaCode << "}" << endl;
        }

// { OBJ content }
OBJECT_CONTENTS : FUNCTIONS OBJECT_CONTENTS 
                | VARIABLES OBJECT_CONTENTS
                |
                ;
//
// ===========================
// ======== Variables ========
// ===========================
//
VARIABLES   :   VAR_VARIABLE
            |   VAL_VARIABLE
            ;

VAL_VARIABLE    :   VAL ID 
                {
                    fp = JavaCode.tellg();
                }
                ASSIGN EXPRESSION
                {
                    Trace("VAL ID = EXPRESSION");
                    // Create new const var to gloabl Tables
                    if(SYMBOLTABLES.insertTABLE(new IDContent(*$2,CONST_TYPE,$5)))
                    {

                    }
                    else
                    {
                        yyerror("ID error",*$2);
                    }
                    JavaCode.seekg(fp);
                }
                |   VAL ID ':' TYPE_ 
                {
                    fp = JavaCode.tellg();
                }
                ASSIGN EXPRESSION
                {
                    Trace("VAL ID : TYPE = EXPRESSION");
                    if($4 != $7->getDataType())
                    {
                        yyerror("Type Error, Not match(assign diff type)");
                    }
                    // Create new const var to gloabl Tables
                    if(SYMBOLTABLES.insertTABLE(new IDContent(*$2,CONST_TYPE,$7)))
                    {
                        // Successed
                    }
                    else
                    {
                        yyerror("ID error",*$2);
                    }
                    JavaCode.seekg(fp);
                }

VAR_VARIABLE    :   VAR ID ASSIGN EXPRESSION
                {
                    Trace("VAR ID = EXPRESSION");
                    if(SYMBOLTABLES.insertTABLE(new IDContent(*$2,VAR_TYPE,$4)))
                    {

                    }
                    else
                    {
                        yyerror("ID Error(VAR ID = EXPRESSION)");
                    }

                    IDContent * Id = SYMBOLTABLES.lookupTABLE(*$2);
                    if (SYMBOLTABLES.getTop() == 0)
                    {
                        GlobalVarCode(*$2);
                        JavaCode << "\t\tputstatic int " << className << "." << *$2 << endl;
                    }
                    else
                    {
                        Id->stackID = varStackID;
                        StoreCode(varStackID++);
                        
                    }
                }
                |   VAR ID ':' TYPE_ ASSIGN EXPRESSION
                {
                    
                    Trace("VAR ID : TYPE = EXPRESSION");
                    if($4 != $6->getDataType())
                    {
                        yyerror("Type Error, Not match(assign diff type)");
                    }
                    if(SYMBOLTABLES.insertTABLE(new IDContent(*$2,VAR_TYPE,$6)))
                    {
                        // create new id(var)
                    }  
                    else
                    {
                        yyerror("ID Error(VAR ID : TYPE = EXPRESSION)",*$2);
                    }

                    IDContent * Id = SYMBOLTABLES.lookupTABLE(*$2);
                    if (SYMBOLTABLES.getTop() == 0)
                    {
                        GlobalVarCode(*$2);
                        JavaCode << "\t\tputstatic int " << className << "." << *$2 << endl;
                    }
                    else
                    {
                        Id->stackID = varStackID;
                        StoreCode(varStackID++);
                    }

                }
                |   VAR ID ':' TYPE_
                {
                    Trace("VAR ID : TYPE ");
                    if(SYMBOLTABLES.insertTABLE(new IDContent(*$2,VAR_TYPE,$4)))
                    {
                        //cout << "Debug : Insert " << *$2 << " as new ID !!!" << endl;
                        
                    }
                    else
                    {
                        yyerror("ID Error(VAR ID : TYPE )",*$2);
                    }

                    IDContent * Id = SYMBOLTABLES.lookupTABLE(*$2);
                    if (SYMBOLTABLES.getTop() == 0)
                    {
                        GlobalVarCode(*$2);
                        //JavaCode << "\t\tputstatic int " << className << "." << *$2 << endl;
                    }
                    else
                    {
                        PushCode(0);
                        Id->stackID = varStackID;
                        StoreCode(varStackID++);
                    }

                }
                |   VAR ID ':' TYPE_ '[' INT_VALUE ']'
                {
                    Trace("VAR ID : TYPE [ INT VALUE ]");
                    if(SYMBOLTABLES.insertTABLE(new IDContent(*$2,ARRAY_TYPE,$4,$6)))
                    {
                        
                    }
                    else
                    {
                        yyerror("ID Error(VAR ID : TYPE [ INT VALUE ])",*$2);
                    }
                }
                |   VAR ID
                {
                    Trace("VAR ID ");
                    if(SYMBOLTABLES.insertTABLE(new IDContent(*$2,VAR_TYPE,NIL_TYPE)))
                    {

                    }
                    else
                    {
                        yyerror("ID Error(VAR ID : TYPE )",*$2);
                    }

                    IDContent * Id = SYMBOLTABLES.lookupTABLE(*$2);
                    if (SYMBOLTABLES.getTop() == 0)
                    {
                        GlobalVarCode(*$2);
                        //JavaCode << "\t\tputstatic int " << className << "." << *$2 << endl;
                    }
                    else
                    {
                        PushCode(0);
                        Id->stackID = varStackID;
                        StoreCode(varStackID++);
                    }

                }

//
// ===========================
// =========== END ===========
// ===========================
//

//
// ==========================
// ======== Functions =======
// ========================== 
//
FUNCTIONS   :   DEF ID
            {        
                Trace("DEF ID");
                if(SYMBOLTABLES.insertTABLE(new IDContent(*$2,FUNC_TYPE)))
                {
                    SYMBOLTABLES.pushTABLE();
                }
                else
                {
                    yyerror("Function ID Error, already exist",*$2);
                }
                returnFlag = false;
                varStackID = 0;
            }
            '(' ARGS
            {
                IDContent * Id = SYMBOLTABLES.lookupTABLE(*$2);
                Id->setArgs(*$5);
                Id->setFuncTable(SYMBOLTABLES.getTopTable());
            }
            ')' FUNCTION_RETURN_TYPE 
            {
                IDContent * Id = SYMBOLTABLES.lookupTABLE(*$2);
                Id->setReturnType($8);

                if (*$2 == "main")
                {
                    cout << "has a main ! \n";
                    isHasMain = true;

                    JavaCode << "\tmethod public static void main(java.lang.String[])" << endl;
                    JavaCode << "\tmax_stack 15" << endl << "\tmax_locals 15" << endl;
                    JavaCode << "\t{" << endl;
                    
                }
                else
                {
                    // Func no return
                    if(Id->getReturnType() == NIL_TYPE)
                    {
                        JavaCode << "\tmethod public static void " << *$2;
                    }
                    else
                    {
                        // func return something
                        JavaCode << "\tmethod public static " << getIdDataTypeCode($8) << " " << *$2;
                    }
                    if($5->size() == 0){
                        JavaCode << "()" << endl;
                    }
                    else
                    {
                        JavaCode << "(";
                        int count = $5->size()-1;
                        for(int i = count;i >= 0 ;i--)
                        {
                            if(i == count){
                                JavaCode << getIdDataTypeCode((*$5)[i]->getDataType());
                            }
                            else{
                                JavaCode << "," <<  getIdDataTypeCode((*$5)[i]->getDataType());
                            }
                        }
                        JavaCode << ")" << endl;
                    }
                    JavaCode << "\tmax_stack 15" << endl << "\tmax_locals 15" << endl; 
                    JavaCode << "\t{" << endl;
                }

            }
            FUNCTION_SCOPE
            {
                
                SYMBOLTABLES.popTABLE();

                if($8 == NIL_TYPE && !returnFlag)
                {
                    JavaCode << "\t\treturn" << endl;
                }
                JavaCode << "\t\treturn" << endl;
                JavaCode << "\t}" << endl;

            };


ARGS :  {
            Trace("NONE ARGS");
            $$ = new vector<IDContent*>();
        }
        | ARG
        {
            Trace("ARG");
            vector<IDContent*> * temp = new vector<IDContent*>();
            temp->push_back($1);
            $$ = temp;
        }
        | ARG ',' ARGS
        {
            Trace("ARG, ");
            $$ = $3;
            $$->push_back($1);
        }
        

ARG : ID ':' TYPE_
    {
        Trace("ID : TYPE");
        if(SYMBOLTABLES.insertTABLE(new IDContent(*$1,VAR_TYPE,$3)))
        {
        }
        else
        {
            yyerror("Function ARG ID Error, already exist",*$1);
        }
        $$ = new IDContent(*$1,VAR_TYPE,$3);
        IDContent * temp = SYMBOLTABLES.lookupTABLE(*$1);
        temp->stackID = varStackID++;
    }
// Functions Type
FUNCTION_RETURN_TYPE    :   ':' TYPE_
                        {
                            // return diff type
                            $$ = $2;
                        }
                        |
                        {
                            // no type define
                            $$ = NIL_TYPE;
                        };

FUNCTION_SCOPE  :   '{'
                {
                    Trace("FUNCTION SCOPE {");
                    SYMBOLTABLES.pushTABLE();
                    cout << "~~~~~~~~~~~~~HERE!!!!!!!!!!!!!!\n";
                } 
                STATEMENTS FUNCTION_RETURN '}'
                {
                    Trace("FUNCTION SCOPE }");
                    $$ = new map<string,IDContent*>();
                    // save a func id table because function call need
                    *$$ = SYMBOLTABLES.getTopTable();
                    //SYMBOLTABLES.dumpTABLE();
                    SYMBOLTABLES.popTABLE();
                }
FUNCTION_RETURN     :   RETURN  EXPRESSION
                    {
                        Trace("FUNCTION RETURN EXPRESSION");
                        $$ = $2;
                    }
                    |   RETURN
                    {
                        Trace("FUNCTION RETURN");
                        $$ = new DataValue();
                    }
                    |
                    {
                        Trace("FUNCTION NONE RETURN");
                        $$ = new DataValue();
                    }

//
// ===========================
// =========== END ===========
// ===========================
//

//
// ===========================
// ======== Statement ========
// ===========================
//
STATEMENTS  :   STATEMENT
            |   STATEMENT STATEMENTS
            |
            ;

STATEMENT   :   SIMPLE_STATEMENT
            |   BLOCK   // {}
            |   CONDITION_STAMENT   // if else 
            |   LOOP_STAMENT    // for while
            |   FUNCTION_CALL   // call some functs
            
SIMPLE_STATEMENT    :   VARIABLES
                    |   ID ASSIGN EXPRESSION    // ID = exprssion
                    {
                        Trace("ID = EXPRESSION");
                        IDContent * temp = SYMBOLTABLES.lookupTABLE(*$1);
                        if(temp == NULL)
                            yyerror("ID Error, Not exist in the scope",*$1);
                        if(temp->getDeclareType() != VAR_TYPE)
                            yyerror("Type Error, Not allow to assign");
                        
                        if(temp->getData()->isHasValue)
                        {
                            cout << "Fuck at : " << getIdDataTypeStr(temp->getDataType()) << endl;
                            if(temp->getDataType() != $3->getDataType())
                            {
                                cout << "Bad assignment : " << *$1 << endl;
                                yyerror("Assign diff Type(etc... assign bool to int)",getIdDataTypeStr($3->getDataType()));
                            }
                            else
                            {
                                temp->setData($3);
                            }
                        }
                        else
                        {
                            temp->setData($3);
                            temp->getData()->isHasValue = true;
                            
                        }

                        if(temp->stackID == -1)
                        {
                            JavaCode << "\t\tputstatic int " << className << "." << *$1 << endl;
                        }
                        else
                        {
                            JavaCode << "\t\tistore " << (temp->stackID) << endl;
                        }


                    }
                    |   ID '[' EXPRESSION ']' ASSIGN EXPRESSION
                    {
                        Trace("ID [ EXPRESSION ] = EXPRESSION");
                        if($3->getDataType() != INT_TYPE)
                            yyerror("Array index must be Integer");
                        IDContent * temp = SYMBOLTABLES.lookupTABLE(*$1);
                        if(temp == NULL)
                            yyerror("ID Error, Not exist in the scope",*$1);
                        if(temp->getDeclareType() != ARRAY_TYPE)
                            yyerror("This ID is not Array Type",*$1);
                        temp->setArrayData($3->getInt(),$6);
                    }
                    |   PRINT 
                    {
                        PrintCode();
                    }
                        EXPRESSION
                    {
                        
                        Trace("PRINT EXPRESSION");
                        if($3->getDataType() == BOOL_TYPE)
                        {
                            JavaCode << "\t\tinvokevirtual void java.io.PrintStream.print(boolean)" << endl;
                        }else
                        {
                            JavaCode << "\t\tinvokevirtual void java.io.PrintStream.print(" << getIdDataTypeCode( $3->getDataType() ) << ")" << endl;
                        }
                    }
                    |   PRINTLN 
                    {
                        PrintCode();
                    }   EXPRESSION
                    {
                        Trace("PRINTLN EXPRESSION");
                        if($3->getDataType() == BOOL_TYPE)
                        {
                            JavaCode << "\t\tinvokevirtual void java.io.PrintStream.println(boolean)" << endl;
                        }else
                        {
                            JavaCode << "\t\tinvokevirtual void java.io.PrintStream.println(" << getIdDataTypeCode( $3->getDataType() ) << ")" << endl;
                        }
                        
                    }
                    |   READ ID
                    {
                        Trace("READ ID");
                        IDContent * temp = SYMBOLTABLES.lookupTABLE(*$2);
                        if(temp == NULL)
                            yyerror("ID Error, Not exist in the scope",*$2);
                    }
                    |   RETURN
                    {
                        returnFlag = true;
                        JavaCode << "\t\treturn" << endl;
                    }
                    |   EXPRESSION
                    |   RETURN EXPRESSION
                    {
                        returnFlag = true;
                        JavaCode << "\t\tireturn" << endl;
                    }
                    ;

BLOCK   :   '{'
        {
            Trace("BLOCK {");
            SYMBOLTABLES.pushTABLE();
        }   
        STATEMENTS  '}'
        {
            $$ = new map<string,IDContent*>();
            *$$ = SYMBOLTABLES.getTopTable();
            Trace("BLOCK }");
            //SYMBOLTABLES.dumpTABLE();
            if(! SYMBOLTABLES.popTABLE())
            {
                cout << "DEBUG : vec is empty, can not pop" << endl;
            }
        }
// // Conditional Staments
// // if ()
// // eles
CONDITION_STAMENT   :   IF_STAMENT

IF_STAMENT  :/*   IF '(' EXPRESSION ')'
            {
                if($3->getDataType() != BOOL_TYPE)
                        yyerror("if ( must be boolean )");

                Trace("IF ( EXPRESSION )");
                SYMBOLTABLES.pushTABLE();
            } 
            SIMPLE_STATEMENT
            {
                //SYMBOLTABLES.dumpTABLE();
                SYMBOLTABLES.popTABLE();
            }
            |   
            IF '(' EXPRESSION ')' BLOCK
            {
                if($3->getDataType() != BOOL_TYPE)
                        yyerror("if ( must be boolean )");
            }
            |
            */
            IF '(' EXPRESSION ')' IF_SCOPE BLOCK_OR_SIMPLE
            {
                if($3->getDataType() != BOOL_TYPE)
                        yyerror("if ( must be boolean )");

                vector<int> temp = IfJumpPoints[IfJumpPoints.size()-1];
                int temp2 = temp[temp.size()-1];
                temp.pop_back();
                IfJumpPoints[IfJumpPoints.size()-1] = temp;
                JavaCode << "\tL" << temp2 <<  ":" << endl;


            }
            ELSE_STAMENT
            |
            IF '(' EXPRESSION ')' IF_SCOPE BLOCK_OR_SIMPLE {
            if($3->getDataType() != BOOL_TYPE)
                        yyerror("if ( must be boolean )");

            if($6)
            {
                SYMBOLTABLES.popTABLE();
            }
            vector<int> temp = IfJumpPoints[IfJumpPoints.size()-1];



            if (temp.size() == 2){
                JavaCode << "\tL" << temp[temp.size()-1] << ":" << endl;
                JavaCode << "\t\tgoto L" << temp[0] << endl;
            }
            int l = temp[0];
            JavaCode << "\tL" << l <<  ":" << endl;
            IfJumpPoints.pop_back();
        }


IF_SCOPE    :   
            {
                if(!IsElseIf)
                {
                    cout << "LabelNum : " << JumpCount << endl;
                    vector<int> temp;
                    IfJumpPoints.push_back(temp); 
                    IfJumpPoints[IfJumpPoints.size()-1].push_back(JumpCount++);
                    IfJumpPoints[IfJumpPoints.size()-1].push_back(JumpCount++);
                    cout << "Debug Start ----------------\n";
                    for(int i=0;i<IfJumpPoints.size();i++)
                    {
                        cout << "[" << i << "] : " << IfJumpPoints[i][IfJumpPoints[i].size()-1] << endl;
                    }
                    cout << "Debug End ----------------\n";
                }
                else
                {
                    IfJumpPoints[IfJumpPoints.size()-1].push_back(JumpCount++);
                }
                vector<int> temp = IfJumpPoints[IfJumpPoints.size()-1];
                JavaCode << "\t\tifeq L" << temp[temp.size()-1] << endl;
                IsElseIf = false;
            }
            
PUSH_TABLE  :   
            {
                SYMBOLTABLES.pushTABLE();
            }
BLOCK_OR_SIMPLE :   
                BLOCK
                {
                    $$ = false;
                    JavaCode << "\t\tgoto L" << IfJumpPoints[IfJumpPoints.size()-1][0] << endl;
                }
                |
                PUSH_TABLE SIMPLE_STATEMENT
                {
                    $$ = true;
                    JavaCode << "\t\tgoto L" << IfJumpPoints[IfJumpPoints.size()-1][0] << endl;
                }

WHILE_BLOCK_OR_SIMPLE:
                    BLOCK
                    {
                        $$ = false;
                        JavaCode << "\t\tgoto Lbegin" << WhileJumpPoints[WhileJumpPoints.size()-1][0]  << endl;
                    }
                    |
                    PUSH_TABLE SIMPLE_STATEMENT
                    {
                        $$ = true;
                        JavaCode << "\t\tgoto Lbegin" << WhileJumpPoints[WhileJumpPoints.size()-1][0] << endl;
                    }


ELSE_STAMENT    :   ELSE
                {
                    Trace("ELSE");
                    SYMBOLTABLES.pushTABLE();
                    IsElseIf = true;
                }
                /*
                IF_STAMENT  //else if
                |  
                SIMPLE_STATEMENT
                {
                    //SYMBOLTABLES.dumpTABLE();
                    SYMBOLTABLES.popTABLE();
                }*/
                |   ELSE BLOCK_OR_SIMPLE
                {
                    if($2)
                    {
                        SYMBOLTABLES.pushTABLE();
                    }
                    vector<int> temp = IfJumpPoints[IfJumpPoints.size()-1];
                    JavaCode << "\tL" << temp[0] << ":" << endl; 
                    IfJumpPoints.pop_back();
                }


//
// // Loop Staments
// // while()
// // for()
LOOP_STAMENT    :   WHILE 
                {
                    vector<int> temp;
                    for(int i=0;i<4;i++)
                    {
                        // L begin,true,false,exit
                        temp.push_back(JumpCount++);
                    }
                    WhileJumpPoints.push_back(temp);
                    
                    JavaCode << "\t\tgoto Lbegin" << WhileJumpPoints[WhileJumpPoints.size()-1][0] << endl;
                    JavaCode << "\tLbegin" << WhileJumpPoints[WhileJumpPoints.size()-1][0] << ":" << endl;
                }
                '(' EXPRESSION ')'
                {
                    //SYMBOLTABLES.pushTABLE();
                    JavaCode << "\t\tifeq Lexit" << WhileJumpPoints[WhileJumpPoints.size()-1][3] << endl;
                    JavaCode << "\t\tgoto Ltrue" << WhileJumpPoints[WhileJumpPoints.size()-1][3] << endl;
                    JavaCode << "\tLtrue" << WhileJumpPoints[WhileJumpPoints.size()-1][3] << ":" << endl;
                }
                WHILE_BLOCK_OR_SIMPLE
                {
                    if($4->getDataType() != BOOL_TYPE)
                        yyerror("While( must be boolean )");
                    if($7)
                        SYMBOLTABLES.popTABLE();
                    JavaCode << "\tLexit" << WhileJumpPoints[WhileJumpPoints.size()-1][3] << ":" << endl;
                    WhileJumpPoints.pop_back();
                }
                /*   
                SIMPLE_STATEMENT
                {
                    Trace("WHILE ( EXPRESSION )");
                    //SYMBOLTABLES.dumpTABLE();
                    SYMBOLTABLES.popTABLE();
                    if($3->getDataType() != BOOL_TYPE)
                        yyerror("While( must be boolean )");
                }
                |   WHILE '(' EXPRESSION ')' BLOCK
                {
                    // while(expr){}
                    Trace("WHILE ( EXPRESSION ) { }");
                    if($3->getDataType() != BOOL_TYPE)
                        yyerror("While( must be Boolean )");
                }*/
                |   FOR '(' ID LESSTHEN '-' EXPRESSION TO EXPRESSION ')'
                {
                    SYMBOLTABLES.pushTABLE();
                }   SIMPLE_STATEMENT
                {
                    Trace("FOR ( ID < - EXPRESSION TO EXPRESSION )");
                    //SYMBOLTABLES.dumpTABLE();
                    SYMBOLTABLES.popTABLE();
                    // only accep int
                    if($6->getDataType() == INT_TYPE && $8->getDataType() == INT_TYPE)
                    {

                    }
                    else
                    {
                        yyerror("For( must be Int )");
                    }
                }
                |   FOR '(' ID LESSTHEN '-' EXPRESSION TO EXPRESSION ')' BLOCK
                {
                    Trace("FOR ( ID < - EXPRESSION TO EXPRESSION ) { }");
                    if($6->getDataType() == INT_TYPE && $8->getDataType() == INT_TYPE)
                    {

                    }
                    else
                    {
                        yyerror("For( must be Int )");
                    }
                }


//
// ===========================
// =========== END ===========
// ===========================
//

//
// ===========================
// ======== Func Call ======== Not done yet !!!!
// ===========================
//
FUNCTION_CALL   :   ID '(' COMMA_SEPARATED_EXPRESSION ')'
                {
                    Trace("CALL_FUNCTION");
                    IDContent * temp = SYMBOLTABLES.lookupTABLE(*$1);
                    if(temp == NULL)
                        yyerror("(calling)~~~ID Not Found, This ID is not declare in the scope");
                    if(temp->getDeclareType() != FUNC_TYPE)
                        yyerror("'ID' is not a function",*$1);
                    cout << "Going to call size is : " << $3->size() << endl;
                    // match same args functs
                    if($3->size() == temp->getArgs().size())
                    {
                        cout << "------- Calling Right Functing ------" << endl;
                    }
                    else
                    {
                        yyerror("Function Args Not Match");
                    }
                    for(int i=0;i<temp->getArgs().size();i++)
                    {
                        // check all arg's type
                        if((*$3)[i]->getDataType() != temp->getArgs()[i]->getDataType())
                        {
                            yyerror("Function Args Type Not Match");
                        }
                        else
                        {
                            continue;
                        }
                    }
                    $$ = new DataValue(temp->getReturnType());

                    if(temp->getReturnType() == NIL_TYPE)
                    {
                        JavaCode << "\t\tinvokestatic void " << className << "." << *$1 << "(" ;
                    }
                    else
                    {
                        JavaCode << "\t\tinvokestatic int " << className << "." << *$1 << "(" ;
                    }

                    //JavaCode << "\t\tinvokestatic int " << className << "." << *$1 << "(" ;
                    for(int i=$3->size()-1;i>=0;--i){
                        if(i == $3->size()-1)
                        {
                            JavaCode << getIdDataTypeCode((*$3)[i]->getDataType());
                        }
                        else
                        {
                            JavaCode << "," <<  getIdDataTypeCode((*$3)[i]->getDataType());
                        }
                    }
                    JavaCode << ")" << endl;
                }
COMMA_SEPARATED_EXPRESSION  :   
                            {
                                Trace("FUNCTION ARG");
                                $$ = new vector<DataValue*>();
                            }
                            |   EXPRESSION ',' COMMA_SEPARATED_EXPRESSION
                            {
                                Trace("FUNCTION ARG");
                                $3->push_back($1);
                                $$ = $3;
                            }
                            |   EXPRESSION
                            {
                                Trace("FUNCTION ARGs");
                                $$ = new vector<DataValue*>();
                                $$->push_back($1);
                            }
                            ;
//
// ===========================
// =========== END ===========
// ===========================
//

//
//////////////////////
////  EXPRESSION  ////
//////////////////////
//

EXPRESSION :
    '-' EXPRESSION %prec UMINUS
    {
        // - (unary)
        // only int and float can do this operation
        Trace("- EXPRESSION");
        switch($2->getDataType())
        {
            case INT_TYPE:
                $2->setInt((-1) * $2->getInt());
                $$ = $2;
                break;
            case FLOAT_TYPE:
                $2->setFloat((-1) * $2->getFloat());
                $$ = $2;
                break;
            default:
                yyerror("Type error(- unary), only Int or Float");
        }
        OpCode('n');
    }|
    EXPRESSION '+' EXPRESSION
    {
        // + 
        Trace("EXPRESSION + EXPRESSION");
        DataValue * result = new DataValue();
        if($1->getDataType() == $3->getDataType())
        {
            switch($1->getDataType())
            {
                case INT_TYPE: 
                    result->setType($1->getDataType());
                    result->setInt($1->getInt() + $3->getInt());
                    break;
                case FLOAT_TYPE:
                    result->setType($1->getDataType());
                    result->setFloat($1->getFloat() + $3->getFloat());
                    break;
                default:
                    break;
            }
        }
        else
        {
            yyerror("Type error(not equal) while doing Operater + ");
        }
        $$ = result;
        OpCode('+');
    }|
    EXPRESSION '-' EXPRESSION
    {
        // - 
        Trace("EXPRESSION - EXPRESSION");
        DataValue * result = new DataValue();
        if($1->getDataType() == $3->getDataType())
        {
            switch($1->getDataType())
            {
                case INT_TYPE: 
                    result->setType($1->getDataType());
                    result->setInt($1->getInt() - $3->getInt());
                    break;
                case FLOAT_TYPE:
                    result->setType($1->getDataType());
                    result->setFloat($1->getFloat() - $3->getFloat());
                    break;
                default:
                    break;
            }
        }
        else
        {
            yyerror("Type error(not equal) while doing Operater - ");
        }
        $$ = result;
        OpCode('-');
    }|
    EXPRESSION '*' EXPRESSION
    {
        // * 
        Trace("EXPRESSION * EXPRESSION");
        DataValue * result = new DataValue();
        if($1->getDataType() == $3->getDataType())
        {
            switch($1->getDataType())
            {
                case INT_TYPE: 
                    result->setType($1->getDataType());
                    result->setInt($1->getInt() * $3->getInt());
                    break;
                case FLOAT_TYPE:
                    result->setType($1->getDataType());
                    result->setFloat($1->getFloat() * $3->getFloat());
                    break;
                default:
                    break;
            }
        }
        else
        {
            yyerror("Type error(not equal) while doing Operater * ");
        }
        $$ = result;
        OpCode('*');
    }|
    EXPRESSION '/' EXPRESSION
    {
        // / 
        
        Trace("EXPRESSION / EXPRESSION");
        DataValue * result = new DataValue();
        
        if($1->getDataType() == $3->getDataType())
        {
            
            switch($1->getDataType())
            {
                case INT_TYPE: 
                    
                    result->setType($1->getDataType());
                    //int temp  = $1->getInt() ;
                    cout << "Debug : " << result->getDataType() << endl;
                    result->setInt(0);
                    break;
                case FLOAT_TYPE:
                    result->setType($1->getDataType());
                    result->setFloat($1->getFloat() / $3->getFloat());
                    break;
                default:
                    break;
            }
        }
        else
        {
            yyerror("Type error(not equal) while doing Operater / ");
        }
        //cout << "Debug : " << result->getDataType() << endl;
        $$ = result;
        OpCode('/');
    }|
    // Logical Operator
    EXPRESSION LG_AND EXPRESSION
    {
        // &&
        Trace("EXPRESSION && EXPRESSION");
        DataValue * result = new DataValue();
        if($1->getDataType() == BOOL_TYPE && $3->getDataType() == BOOL_TYPE)
        {
            result->setType(BOOL_TYPE);
            result->setBool($1->getBool() && $3->getBool());
        }
        else
        {
            yyerror("Type error(not Boolean) while doing Logical Operation ");
        }
        $$ = result;
        OpCode('&');
    }|
    EXPRESSION LG_OR EXPRESSION
    {
        // ||
        Trace("EXPRESSION || EXPRESSION");
        DataValue * result = new DataValue();
        if($1->getDataType() == BOOL_TYPE && $3->getDataType() == BOOL_TYPE)
        {
            result->setType(BOOL_TYPE);
            result->setBool($1->getBool() || $3->getBool());
        }
        else
        {
            yyerror("Type error(not Boolean) while doing Logical Operation ");
        }
        $$ = result;
        OpCode('|');
    }|
    LG_NOT EXPRESSION
    {
        // !
        Trace("! EXPRESSION");
        DataValue * result = new DataValue();
        if($2->getDataType() == BOOL_TYPE)
        {
            result->setType(BOOL_TYPE);
            result->setBool(!$2->getBool());
        }
        else
        {
            yyerror("Type error(not Boolean) while doing Logical Operation ");
        }
        $$ = $2;
        OpCode('!');
    }|
    EXPRESSION LESSTHEN EXPRESSION
    {
        // <
        Trace("EXPRESSION < EXPRESSION");
        DataValue * result = new DataValue();
        if($1->getDataType() == $3->getDataType())
        {
            result->setType(BOOL_TYPE);
            switch($1->getDataType())
            {
                case INT_TYPE: 
                    result->setBool($1->getInt() < $3->getInt());
                    break;
                case FLOAT_TYPE:
                    result->setBool($1->getFloat() < $3->getFloat());            
                    break;
                default:
                    break;
            }
        }
        else
        {
            yyerror("Type error(only int, float) while doing '<' ");
        }
        $$ = result;
        LogicOpCode(0);
    }|
    EXPRESSION LESSEQUAL EXPRESSION
    {
        // <=
        Trace("EXPRESSION <= EXPRESSION");
        DataValue * result = new DataValue();
        if($1->getDataType() == $3->getDataType())
        {
            result->setType(BOOL_TYPE);
            switch($1->getDataType())
            {
                case INT_TYPE: 
                    result->setBool($1->getInt() <= $3->getInt());
                    break;
                case FLOAT_TYPE:
                    result->setBool($1->getFloat() <= $3->getFloat());            
                    break;
                default:
                    break;
            }
        }
        else
        {
            yyerror("Type error(only int, float) while doing '<=' ");
        }
        $$ = result;
        LogicOpCode(1);
    }|
    EXPRESSION MORETHEN EXPRESSION
    {
        // >
        Trace("EXPRESSION > EXPRESSION");
        DataValue * result = new DataValue();
        if($1->getDataType() == $3->getDataType())
        {
            result->setType(BOOL_TYPE);
            switch($1->getDataType())
            {
                
                case INT_TYPE: 
                    result->setBool($1->getInt() > $3->getInt());
                    break;
                case FLOAT_TYPE:
                    result->setBool($1->getFloat() > $3->getFloat());            
                    break;
                default:
                    break;
            }
        }
        else
        {
            yyerror("Type error(only int, float) while doing '>' ");
        }
        $$ = result;
        LogicOpCode(3);
    }|
    EXPRESSION MOREEQUAL EXPRESSION
    {
        // >=
        Trace("EXPRESSION >= EXPRESSION");
        DataValue * result = new DataValue();
        if($1->getDataType() == $3->getDataType())
        {
            result->setType(BOOL_TYPE);
            switch($1->getDataType())
            {
                
                case INT_TYPE: 
                    result->setBool($1->getInt() >= $3->getInt());
                    break;
                case FLOAT_TYPE:
                    result->setBool($1->getFloat() >= $3->getFloat());            
                    break;
                default:
                    break;
            }
        }
        else
        {
            yyerror("Type error(only int, float) while doing '>=' ");
        }
        $$ = result;
        LogicOpCode(4);
    }|
    EXPRESSION EQUAL EXPRESSION
    {
        // ==
        Trace("EXPRESSION == EXPRESSION");
        DataValue * result = new DataValue();
        if($1->getDataType() == $3->getDataType())
        {
            result->setType(BOOL_TYPE);
            switch($1->getDataType())
            {
                
                case INT_TYPE: 
                    result->setBool($1->getInt() == $3->getInt());
                    break;
                case FLOAT_TYPE:
                    result->setBool($1->getFloat() == $3->getFloat());            
                    break;
                case BOOL_TYPE:
                    result->setBool($1->getBool() == $3->getBool());
                    break;
                default:
                    break;
            }
        }
        else
        {
            yyerror("Type error(not equal) while doing '==' ");
        }
        $$ = result;
        LogicOpCode(2);
    }|
    EXPRESSION NOTEQUAL EXPRESSION
    {
        // !=
        Trace("EXPRESSION != EXPRESSION");
        DataValue * result = new DataValue();
        if($1->getDataType() == $3->getDataType())
        {
            result->setType(BOOL_TYPE);
            switch($1->getDataType())
            {
                
                case INT_TYPE: 
                    result->setBool($1->getInt() != $3->getInt());
                    break;
                case FLOAT_TYPE:
                    result->setBool($1->getFloat() != $3->getFloat());            
                    break;
                case BOOL_TYPE:
                    result->setBool($1->getBool() != $3->getBool());
                    break;
                default:
                    break;
            }
        }
        else
        {
            yyerror("Type error(not equal) while doing '<' ");
        }
        $$ = result;
        LogicOpCode(5);
    }|
    FUNCTION_CALL
    |
    ID
    {
        // ID
        Trace("EXPR_ID");
        IDContent * temp = SYMBOLTABLES.lookupTABLE(*$1);
        if(temp == NULL)
            yyerror("ID Not Found, This ID is not declare in the scope",*$1);
        if(temp->getDeclareType() == ARRAY_TYPE)
            yyerror("ID Type Error(is a array type)");
        // Find this ID and return as DataValue * type
        $$ = temp->getData();
        // Java
        DataValue * data = temp->getData();
        int value;
        if(temp->getDeclareType() == CONST_TYPE)
        {
            //cout << "_______Here!!!!!!!!!!!!!!!!!!!!!!\n";
            if(data->getDataType() == INT_TYPE)
            {
                PushCode(data->getInt());
            }
            else if(data->getDataType() == BOOL_TYPE)
            {
                if(data->getBool())
                {
                    PushCode(1);   //true
                }
                else
                {
                    PushCode(0);    //false
                }
            }
            else //string
            {
                JavaCode << "\t\tldc " <<  "\"" << *(data->getStr()) << "\"" << endl;
            }
        }
        else
        {
            //cout << "Here!!!!!!!!!!!!!!!!!!!!!!\n";
            if(temp->stackID == -1)
            {
                JavaCode << "\t\tgetstatic int " << className << "." << *$1 << endl;
            }
            else
            {
                LoadCode(temp->stackID);
            }
        }

    }|
    ID '[' EXPRESSION ']' 
    {
        // A [ integer expression ]
        Trace("ID [ EXPRESSION ]");
        if($3->getDataType() != INT_TYPE)
            yyerror("Type Error (Index must be integer)");
        // Check if This ID is in scope
        IDContent * temp = SYMBOLTABLES.lookupTABLE(*$1);
        if(temp == NULL)
            yyerror("Array Error, This Array ID is not find in the scope",*$1);
        else if(temp->getDeclareType() != ARRAY_TYPE)
            yyerror("Type Error, This ID is not declare as Array");
        else if($3->getInt() < 0 || $3->getInt() > temp->getArrayLen())
            yyerror("Array Error, Index Out of the Range");
        else
        {
            $$ = temp->getArrayByIndex($3->getInt());
        }

    }|
    '(' EXPRESSION ')'
    {
        $$ = $2;
        Trace("( EXPRESSION )");
    }|
    DATA_VALUE
    {
        Trace("DATA_VALUE");
        $$ = $1;
    }


// Type Check
TYPE_   :   INT
        {
            $$ = INT_TYPE;
        }
        |   BOOLEAN
        {
            $$ = BOOL_TYPE;
        }
        |   CHAR
        {
            $$ = CHAR_TYPE;
        }
        |   STRING
        {
            $$ = STR_TYPE;
        }
        |   FLOAT
        {
            $$ = FLOAT_TYPE;
        }
        
//
DATA_VALUE  :  INT_VALUE
            {
                Trace("INT VALUE");
                $$ = new DataValue($1);
                PushCode($1);
            }
            |   BOOL_VALUE
            {
                Trace("BOOL VALUE");
                $$ = new DataValue($1);
                if($1)
                {
                    PushCode(1);
                }
                else
                {
                    PushCode(0);
                }
                
            }
            |   CHAR_VALUE
            {
                Trace("CHAR VALUE");
                $$ = new DataValue($1);
            }
            |   STRING_VALUE
            {
                Trace("STRING VALUE");
                $$ = new DataValue($1);
                JavaCode << "\t\tldc "  << "\"" << *$1 << "\"" << endl;
            }
            |   FLOAT_VALUE
            {
                Trace("FLOAT VALUE");
                $$ = new DataValue($1);
            }
            ;
//

%%

int main(int argc,char ** argv)
{
    ++argv, --argc; 
    string filename;
	if ( argc > 0 )
    {
	    yyin = fopen( argv[0], "r" );
        filename = string(argv[0]);
        filename = filename +  ".jasm";
        JavaCode.open(filename,ios::out);
    }
	else
    {
	    yyin = stdin;
        JavaCode.open("JaveByteCode.jasm",ios::out);
    }

    if(!JavaCode){
        cout << "Can't build JavaByteCode file !\n";
        exit(1);
    }

	if(!yyin){
		printf("Load File Failed\n");
		return -1;
	} 

    if (yyparse() == 1)                
            yyerror("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Parsing error!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! !");
    else
    {
        printf("\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~Parsing Success~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
        printf("\n");
        if(isHasMain)
        {
            SYMBOLTABLES.dumpTABLE();
            cout << "JaveByteCode File : " << filename << "has been built\n";
        }
        else
        {
            cout << "No main() exist !\n";
        }
    }  
    
}