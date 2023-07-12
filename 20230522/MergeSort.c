#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int low,int high){

    int begin1 = low;
    int end1 = (high + low) / 2;
    int begin2 = end1 + 1;
    int end2 = high;
    int length = high - low + 1;

    int *ptemp = NULL;
    ptemp = (int *)malloc(sizeof(int) * length);

    int i = 0;
    while(begin1 <= end1 && begin2 <=end2){
        if(arr[begin2] < arr[begin1])
        {
            ptemp[i++] = arr[begin2++];
        }
        else{
            ptemp[i++] = arr[begin1++];
        }
    }
    //将有剩余的数组放回
    while(begin1<=end1){
        ptemp[i++] = arr[begin1++];
    }
    while(begin2<=end2){
        ptemp[i++] = arr[begin2++];
    }

    //放回
    for (i = 0; i < high - low + 1;i++){
        arr[low + i] = ptemp[i];
    }

        free(ptemp);
    ptemp = NULL;
}

void mergeSort(int arr[],int low,int high){
    if(arr==NULL || low>=high){
        return ;
    }
    int mid = (high + low) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    
    //合并
    merge(arr, low, high);
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
    int arr[] = {1, 4, 8, 19, 24, 2, 5, 7, 16};
    int nlength = sizeof(arr) / sizeof(arr[0]);
    Print(arr, nlength);
    mergeSort(arr, 0, nlength - 1);
    Print(arr, nlength);
    return 0;
}
