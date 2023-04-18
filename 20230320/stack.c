#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int nValue;
    struct node *pNext;
}Data;

typedef struct node2
{
    Data *pTop;
    int nCount;
} Stack;

void Init(Stack **pStack)
{
    *pStack = (Stack *)malloc(sizeof(Stack));
    (*pStack)->nCount = 0;
    (*pStack)->pTop = NULL;
}

void Push(Stack *pStack,int nNum)
{

    
}
