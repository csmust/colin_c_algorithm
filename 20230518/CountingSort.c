#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void CountingSort(int arr[],int nlength)
{
    if (arr==NULL||nlength<=0)
    {
        return;
    }
    int i;
    int j;
    int max = arr[0];
    int min = arr[0];
    for (i = 1; i < nlength; i++){
        if (arr[i]>max){
            max = arr[i];
        }
        if (arr[i]<min){
            min = arr[i];
        }
    }

    //计数数组
    int *Count = NULL;
    Count = (int *)malloc(sizeof(int)*(max - min + 1));
    memset(Count, 0, sizeof(int)*(max - min + 1));

    //计数
    for (i = 0;i<nlength;i++){
        Count[arr[i] - min]++;
    }
    //放回
    j = 0;
    for (i = 0;i<max - min + 1;i++){
        while(Count[i]--){
            arr[j++] = i + min;
            
        }
    }
    free(Count);
    Count = NULL;
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
    int arr[] = { 3, 1, 5, 7, 2, 4, 9, 6 ,3,5,7,2,4,9,9,9 };
    int nlength = sizeof(arr) / sizeof(arr[0]);
    Print(arr, nlength);
    CountingSort(arr, nlength);
    Print(arr, nlength);
    return 0;
}