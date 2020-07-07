#include <vector>
#include <string>
#include <map>
#include <stdio.h>
#include <memory.h>
#include <limits.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <utility>
#include <string>
#include <fstream>

using namespace std;

extern fstream JavaCode;
extern int JumpCount;

// Enum
enum ID_DECLARE_TYPE
{
    CONST_TYPE,
    VAR_TYPE,
    FUNC_TYPE,
    ARRAY_TYPE,
    OBJECT_TYPE,
};
string getIdDeclareTypeStr(ID_DECLARE_TYPE idtype)
{
    switch (idtype)
    {
    case CONST_TYPE:
        return "Constant";
        break;
    case VAR_TYPE:
        return "Variable";
        break;
    case FUNC_TYPE:
        return "Function";
        break;
    case ARRAY_TYPE:
        return "Array";
        break;
    case OBJECT_TYPE:
        return "Object";
        break;
    }
}
// Type to String func
enum ID_DATA_TYPE
{
    INT_TYPE,
    BOOL_TYPE,
    CHAR_TYPE,
    STR_TYPE,
    FLOAT_TYPE,
    NIL_TYPE,
};
string getIdDataTypeStr(ID_DATA_TYPE idtype)
{
    switch (idtype)
    {
    case (INT_TYPE):
        return "Integer";
        break;
    case (BOOL_TYPE):
        return "Boolean";
        break;
    case (CHAR_TYPE):
        return "Char";
        break;
    case (STR_TYPE):
        return "String";
        break;
    case (FLOAT_TYPE):
        return "Float";
        break;
    case (NIL_TYPE):
        return "Nil";
        break;
    }
}
string getIdDataTypeCode(ID_DATA_TYPE idtype)
{
    switch (idtype)
    {
    case (INT_TYPE):
        return "int";
        break;
    case (BOOL_TYPE):
        return "int"; // boolean
        break;
    case (CHAR_TYPE):
        return "char";
        break;
    case (STR_TYPE):
        return "java.lang.String";
        break;
    case (FLOAT_TYPE):
        return "float";
        break;
    case (NIL_TYPE):
        return "unknown";
        break;
    }
}
// Basic value class
// this class is the content of each id content
class DataValue
{
private:
    union {
        int intVal;
        float floatVal;
        bool boolVal;
        char charVal;
        string *strVal;
    };
    ID_DATA_TYPE DataType;

public:
    // Constructor
    bool isHasValue;
    DataValue() { isHasValue = false; }
    DataValue(ID_DATA_TYPE Type)
    {
        DataType = Type;
        isHasValue = false;
    }
    DataValue(int i)
    {
        DataType = INT_TYPE;
        setInt(i);
    }
    DataValue(float f)
    {
        DataType = FLOAT_TYPE;
        setFloat(f);
    }
    DataValue(bool b)
    {
        DataType = BOOL_TYPE;
        setBool(b);
    }
    DataValue(char c)
    {
        DataType = CHAR_TYPE;
        setChar(c);
    }
    DataValue(string *s)
    {
        DataType = STR_TYPE;
        setStr(s);
    }
    ///////////////////////
    // Set, Get function //
    ///////////////////////
    ID_DATA_TYPE getDataType()
    {
        return DataType;
    }
    // Data is a int
    void setInt(int i)
    {
        intVal = i;
        isHasValue = true;
    }
    // Data is a float
    void setFloat(float f)
    {
        floatVal = f;
        isHasValue = true;
    }
    // Data is a boolean
    void setBool(bool b)
    {
        boolVal = b;
        isHasValue = true;
    }
    // Data is a char
    void setChar(char c)
    {
        charVal = c;
        isHasValue = true;
    }
    // Data is a string
    void setStr(string *s)
    {
        strVal = s;
        isHasValue = true;
    }
    // setType
    void setType(ID_DATA_TYPE t)
    {
        DataType = t;
    }
    // get
    int getInt()
    {
        return intVal;
    }
    // get
    float getFloat()
    {
        return floatVal;
    }
    // get
    int getChar()
    {
        return charVal;
    }
    // get
    bool getBool()
    {
        return boolVal;
    }
    // get
    string *getStr()
    {
        return strVal;
    }
};

// functions Args
struct Args
{
    string _Idname;
    ID_DATA_TYPE _Type;
};

