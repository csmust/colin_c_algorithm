//链表实现尾部添加
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int nvalue;
    struct Node* pnext;
} List;

List *CreateList()
{
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

        //尾添加创建链表
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

int main()
{
    List *pHead = CreateList();
    Print(pHead);
    return 0;
}

