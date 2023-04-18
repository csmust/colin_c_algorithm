#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct List{
    struct List* next;
    int value;
} List;

typedef struct Queue{
    List *front;
    List *back;
    int count;
} Queue;

void Init(Queue ** pQ){
    *pQ = (Queue *)malloc(sizeof(Queue));
    (*pQ)->count = 0;
    (*pQ)->front = NULL;
    (*pQ)->back = NULL;
}

void Push(Queue *pQueue,int nNum)
{
    if(pQueue==NULL)
        return;
    List *pTemp = NULL;
    pTemp = (List *)malloc(sizeof(List));
    pTemp->next = NULL;
    pTemp->value = nNum;

    //尾增
    if(pQueue->front==NULL){
        pQueue->front = pTemp;
    }
    else{
        pQueue->back->next = pTemp;
    }
    pQueue->back = pTemp;//更改队尾
    pQueue->count++;
}

void Pop(Queue *pQueue)
{
    if(pQueue == NULL)
        return;
    if(pQueue->count==0)
        return;
    List *pDel = pQueue->front;
    pQueue->front = pQueue->front->next;

    printf("%d\n", pDel->value);
    free(pDel);
    pDel = NULL;
    pQueue->count--;

    if(pQueue->count==0)
        pQueue->back = NULL;
}

int main(){
    Queue *pQueue=NULL;
    Init(&pQueue);
    printf("%d\n", pQueue->count);
    // printf("hello\n");
    Push(pQueue, 1);
    Push(pQueue, 2);
    Push(pQueue, 3);
    Pop(pQueue);
    Pop(pQueue);
    return 0;
}