// Id's infomation
class IDContent
{
private:
    string IdName;
    ID_DECLARE_TYPE DeclareType;
    ID_DATA_TYPE DataType;

    // Simple data
    DataValue *Data;
    // Array data
    int ArrayLen;
    vector<DataValue *> ArrayData;
    // Function data
    ID_DATA_TYPE ReturnType;
    vector<IDContent *> FuncArgs;
    map<string, IDContent *> FuncTable;

public:
    IDContent() {}
    IDContent(string name, ID_DECLARE_TYPE type)
    {
        stackID = -1;
        IdName = name;
        DeclareType = type;
        DataType = NIL_TYPE;
        cout << "ID < " << name << " > with Declaration : " << getIdDeclareTypeStr(type) << " , DataType : NIL_TYPE " << endl;
    }
    IDContent(string name, ID_DECLARE_TYPE type, DataValue *data)
    {
        stackID = -1;
        IdName = name;
        DeclareType = type;
        Data = data;
        DataType = data->getDataType();
        cout << "ID < " << name << " > with Declaration : " << getIdDeclareTypeStr(type) << " , DataType : " << endl;
    }
    IDContent(string name, ID_DECLARE_TYPE type, ID_DATA_TYPE datatype)
    {
        stackID = -1;
        IdName = name;
        DeclareType = type;
        DataType = datatype;
        Data = new DataValue(datatype);
        cout << "ID < " << name << " > with Declaration : " << getIdDeclareTypeStr(type) << " , DataType : " << getIdDataTypeStr(datatype) << endl;
    }
    IDContent(string name, ID_DECLARE_TYPE type, ID_DATA_TYPE datatype, int arraylen)
    {
        // Array
        // : " << type << endl;
        stackID = -1;
        IdName = name;
        DeclareType = type;
        DataType = datatype;
        ArrayLen = arraylen;
        Data = NULL;
        for (int i = 0; i < arraylen; i++)
        {
            ArrayData.push_back(new DataValue(datatype));
        }
        cout << "ID < " << name << " > with Declaration : " << getIdDeclareTypeStr(type) << " , DataType : " << getIdDataTypeStr(datatype) << endl;
    }
    IDContent(ID_DATA_TYPE datatype)
    {
        stackID = -1;
        DataType = datatype;
        Data = new DataValue(datatype);
    }
    string getIdName()
    {
        return IdName;
    }
    ID_DECLARE_TYPE getDeclareType()
    {
        return DeclareType;
    }
    ID_DATA_TYPE getDataType()
    {
        return DataType;
    }
    string getInfo()
    {
        string temp = "";
        temp = temp + "ID : " + IdName + ", Declaration: " + getIdDeclareTypeStr(DeclareType) + ", Data type: " + getIdDataTypeStr(DataType);
        temp += "\n";
        return temp;
    }
    // Simple Data
    DataValue *getData()
    {
        return Data;
    }
    void setData(DataValue *data)
    {
        Data = data;
        Data->setType(data->getDataType());
        DataType = data->getDataType();
    }
    // Array methods
    int getArrayLen()
    {
        return ArrayLen;
    }
    void setArrayData(int index, DataValue *data)
    {
        ArrayData[index] = data;
    }
    DataValue *getArrayByIndex(int index)
    {
        if (index >= 0 && index <= ArrayLen)
            return ArrayData[index];
        else
            return NULL;
    }
    // Function
    void setReturnType(ID_DATA_TYPE type_)
    {
        ReturnType = type_;
    }
    ID_DATA_TYPE getReturnType()
    {
        return ReturnType;
    }
    void setArgs(vector<IDContent *> args)
    {
        FuncArgs = args;
    }
    vector<IDContent *> getArgs()
    {
        return FuncArgs;
    }
    void setFuncTable(map<string, IDContent *> table)
    {
        FuncTable = table;
    }
    map<string, IDContent *> getFuncTable()
    {
        return FuncTable;
    }
    int stackID = -1;
};

// Atom of GlobalTABLE
class SymbolTABLE
{
private:
    map<string, IDContent *> TABLE;

public:
    bool insertTABLE(IDContent *Id)
    {
        if (TABLE.find(Id->getIdName()) != TABLE.end())
            return false;
        else
        {
            TABLE[Id->getIdName()] = Id;
            return true;
        }
    }
    void dumpTABLE()
    {
        for (auto it : TABLE)
            cout << it.second->getInfo() << endl;
    }
    IDContent *lookupTABLE(string idname)
    {
        if (TABLE.find(idname) != TABLE.end())
        {
            return TABLE[idname];
        }
        else
        {
            return NULL;
        }
    }
    map<string, IDContent *> getSymbolTable()
    {
        return TABLE;
    }
};

