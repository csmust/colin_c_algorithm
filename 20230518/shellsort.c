//希尔排序
#include<stdio.h>
void ShellSort(int arr[],int nlength)
{
    if (arr==NULL||nlength<=0)
    {
        return;
    }
    


    int gap=nlength/2;
    while(gap>0){
        int i;
        int j;
        int temp;
        // 无序元素插入到有序中去
        for (i = gap; i < nlength;i++)
        {
            j=i-gap;
            temp=arr[i];
            //倒序遍历有序部分
            while(arr[j]>temp &&j>=0){
                //移动，不是交换
                arr[j+gap]=arr[j];
                j-=gap;
            }
            //将无序元素插入
            arr[j+gap]=temp;
        }
        gap /= 2;
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
    int arr[] = { 3, 1, 5, 7, 2, 4, 9, 6 ,10 ,15, 13, 12, 11, 8, 14};
    int nlength = sizeof(arr) / sizeof(arr[0]);
    Print(arr, nlength);
    ShellSort(arr, nlength);
    Print(arr, nlength);
    return 0;
}