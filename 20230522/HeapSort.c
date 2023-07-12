#include<stdio.h>
#include<stdlib.h>
/*我自己尝试写的：*/

//从i开始调整大根堆，产生交换则继续向下调整被交换的节点。否则结束
void check(int i ,int arr[],int nlen){
    if(i>nlen/2-1)
        return;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp = arr[i];
    if(right<nlen){
        //存在右孩子
        if (arr[right] >= arr[left] && arr[right] > temp){
            arr[i] = arr[right];
            arr[right] = temp;
            temp = arr[i];
            i = right;
            check(i, arr, nlen);
        }
        else if(arr[left] >= arr[right] && arr[left] > temp){
            arr[i] = arr[left];
            arr[left] = temp;
            temp = arr[i];
            i = left;
            check(i, arr, nlen);
        }
    }
    else{
        //不存在右孩子
        if(arr[left] > temp){
            arr[i] = arr[left];
            arr[left] = temp;
            temp = arr[i];
            i= left;
            check(i, arr, nlen);
        }
    }
}
//初始化大根堆，需要从最后一个父亲节点开始向前调整父亲。
void initHeap(int arr[],int nlen){

    int i;
    for (i = nlen / 2 - 1; i >=0;i--){
        check(i, arr, nlen);
    }
}

void heapSort(int arr[],int nlen){
    initHeap(arr, nlen);
    for (int i = nlen - 1; i >= 1;i--){
        arr[i] = arr[0] ^ arr[i];
        arr[0] = arr[0] ^ arr[i];
        arr[i] = arr[0] ^ arr[i];
        check(0, arr, i);
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
    int arr[] = { 3, 1, 5, 7, 2, 4, 9, 6 ,3,5,7,2,4,9,9,9 };
    int nlength = sizeof(arr) / sizeof(arr[0]);
    Print(arr, nlength);
    heapSort(arr,nlength);
    Print(arr, nlength);
    return 0;
}