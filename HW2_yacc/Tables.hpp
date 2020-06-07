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

using namespace std;

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
    bool isHasValue;

public:
    // Constructor
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

struct Args
{
    string _Idname;
    ID_DATA_TYPE _Type;
};

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
        IdName = name;
        DeclareType = type;
        DataType = NIL_TYPE;
    }
    IDContent(string name, ID_DECLARE_TYPE type, DataValue *data)
    {
        IdName = name;
        DeclareType = type;
        Data = data;
        DataType = data->getDataType();
    }
    IDContent(string name, ID_DECLARE_TYPE type, ID_DATA_TYPE datatype)
    {
        IdName = name;
        DeclareType = type;
        DataType = datatype;
        Data = new DataValue(datatype);
    }
    IDContent(string name, ID_DECLARE_TYPE type, ID_DATA_TYPE datatype, int arraylen)
    {
        // Array
        cout << "Debug : " << type << endl;
        IdName = name;
        DeclareType = type;
        DataType = datatype;
        ArrayLen = arraylen;
        Data = NULL;
        for (int i = 0; i < arraylen; i++)
        {
            ArrayData.push_back(new DataValue(datatype));
        }
    }
    IDContent(ID_DATA_TYPE datatype)
    {
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
};

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
            cout << "[ " << i << " ] Table: " << endl;
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
};
