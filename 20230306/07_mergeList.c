//两个有序链表，合并成有序的链表
//尾插法

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int nvalue;
    struct Node* pnext;
} List;

List *CreateList()
{   
    //链表创建，尾部添加法
    int len;
    printf("请输入链表长度：\n");
    scanf("%d", &len);

    List *pHead = NULL;
    List *pTail = NULL;
    List *pTemp = NULL;

    int num;
    while(len !=0)
    {
        printf("请输入链表数值:\n");
        scanf("%d", &num);

        pTemp = (List *)malloc(sizeof(List));
        pTemp->nvalue = num;
        pTemp->pnext = NULL;

        //尾添加
        if(pHead == NULL)
        {
            pHead = pTemp;
        }
        else
        {
            pTail->pnext = pTemp;
        }

        pTail = pTemp;
        len--;
    }
    return pHead;
}

void Print(List *pHead)
{
    while(pHead)
    {
        printf("%d ", pHead->nvalue);
        pHead = pHead->pnext;
    }
    printf("\n");
}

List * mergeList(List *A ,List *B)
{
    // if (!A&&!B)
    // {
    //     return NULL;
    // }
    if(!A)
        return B;
    else if(!B)
        return A;
    List *pTail = NULL;
    List *pHead = NULL;
    /*确定新表表头 */
    if(A->nvalue <= B->nvalue){
        pHead = A;
        pTail = A;
        A = A->pnext;
    }
    else{
        pHead = B;
        pTail = B;
        B = B->pnext;
    }
    /*找下一个尾插元素*/
    while(A&&B){
        //都非空
        if(A->nvalue <= B->nvalue){
            
            pTail->pnext = A;
            pTail = A;
            A = A->pnext;
        }
        else{
            pTail->pnext = B;
            pTail = B;
            B = B->pnext;
        }
    }
    //收尾工作
    if(A){
        pTail->pnext = A;
    }
    else 
        pTail->pnext = B;
    return pHead;
}



 
int main()
{
    List *pHead1 = CreateList();
    Print(pHead1);
    List *pHead2 = CreateList();
    Print(pHead2);
    List *newlist=mergeList(pHead1, pHead2);
    Print(newlist);

    return 0;
}