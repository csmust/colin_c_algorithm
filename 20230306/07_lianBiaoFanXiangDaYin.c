
#include<stdio.h>
#include<stdlib.h>    //malloc

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

void ReversePrint(List *pHead)
{   
    //递归实现反向打印链表
    if(pHead!=NULL){
        // if(pHead->pnext!=NULL)
        ReversePrint(pHead->pnext);
        printf("%d ",pHead->nvalue);
    }
}

List* ReversList(List *pHead)
{   
    //头插法 三指针 实现翻转链表  必须通过返回新链表，
    if(pHead==NULL||pHead->pnext == NULL)
        return pHead;
    
    List *ptmp1 = pHead;  //头插节点
    List *ptmp2 = pHead->pnext;  //头插的节点的下一个节点 , 被断开的旧链表表头
    pHead = NULL;
    while(ptmp1!=NULL)
    {
        ptmp1->pnext = pHead;
        pHead = ptmp1;
        ptmp1 = ptmp2;
        if(ptmp2)
            ptmp2 = ptmp2->pnext;
        // Print(pHead);
        // Print(ptmp2);
    }
    return pHead;
}
 
int main()
{
    List *pHead = CreateList();
    Print(pHead);
    ReversePrint(pHead);
    printf("\n");
    List *newpHead = ReversList(pHead);
    Print(newpHead);
    return 0;
}