%{
#include <iostream>
#include "Tables.hpp"
#include "lex.yy.cpp"
#define Trace(s)        {cout << "Parser Msg : " << s << endl;}
#define Warning(t)      {printf(t);printf("\n");} 

void yyerror(string error_msg){
    cout << "=============== Error ===============" << endl;
    cout << buf << " ( " <<  error_msg <<  ")" << endl;
    cout << "============ Parser Fail ============" << endl;
   exit(-1);
}void yyerror(string error_msg,string t)
{
    cout << "=============== Error ===============" << endl;
    cout << buf << " ( " <<  error_msg <<  ")" << endl;
    cout << "With bad string : " << t << endl;
    cout << "============ Parser Fail ============" << endl;
   exit(-1);
}
// Create a new global tables
GlobalTABLE SYMBOLTABLES;
bool global_INSERT(IDContent * Id);

%}

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
            
        }
        '{' OBJECT_CONTENTS '}'
        {
            //Trace("");
        }


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

VAL_VARIABLE    :   VAL ID ASSIGN EXPRESSION
                {
                    Trace("VAL ID = EXPRESSION");
                    // Create new const var to gloabl Tables
                    if(SYMBOLTABLES.insertTABLE(new IDContent(*$2,CONST_TYPE,$4)))
                    {

                    }
                    else
                    {
                        yyerror("ID error",*$2);
                    }
                }
                |   VAL ID ':' TYPE_ ASSIGN EXPRESSION
                {
                    Trace("VAL ID : TYPE = EXPRESSION");
                    if($4 != $6->getDataType())
                    {
                        yyerror("Type Error, Not match(assign diff type)");
                    }
                    if(SYMBOLTABLES.insertTABLE(new IDContent(*$2,CONST_TYPE,$6)))
                    {

                    }
                    else
                    {
                        yyerror("ID error",*$2);
                    }
                    
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

                    }
                    else
                    {
                        yyerror("ID Error(VAR ID : TYPE = EXPRESSION)",*$2);
                    }
                }
                |   VAR ID ':' TYPE_
                {
                    Trace("VAR ID : TYPE ");
                    if(SYMBOLTABLES.insertTABLE(new IDContent(*$2,VAR_TYPE,$4)))
                    {
                        cout << "Debug : Insert " << *$2 << " as new ID !!!" << endl;
                    }
                    else
                    {
                        yyerror("ID Error(VAR ID : TYPE )",*$2);
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

            }
            FUNCTION_SCOPE
            {
                SYMBOLTABLES.popTABLE();

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
    }
// Functions Type
FUNCTION_RETURN_TYPE    :   ':' TYPE_
                        {
                            $$ = $2;
                        }
                        |
                        {
                            $$ = NIL_TYPE;
                        };

FUNCTION_SCOPE  :   '{'
                {
                    Trace("FUNCTION SCOPE {");
                    SYMBOLTABLES.pushTABLE();
                } 
                STATEMENTS FUNCTION_RETURN '}'
                {
                    Trace("FUNCTION SCOPE }");
                    $$ = new map<string,IDContent*>();
                    *$$ = SYMBOLTABLES.getTopTable();
                    
                    SYMBOLTABLES.dumpTABLE();
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
            |   BLOCK
            |   CONDITION_STAMENT
            |   LOOP_STAMENT
            |   FUNCTION_CALL
            
SIMPLE_STATEMENT    :   VARIABLES
                    |   ID ASSIGN EXPRESSION
                    {
                        Trace("ID = EXPRESSION");
                        IDContent * temp = SYMBOLTABLES.lookupTABLE(*$1);
                        if(temp == NULL)
                            yyerror("ID Error, Not exist in the scope",*$1);
                        if(temp->getDeclareType() != VAR_TYPE)
                            yyerror("Type Error, Not allow to assign");

                        if(temp->getDataType() != $3->getDataType())
                        {
                            yyerror("Assign diff Type(etc... assign bool to int)");
                        }
                        temp->setData($3);

                    }
                    |   ID '[' EXPRESSION ']' ASSIGN EXPRESSION
                    {
                        Trace("ID [ EXPRESSION ] = EXPRESSION");
                        if($3->getDataType() != INT_TYPE)
                            yyerror("Array index must be Integer");
                        IDContent * temp = SYMBOLTABLES.lookupTABLE(*$1);
                        if(temp == NULL)
                            yyerror("ID Error, Not exist in the scope",*$1);

                        temp->setArrayData($3->getInt(),$6);
                    }
                    |   PRINT EXPRESSION
                    {
                        Trace("PRINT EXPRESSION");
                    }
                    |   PRINTLN EXPRESSION
                    {
                        Trace("PRINTLN EXPRESSION");
                    }
                    |   READ ID
                    {
                        Trace("READ ID");
                        IDContent * temp = SYMBOLTABLES.lookupTABLE(*$2);
                        if(temp == NULL)
                            yyerror("ID Error, Not exist in the scope",*$2);
                    }
                    |   RETURN
                    |   EXPRESSION
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
            SYMBOLTABLES.dumpTABLE();
            if(! SYMBOLTABLES.popTABLE())
            {
                cout << "DEBUG : vec is empty, can not pop" << endl;
            }
        }
// // Conditional Staments
// // if ()
// // eles
CONDITION_STAMENT   :   IF_STAMENT
                    |   IF_STAMENT ELSE_STAMENT
IF_STAMENT  :   IF '(' EXPRESSION ')'
            {
                Trace("IF ( EXPRESSION )");
                SYMBOLTABLES.pushTABLE();
            } 
            SIMPLE_STATEMENT
            {
                SYMBOLTABLES.dumpTABLE();
                SYMBOLTABLES.popTABLE();
            }
            |   IF '(' EXPRESSION ')' BLOCK

ELSE_STAMENT    :   ELSE
                {
                    Trace("ELSE");
                    SYMBOLTABLES.pushTABLE();
                }   
                SIMPLE_STATEMENT
                {
                    SYMBOLTABLES.dumpTABLE();
                    SYMBOLTABLES.popTABLE();
                }
                |   ELSE BLOCK
                |   ELSE IF_STAMENT
                |   ELSE IF_STAMENT ELSE_STAMENT


//
// // Loop Staments
// // while()
// // for()
LOOP_STAMENT    :   WHILE '(' EXPRESSION ')'
                {
                    SYMBOLTABLES.pushTABLE();
                }   
                SIMPLE_STATEMENT
                {
                    Trace("WHILE ( EXPRESSION )");
                    SYMBOLTABLES.dumpTABLE();
                    SYMBOLTABLES.popTABLE();
                    if($3->getDataType() != BOOL_TYPE)
                        yyerror("While( must be boolean )");
                }
                |   WHILE '(' EXPRESSION ')' BLOCK
                {
                    Trace("WHILE ( EXPRESSION ) { }");
                    if($3->getDataType() != BOOL_TYPE)
                        yyerror("While( must be Boolean )");
                }
                |   FOR '(' ID LESSTHEN '-' EXPRESSION TO EXPRESSION ')'
                {
                    SYMBOLTABLES.pushTABLE();
                }   SIMPLE_STATEMENT
                {
                    Trace("FOR ( ID < - EXPRESSION TO EXPRESSION )");
                    SYMBOLTABLES.dumpTABLE();
                    SYMBOLTABLES.popTABLE();
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
                    result->setInt($1->getInt() / $3->getInt());
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
        $$ = result;
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
            }
            |   BOOL_VALUE
            {
                Trace("BOOL VALUE");
                $$ = new DataValue($1);
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

	if ( argc > 0 )
	    yyin = fopen( argv[0], "r" );
	else
	    yyin = stdin;

	if(!yyin){
		printf("Load File Failed\n");
		return -1;
	} 

    if (yyparse() == 1)                
        yyerror("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Parsing error!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! !");  
    printf("\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~Parsing Success~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
    printf("\n");
    //SYMBOLTABLES.dumpTABLE();
}