#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

SymbolTable *MAP;

SymbolTable *Create()
{
    SymbolTable *temp = malloc(sizeof(SymbolTable));
    temp->items = NULL;
    temp->size = 0;
    return temp;
}
int lookup(char *Key, SymbolTable *Table)
{
    if (Table->size == 0 || Table->items == NULL)
        return 0;
    Item *ptr = Table->items;
    while (ptr != NULL)
    {
        if (strcmp(Key, ptr->Key) == 0)
            return ptr->index;
        else
        {
            ptr = ptr->next;
        }
    }
    return 0;
}
void insert(char *Key, SymbolTable *Table)
{
    if (lookup(Key, Table) > 0)
    {
        Item *ptr = Table->items;
        while (ptr != NULL)
        {
            if (strcmp(Key, ptr->Key) == 0)
                ptr->data += 1;
            else
                ptr = ptr->next;
        }
    }
    else
    {
        Item *newItem = malloc(sizeof(Item));
        Table->size++;
        stpcpy(newItem->Key, Key);
        newItem->data = 1;
        newItem->index = 0;
        Item *ptr = Table->items;
        while (ptr != NULL)
        {
            ptr->index++;
        }
        newItem->next = Table->items;
        Table->items = newItem;
    }
}
void dump(SymbolTable *Table)
{
    printf("Table size : %d\n", Table->size);
    if (Table->size == 0 || Table->items == NULL)
    {
        printf("There is Nothing in Table\n");
        return;
    }
    Item *ptr = malloc(sizeof(Item));
    ptr = Table->items;
    while (ptr->next != NULL)
    {
        printf("%s\n", ptr->Key);
        ptr = ptr->next;
    }
}
int main(int argc, char *argv[])
{
    MAP = Create();
    char *Test = "Test";
    insert(Test, MAP);
    dump(MAP);
    /*
    Node a, b, c;
    Node *ptr = &a; //宣告ptr，並將他只向節點a

    a.data = 12;
    a.next = &b;
    b.data = 30;
    b.next = &c;
    c.data = 64;
    c.next = NULL;

    while (ptr != NULL)
    {
        printf("address=%p, ", ptr);    //印出節點的位址
        printf("data=%d ", ptr->data);  //印出節點的資料
        printf("next=%p\n", ptr->next); //印出下一個節點位址
        ptr = ptr->next;                //將ptr指向下一個節點
    }

    system("PAUSE");
    */
    return 0;
}