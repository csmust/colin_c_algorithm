//桶排序  整数模拟小数
#include<stdio.h>
#include<stdlib.h>

typedef struct List{
    List *next;
    int value;
} List;

void BubbleSort(List * arr){
    if (arr==NULL){
        return;
    }
    if(arr->next==NULL){
        return;
    }
    List* p = arr;
    int flag = 0;
    while (1){
        while(arr->next!=NULL){
            if(arr->next->value < arr->value){
                arr->next->value = arr->next->value ^ arr->value;
                arr->value= arr->next->value ^ arr->value;
                arr->next->value = arr->next->value ^ arr->value;
                flag = 1;
            }
            arr = arr->next;
        }
        if(flag==0){
            break;
        }
        arr = p;
        flag = 0;
    }
}
int chaiwei(int m)
{
    //得到高位数
    int cnt=1;
    while(m/10){
        cnt++;
        m /= 10;
    }
    return m;
}

void BucketSort(int arr[], int nlen){

    if(arr==NULL || nlen <=0)
        return;
    // 找最大最小值的下标
    int Maxid = 0;
    int Minid = 0;
    for (int i = 0; i < nlen;i++){
        if(arr[i]>arr[Maxid]){
            Maxid = i;
        }
        if(arr[i]<arr[Minid]){
            Minid = i;
        }
    }
    int len = chaiwei(arr[Maxid]) - chaiwei(arr[Minid])+1;

    List *buckets[len];
    //初始化
    for (int i = 0; i < len;i++){
        // List *Temp = (List *)malloc(sizeof(List));
        buckets[i] = NULL;
    }
    for (int i = 0; i < nlen; i++)
    {
        List *Temp = (List *)malloc(sizeof(List));
        Temp->value = arr[i];
        Temp->next = buckets[chaiwei(arr[i]) -chaiwei( arr[Minid])];
        buckets[chaiwei(arr[i])-chaiwei(arr[Minid])] = Temp;
        
    }
    for (int i = 0; i < len;i++){
        BubbleSort(buckets[i]);
    }
    for (int i = 0; i < len;i++){
        List *a = buckets[i];
        while (a)
        {
            printf("%d ",a->value);
            a = a->next;
        }
        
    }
    printf("\n");
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
    int arr[] = { 131, 518, 351, 471,155,227,121, 741, 617, 856 ,933,352,475,126,947,819,590,495 ,392,215};
    int nlength = sizeof(arr) / sizeof(arr[0]);
    Print(arr, nlength);
    BucketSort(arr,nlength);
    // Print(arr, nlength);
    return 0;
}