// all the Symbol tables in here
class GlobalTABLE
{
private:
    vector<SymbolTABLE> glTABLES;
    int top;

public:
    GlobalTABLE()
    {
        top = -1;
        pushTABLE();
    }
    bool popTABLE()
    {
        if (glTABLES.empty())
            return false;
        glTABLES.pop_back();
        --top;
        return true;
    }
    void pushTABLE()
    {
        glTABLES.push_back(SymbolTABLE());
        ++top;
    }
    bool insertTABLE(IDContent *Id)
    {
        return glTABLES[top].insertTABLE(Id);
    }
    void dumpTABLE()
    {
        cout << endl;
        cout << "========================================" << endl;
        cout << "===== Dumping Global Symbol Tables =====" << endl;
        cout << "========================================" << endl;
        cout << "================= Dump =================" << endl;
        cout << "========================================" << endl;
        cout << endl;
        for (int i = top; i >= 0; --i)
        {
            //cout << "[ " << i << " ] Table: " << endl;
            glTABLES[i].dumpTABLE();
        }
        cout << "========================================" << endl;
        cout << "=============== End Dump ===============" << endl;
        cout << "========================================" << endl;
    }
    IDContent *lookupTABLE(string Idname)
    {
        for (int i = top; i >= 0; i--)
        {
            IDContent *result = glTABLES[i].lookupTABLE(Idname);
            if (result != NULL)
                return result;
        }
    }
    map<string, IDContent *> getTopTable()
    {
        return glTABLES[top].getSymbolTable();
    }
    int getTop()
    {
        return top;
    }
};

// JavaCode gen
void GlobalVarCode(string id)
{
    JavaCode << "\tfield static int " << id << endl;
}
void GlobalVarCode(string id, int integer)
{
    JavaCode << "\tfield static int " << id << " = " << integer << endl;
}
void PushCode(int integer)
{
    JavaCode << "\t\tldc " << integer << endl;
}
void StoreCode(int index)
{
    JavaCode << "\t\tistore " << index << endl;
}
void PrintCode()
{
    JavaCode << "\t\tgetstatic java.io.PrintStream java.lang.System.out" << endl;
}
void LoadCode(int index)
{
    JavaCode << "\t\tiload " << index << endl;
}
void OpCode(char op)
{
    switch (op)
    {
    case 'n':
        JavaCode << "\t\tineg" << endl;
        break;
    case '+':
        JavaCode << "\t\tiadd" << endl;
        break;
    case '-':
        JavaCode << "\t\tisub" << endl;
        break;
    case '*':
        JavaCode << "\t\timul" << endl;
        break;
    case '/':
        JavaCode << "\t\tidiv" << endl;
        break;
    case '!':
        JavaCode << "\t\tldc 1" << endl
                 << "\t\tixor" << endl;
        break;
    case '&':
        JavaCode << "\t\tiand" << endl;
        break;
    case '|':
        JavaCode << "\t\tior" << endl;
        break;
    }
}

void LogicOpCode(int op)
{

    JavaCode << "\t\tisub" << endl;
    switch (op)
    {
    case 0:
        JavaCode << "\t\tiflt"; // <
        break;
    case 1:
        JavaCode << "\t\tifle"; // <=
        break;
    case 2:
        JavaCode << "\t\tifeq"; //==
        break;
    case 3:
        JavaCode << "\t\tifgt"; //>
        break;
    case 4:
        JavaCode << "\t\tifge"; //>=
        break;
    case 5:
        JavaCode << "\t\tifne"; //!=
        break;
    }

    int jump1 = JumpCount++;
    int jump2 = JumpCount++;

    JavaCode << " L" << jump1 << endl;
    JavaCode << "\t\ticonst_0" << endl;
    JavaCode << "\t\tgoto L" << jump2 << endl;
    JavaCode << "\tL"
             << jump1
             << ":" << endl;
    JavaCode << "\t\ticonst_1" << endl;
    JavaCode << "\t\tgoto L" << jump2 << endl;
    JavaCode << "\tL"
             << jump2
             << ":" << endl;
}