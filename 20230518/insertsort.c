#include<stdio.h>
void InsertSort(int arr[],int nlength)
{
    if (arr==NULL||nlength<=0)
    {
        return;
    }

    int i;
    int j;
    int temp;
    // 无序元素插入到有序中去
    for (i = 1; i < nlength;i++)
    {
        j=i-1;
        temp=arr[i];
        //倒序遍历有序部分
        while(arr[j]>temp &&j>=0){
            //移动，不是交换
            arr[j+1]=arr[j];
            j--;
        }
        //将无序元素插入
        arr[j+1]=temp;
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
    int arr[] = { 3, 1, 5, 7, 2, 4, 9, 6 };
    int nlength = sizeof(arr) / sizeof(arr[0]);
    Print(arr, nlength);
    InsertSort(arr, nlength);
    Print(arr, nlength);
    return 0;
}