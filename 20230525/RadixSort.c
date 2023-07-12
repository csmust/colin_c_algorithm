#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int value;
    struct node *next;
} List;

void RadixSort(int arr[],int len){
    if(arr==NULL || len<=0)
        return;
    int i;
    // 找最大值
    int nMax = arr[0];
    for (i = 1; i < len;i++)
    {
        if(arr[i]>nMax)
        {
            nMax = arr[i];
        }
    }

    //计算最大值位数
    int nLoopTimes = 0;
    while(nMax)
    {
        nLoopTimes++;
        nMax /= 10;
    }

    //按位处理
    int nBase;
    int j;
    List **Radix = NULL;
    List *pTemp = NULL;
    int nIndex;
    List *pNode = NULL;

    for (i = 1; i <= nLoopTimes;i++)
    {
        //计算除数
        j = i;
        nBase = 1;
        while(j>1)
        {
            nBase *= 10;
            j--;
        }

        //组
        Radix = (List **)malloc(sizeof(List *) * 10);
        memset(Radix, 0, sizeof(List *) * 10);

        for (j = 0; j < len;j++){
            nIndex = arr[j] / nBase % 10;

            pTemp = (List *)malloc(sizeof(List));
            pTemp->value = arr[j];
            pTemp->next = NULL;

            //尾添加
            if(Radix[nIndex] == NULL)
            {
                Radix[nIndex] = pTemp;
            }
            else{
                pNode = Radix[nIndex];
                while(pNode->next !=NULL)
                {
                    pNode = pNode->next;
                }
                pNode->next = pTemp;
            }
        }
        //放回
        int k = 0;
        for (j = 0; j < 10; j++){
            pTemp = Radix[j];
            while(pTemp)
            {
                arr[k] = pTemp->value;
                k++;
                pTemp = pTemp->next;
            }
        }

        for (j = 0; j < 10;j++){
            pTemp = Radix[j];
            while(pTemp)
            {
                pNode = pTemp;
                pTemp = pTemp->next;
                free(pNode);
                pNode = NULL;
            }
        }
        free(Radix);
        Radix = NULL;
    }
}
void Print(int arr[],int nlength){
    if (arr==NULL||nlength<=0)
    {
        return;
    }
    int i;
    for (i = 0; i < nlength;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = { 333, 1, 53, 75, 12, 44,429, 655 ,3,5,7,2,4,9,9,9 };
    int nlength = sizeof(arr) / sizeof(arr[0]);
    Print(arr, nlength);
    RadixSort(arr, nlength);
    Print(arr, nlength);
    return 0;
}